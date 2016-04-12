#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct edge {
    int u, v, cap, flow;
    edge(int a, int b, int c) {
        u = a, v = b, cap = c;
        flow = 0;
    }
    inline int rcap() {
        return cap - flow;
    }
};


vector<int> graph[2000];
vector<edge> edges;
int src, sink;
int level[2000];
int ei[2000];

int bfs() {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[src] = 1;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            int v = edges[id].v;
            if (level[v] != -1 || edges[id].rcap() <= 0)
                continue;
            q.push(v);
            level[v] = level[u] + 1;
        }
    }
    return level[sink] != -1;
}

int dfs(int u, int pushed) {
    if (u == sink) return pushed;
    if (pushed <= 0) return 0;
    for (; ei[u] < graph[u].size(); ei[u]++) {
        int i = ei[u], id = graph[u][i];
        int v = edges[id].v;
        if (level[v] == level[u] + 1 && edges[id].rcap() > 0) {
            int f = dfs(v, min(pushed, edges[id].rcap()));
            if (f > 0) {
                edges[id].flow += f;
                edges[id^1].flow -= f;
                return f;
            }
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memset(ei, 0, sizeof(ei));
        while (int pushed = dfs(src, 1e8))
            flow += pushed;
    }
    return flow;
}

inline void add_edge(int u, int v, int c) {
    graph[u].push_back(edges.size());
    edges.push_back(edge(u, v, c));
    graph[v].push_back(edges.size());
    edges.push_back(edge(v, u, 0));
}

class cmp {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

int dijkstra() {
    memset(level, 0, sizeof(level));
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push(make_pair(src, 1e8));
    level[src] = 1e8;
    while (!pq.empty()) {
        int u = pq.top().first, w = pq.top().second;
        pq.pop();
        if (level[u] < w) continue;
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            int v = edges[id].v, nw = edges[id].cap;
            if (edges[id].rcap() <= 0) continue;
            if (level[v] < min(w, nw)) {
                level[v] = min(w, nw);
                pq.push(make_pair(v, level[v]));
            }
        }
    }
    return level[sink];
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int d, n, e;
        scanf("%d %d %d %d %d", &d, &n, &e, &src, &sink);
        for (int i = 0; i < e; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
        }
        int maxc = dijkstra();
        int flow = dinic();
        //printf("max = %d, flow = %d\n", maxc, flow);
        printf("%d %.3f\n", d, (float) flow / maxc);
        edges.clear();
        for (int i = 0; i <= n; i++)
            graph[i].clear();
    }
    return 0;
}
