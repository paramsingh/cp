#include <bits/stdc++.h>
using namespace std;

int freq[30];
int other[30][30];

struct edge {
    int u, v, cap, flow;
    edge(int a, int b, int c) {
        u = a, v = b, cap = c, flow = 0;
    }
    int rcap() {
        return cap - flow;
    }
};

struct dinic {
    vector<edge> edges;
    vector<int> graph[100];
    int level[100];
    int ei[100];
    int s, t;

    void add_edge(int u, int v, int cap) {
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, cap));
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, 0));
    }

    void clear(int a, int b) {
        s = a, t = b;
        for (int i = 0; i < 100; i++)
            graph[i].clear();
        edges.clear();
    }

    int bfs() {
        memset(level, 0, sizeof(level));
        level[s] = 1;
        queue<int> q;
        q.push(s);
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
};

dinic d;

int main(void) {
    int term, cnt = 1;
    scanf("%d", &term);
    while (term--) {
        int n, m;
        scanf("%d %d", &n, &m);
        d.clear(0, m+1);
        int k, c;
        scanf("%d", &k);
        int s = 0, t = m + 1;
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < k; i++) {
            scanf("%d", &c);
            freq[c]++;
        }
        for (int i = 1; i <= m; i++) {
            d.add_edge(s, i, freq[i]);
            d.add_edge(i, t, 1);
        }
        memset(other, 0, sizeof(other));
        for (int i = 1; i < n; i++) {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &c);
                other[i][c]++;
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 1; k <= m; k++) {
                    if (other[j][i] == 0 && other[j][k] > 1) {
                        d.add_edge(i, k, 1);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", cnt++, d.flow());
    }
    return 0;
}
