#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, cap, flow;
    edge(int a, int b, int c, int d) {
        u = a, v = b, cap = c, flow = d;
    }
    inline int rcap() {
        return cap - flow;
    }
};

struct dinic {
    vector<int> graph[100100];
    vector<edge> edges;
    int level[100100];
    int ei[100100];
    int s, t;

    dinic(int a, int b) {
        s = a, t = b;
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
        for (;ei[u] < graph[u].size(); ei[u]++) {
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
            while (int pushed = dfs(s))
                f += pushed;
        }
        return f;
    }

    void add(int u, int v, int cap) {
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, cap, 0));
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, 0, 0));
    }
};

char heaven[500][500];
int rnodes[500][500];
int cnodes[500][500];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(rnodes, 0, sizeof(rnodes));
        memset(cnodes, 0, sizeof(cnodes));
        int x, y;
        scanf("%d %d", &x, &y);
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                char c[10];
                scanf("%s", c);
                heaven[i][j] = c[0];
            }
            heaven[i][y] = '\0';
        }

        int s = 0, t = 100000;
        dinic d(s, t);
        int node = 1;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y;) {
                if (heaven[i][j] == 'H') {
                    while (j < y && (heaven[i][j] == 'H' || heaven[i][j] == 'D')) {
                        rnodes[i][j] = node;
                        j++;
                    }
                    d.add(s, node, 1);
                    node++;
                }
                else if (heaven[i][j] == 'A') {
                    while (j < y && (heaven[i][j] == 'A' || heaven[i][j] == 'D'))
                        j++;
                }
                else if (heaven[i][j] == 'D')
                    j++;
            }
        }

        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; ) {
                if (heaven[i][j] == 'H') {
                    while (i < x && (heaven[i][j] == 'H' || heaven[i][j] == 'D')) {
                        cnodes[i][j] = node;
                        i++;
                    }
                    d.add(node, t, 1);
                    node++;
                }
                else if (heaven[i][j] == 'A') {
                    while (i < x && (heaven[i][j] == 'A' || heaven[i][j] == 'D'))
                        i++;
                }
                else if (heaven[i][j] == 'D')
                    i++;
            }
        }

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (heaven[i][j] == 'H') {
                    d.add(rnodes[i][j], cnodes[i][j], 1);
                }
            }
        }
        printf("%d\n", d.flow());
    }
    return 0;
}
