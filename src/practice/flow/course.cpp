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

struct maxflow {
    vector<int> graph[200];
    vector<edge> edges;
    int lim[200];
    int level[200];
    int ei[200];
    int s, t;

    void init(int a, int b) {
        s = a, t = b;
        for (int i = 0; i < 200; i++)
            graph[i].clear();
        edges.clear();
    }

    void add(int u, int v, int c) {
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, c));
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, 0));
    }

    int bfs() {
        memset(level, 0, sizeof(level));
        lim[s] = 1e8;
        queue<int> q;
        q.push(s);
        level[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                int id = graph[u][i];
                int v = edges[id].v;
                if (level[v] == 0 && edges[id].rcap() > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[t];
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

    int check(int val) {
        for (int i = 0; i < edges.size(); i++)
            edges[i].flow = 0;
        for (int i = 0; i < graph[s].size(); i++) {
            int id = graph[s][i];
            edges[id].cap = val;
        }
        int f = flow();
        int flag = 0;
        for (int i = 0; i < graph[s].size(); i++) {
            int id = graph[s][i];
            if (edges[id].rcap() != 0)
                return 1;
        }
        return 0;
    }
};

int main(void) {
    maxflow mf;
    while (true) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        if (n + m + k == 0) return 0;

        int s = 0, t = n + m + 1;
        mf.init(s, t);
        for (int i = 1; i <= n; i++) {
            int c;
            scanf("%d", &c);
            while (c--) {
                int u;
                scanf("%d", &u);
                mf.add(i, u+n, 1);
            }
            mf.add(s, i, 1);
        }

        for (int j = 1; j <= m; j++)
            mf.add(j+n, t, k);

        int lo = 0, hi = m;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (mf.check(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        if (!mf.check(lo))
            printf("%d\n", m);
        else
            printf("%d\n", lo-1);
    }
    return 0;
}
