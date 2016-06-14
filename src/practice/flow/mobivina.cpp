#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, cap, flow;
    edge(int a, int b, int c) {
        u = a, v = b, cap = c, flow = 0;
    }
    int rcap() {
        return cap - flow;
    }
};

vector<edge> edges;
vector<int> graph[600];
int level[600];
int ei[600];
int s, t;

int bfs() {
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
    if (u == t) return pushed;
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

int flow() {
    int f = 0;
    while (bfs()) {
        memset(ei, 0, sizeof(ei));
        while (int p = dfs(s))
            f += p;
    }
    return f;
}

void add_edge(int u, int v, int c) {
    graph[u].push_back(edges.size());
    edges.push_back(edge(u, v, c));
    graph[v].push_back(edges.size());
    edges.push_back(edge(v, u, 0));
}


int main(void) {
    int n;
    scanf("%d", &n);
    s = 0, t = n+1;
    for (int i = 1; i <= n; i++) {
        int w;
        scanf("%d", &w);
        add_edge(s, i, w);
    }
    for (int i = 1; i <= n; i++) {
        int w;
        scanf("%d", &w);
        add_edge(i, t, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            scanf("%d", &w);
            add_edge(i, j, w);
        }
    }
    printf("%d\n", flow());
    return 0;
}
