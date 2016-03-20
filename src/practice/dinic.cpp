#include <bits/stdc++.h>
using namespace std;

class edge {
    public: int from, to, cap, flow, id;
            edge(int a, int b, int c, int d, int e) {
                from = a;
                to = b;
                cap = c;
                flow = d;
                id = e;
            }
            int rcap() { return cap - flow; }
};

vector<edge> edges;
vector<int> graph[5100];
int level[5100];
int lim[5100];
int n, m;
int s, t;

int bfs() {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            edge& e = edges[ graph[u][i] ];
            int v = e.to;
            if (level[v] != -1 || e.rcap() <= 0)
                continue;
            else {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return (level[t] != -1);
}
int ei[5100];

int dfs(int u, int flow) {
    if (flow == 0) return 0;
    if (u == t) return flow;
    for (; ei[u] < graph[u].size(); ei[u]++) {
        int i = ei[u];
        int id = graph[u][i];
        edge& e = edges[ graph[u][i] ];
        int v = e.to;
        if (level[v] != level[u] + 1)
            continue;
        int pushed = dfs(v, min(flow, e.rcap()));
        if (pushed != 0) {
            edges[id].flow += pushed;
            edges[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}


long long int dinic() {
    long long int flow = 0;
    while (bfs()) {
       // printf("new iteration\n");
        memset(ei, 0, sizeof(ei));
        while (int pushed = dfs(s, 1e9 + 1)) {
           // printf("pushed %d\n", pushed);
            flow += pushed;
        }
    }
    return flow;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        // Adding edge u -> v and its residual edge
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, c, 0, edges.size()));
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, 0, 0, edges.size()));
        // Adding edge v -> u and its residual edge
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, c, 0, edges.size()));
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, 0, 0, edges.size()));
    }
    s = 1, t = n;
    printf("%lld\n", dinic());
    return 0;
}
