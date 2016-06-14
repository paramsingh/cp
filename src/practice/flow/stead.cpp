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

vector<edge> edges;
vector<int> graph[1050];
int ei[1050];
int level[1050];
int s, t;

int bfs() {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
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

inline void add_edge(int u, int v, int cap) {
    graph[u].push_back(edges.size());
    edges.push_back(edge(u, v, cap));
    graph[v].push_back(edges.size());
    edges.push_back(edge(v, u, cap));
}

void clear(int a, int b) {
    s = a, t = b;
    for (int i = 0; i <= t; i++)
        graph[i].clear();
    edges.clear();
}

int ranks[1001][25];
int allow[25];
int n, m;

int check(int l, int r) {
    clear(0, n+m+1);
    for (int i = 0; i < n; i++)
        add_edge(s, i + 1, 1);
    for (int j = 0; j < m; j++)
        add_edge(j+n+1, t, allow[j]);
    for (int i = 0; i < n; i++) {
        for (int j = l; j <= r; j++) {
            int barn = ranks[i][j];
            add_edge(i + 1, barn + n, 1);
        }
    }

    int f = flow();
    return f >= n;
}

int main(void) {
    scanf("%d %d", &n, &m);
    int mn = m + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            ranks[i][j] = x;
        }
    }
    for (int i = 0; i < m; i++)
        scanf("%d", allow+i);
    for (int base = 0; base < m; base++) {
        int lo = base, hi = m - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(base, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (check(base, lo))
            mn = min(mn, lo - base + 1);
    }
    printf("%d\n", mn);
    return 0;
}

