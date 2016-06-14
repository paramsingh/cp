#include <bits/stdc++.h>
using namespace std;

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

vector<int> graph[105];
vector<edge> edges;
int done[105];
int level[105];
int ei[105];
int s, t;
int k;

inline void add_edge(int u, int v, int cap) {
    graph[u].push_back(edges.size());
    edges.push_back(edge(u, v, cap));
    graph[v].push_back(edges.size());
    edges.push_back(edge(v, u, 0));
}

inline int bfs() {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            int v = edges[id].v;
            if (level[v] == -1 && edges[id].rcap() > 0) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int pushed = 1e8) {
    if (u == t)
        return pushed;
    for (; ei[u] < graph[u].size(); ei[u]++) {
        int id = graph[u][ei[u]];
        int v = edges[id].v;
        if (level[v] == level[u] + 1 && edges[id].rcap() > 0) {
            int p = dfs(v, min(pushed, edges[id].rcap()));
            if (p > 0) {
                edges[id].flow += p;
                edges[id^1].flow -= p;
                return p;
            }
        }
    }
    return 0;
}

int maxflow() {
    int flow = 0;
    while (bfs()) {
        memset(ei, 0, sizeof(ei));
        while (int p = dfs(s)) {
            flow += p;
        }
    }
    return flow;
}

void clear(int a, int b) {
    s = a, t = b;
    for (int i = 0; i < 105; i++)
        graph[i].clear();
    edges.clear();
}

int n, m, a, l, g;

vector<edge> all;
vector<int> src;
vector<int> sink;
int check(int x) {
    clear(0, n+1);
    for (int i = 0; i < all.size(); i++) {
        if (all[i].cap <= x) {
            add_edge(all[i].u, all[i].v, all[i].cap);
            add_edge(all[i].v, all[i].u, all[i].cap);
        }
    }

    for (int i = 0; i < src.size(); i++)
        add_edge(0, src[i], 1e8);

    for (int i = 0; i < sink.size(); i++)
        add_edge(sink[i], n+1, 1e8);

    int f = maxflow();
    return f >= g;
}

int scanint() {
    register int x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar_unlocked();
    }
    return x;
}

int main(void) {
    int t = scanint();
    while (t--) {
        n = scanint();
        m = scanint();
        a = scanint();
        l = scanint();
        g = scanint();
        clear(0, n+1);
        all.clear();
        src.clear();
        sink.clear();
        int s = 0, t = n + 1;
        for (int i = 0; i < m; i++) {
            int u = scanint(), v = scanint(), cap = scanint();
            all.push_back(edge(u, v, cap));
        }
        int u;
        for (int i = 0; i < a; i++) {
            u = scanint();
            src.push_back(u);
        }
        for (int i = 0; i < l; i++) {
            u = scanint();
            sink.push_back(u);
        }
        int lo = 0, hi = 1e6 + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (check(lo))
            printf("%d\n", lo * 100);
        else
            printf("-1\n");
    }
    return 0;
}
