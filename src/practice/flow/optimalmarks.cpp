#include <bits/stdc++.h>
using namespace std;
int arr[700];
int m[700];

struct edge {
    int u, v, cap, flow;
    edge() {
        u = 0, v = 0, cap = 0, flow = 0;
    }
    edge(int a, int b, int c) {
        u = a, v = b, cap = c, flow = 0;
    }
    inline int rcap() {
        return cap - flow;
    }
};

struct dinic {
    int n;
    int s, t;
    int ei[700];
    int level[700];
    vector<int> graph[700];
    vector<edge> edges;

    void clear(int a, int b, int c) {
        for (int i = 0; i <= n+1; i++)
            graph[i].clear();
        edges.clear();
        n = a, s = b, t = c;
        m[s] = m[t] = 1;
    }

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
                if (level[v] != -1 || edges[id].rcap() <= 0)
                    continue;
                else {
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
        if (pushed <= 0)
            return 0;
        for (; ei[u] < graph[u].size(); ei[u]++) {
            int id = graph[u][ei[u]];
            int v = edges[id].v;
            if (level[v] != level[u] + 1 || edges[id].rcap() <= 0)
                continue;
            else {
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
            while (int pushed = dfs(s))
                f += pushed;
        }
        return f;
    }

    void cutdfs(int u, int bit) {
        level[u] = 1;
        if (m[u] == 0) {
            arr[u] |= (1 << bit);
        }
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            int v = edges[id].v;
            if (level[v] == 1 || edges[id].rcap() <= 0)
                continue;
            else {
                cutdfs(v, bit);
            }
        }
    }

    int place(int bit) {
        memset(level, 0, sizeof(level));
        cutdfs(s, bit);
    }

    inline void add_edge(int u, int v, int cap) {
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, cap));
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, 0));
    }
};

int main(void) {
    int t;
    scanf("%d", &t);
    dinic d;
    while (t--) {
        int n, e;
        scanf("%d %d", &n, &e);
        d.clear(n, 0, n+1);
        int s = 0, t = n+1;
        for (int i = 0; i < e; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            d.add_edge(u, v, 1);
            d.add_edge(v, u, 1);
        }
        int size = d.edges.size();
        memset(arr, 0, sizeof(arr));
        memset(m, 0, sizeof(m));
        m[s] = m[t] = 1;
        int k;
        scanf("%d", &k);
        while (k--) {
            int u, v;
            scanf("%d %d", &u, &v);
            m[u] = 1;
            arr[u] = v;
        }
        for (int bit = 0; bit <= 30; bit++) {
            d.edges.resize(size);
            for (int i = 0; i < size; i++)
                d.edges[i].flow = 0;
            d.graph[s].clear();
            d.graph[t].clear();
            for (int i = 1; i <= n; i++) {
                if (m[i] == 1) {
                    if ((arr[i] >> bit) & 1) {
                        d.add_edge(s, i, 1000000000);
                    }
                    else {
                        d.add_edge(i, t, 1000000000);
                    }
                }
            }
            int f = d.flow();
            d.place(bit);
        }
        for (int i = 1; i <= n; i++)
            printf("%d\n", arr[i]);
    }
    return 0;
}
