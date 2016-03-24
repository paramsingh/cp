// Standard flow problem
#include <bits/stdc++.h>
using namespace std;

class edge {
    public: int u, v, cap, flow, id;
    edge(int a, int b, int c, int d, int e) {
        u = a;
        v = b;
        cap = c;
        flow = d;
        id = e;
    }
    int rcap() {
        return cap - flow;
    }
};

vector<edge> edges;
vector<int> graph[500];
int level[300];
int ei[300];
int src, sink;

int bfs() {
    queue<int> q;
    memset(level, -1, sizeof(level));
    q.push(src);
    level[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            edge& e = edges[id];
            int v = e.v;
            if (level[v] != -1 || e.rcap() <= 0)
                continue;
            else {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] != -1;
}

int dfs(int u, int pushed) {
    if (pushed == 0)
        return 0;
    if (u == sink)
        return pushed;
    for (;ei[u] < graph[u].size(); ei[u]++) {
        int id = graph[u][ei[u]];
        edge& e = edges[id];
        int v = e.v;
        if (e.rcap() <= 0) continue;
        if (level[v] == level[u] + 1) {
            int flow = dfs(v, min(pushed, e.rcap()));
            if (flow > 0) {
                edges[id].flow += flow;
                edges[id^1].flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}

int dinics() {
    int sent = 0;
    while (bfs()) {
        memset(ei, 0, sizeof(ei));
        while (int pushed = dfs(src, 1e9+1))
            sent += pushed;
    }
    return sent;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        src = 1;
        sink = n;
        for (int i = 1; i < n; i++) {
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                int v, cap;
                scanf("%d", &v);
                if (i == src || v == sink)
                    cap = 1;
                else
                    cap = 1e8;
                graph[i].push_back(edges.size());
                edges.push_back(edge(i, v, cap, 0, edges.size()));
                graph[v].push_back(edges.size());
                edges.push_back(edge(v, i, 0, 0, edges.size()));
            }
        }
        printf("%d\n", dinics());
        for (int i = 0; i < 500; i++)
            graph[i].clear();
    }
    return 0;
}
