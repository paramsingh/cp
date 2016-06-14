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
vector<int> graph[70010];
int level[70010];
int ei[70010];
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
    //printf("at %d\n", u);
    if (u == t) return pushed;
    for (; ei[u] < graph[u].size(); ei[u]++) {
        int id = graph[u][ei[u]];
        int v = edges[id].v;
        if (level[v] == level[u] + 1 && edges[id].rcap() > 0) {
            int p = dfs(v, min(pushed, edges[id].rcap()));
            if (p > 0) {
                edges[id].flow   += p;
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

void add_edge(int u, int v, int cap) {
    graph[u].push_back(edges.size());
    edges.push_back(edge(u, v, cap));
    graph[v].push_back(edges.size());
    edges.push_back(edge(v, u, 0));
}

void clear() {
    for (int i = 0; i < 70010; i++)
        graph[i].clear();
    edges.clear();
}

int main(void) {
    int term;
    scanf("%d", &term);
    while (term--) {
        int n, m;
        scanf("%d %d", &n, &m);
        s = 0, t = n + m + 2;
        for (int i = 1; i <= n; i++) {
            int p;
            scanf("%d", &p);
            add_edge(s, i, p);
        }
        int f = 0;
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            f += w;
            add_edge(n+i, t, w);
            add_edge(u, n+i, 1e9);
            add_edge(v, n+i, 1e9);
        }
        int a = flow();
        f -= a;
        printf("%d\n", f);
        clear();
    }
    return 0;
}

