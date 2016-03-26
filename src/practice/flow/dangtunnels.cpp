// Binary search for the answer
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
class edge {
    public:
        int u, v, cap, flow, dang, id;
        edge(int a, int b, int c, int d, int e, int f) {
            u = a, v = b, cap = c, flow = d, dang = e, id = f;
        }
        int rcap() {
            return cap - flow;
        }
};
vector<edge> edges;
vector<int> graph[600];
int lim[600];
int parent[600];
int pedge[600];
int n, src, sink;
int k;

int bfs(int mxd) {
    memset(lim, 0, sizeof(lim));
    memset(parent, -1, sizeof(parent));
    memset(pedge, -1, sizeof(pedge));
    queue<int> q;
    q.push(src);
    parent[src] = src;
    lim[src] = 1e9;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            edge& e = edges[id];
            int v = e.v;
            if (parent[v] != -1 || e.rcap() <= 0 || e.dang > mxd)
                continue;
            else {
                lim[v] = min(lim[u], e.rcap());
                parent[v] = u;
                pedge[v] = id;
                q.push(v);
            }
        }
    }
    if (parent[sink] == -1)
        return 0;
    else {
        int cap = lim[sink];
        int v = sink;
        while (v != src) {
            int ei = pedge[v];
            edges[ei].flow += cap;
            edges[ei^1].flow -= cap;
            v = parent[v];
        }
        return cap;
    }
}

int flow(int mxd) {
    for (int i = 0; i < edges.size(); i++)
        edges[i].flow = 0;
    int f = 0;
    while (int pushed = bfs(mxd))
        f += pushed;
    return f >= k;
}

int main(void) {
    int cs = 1;
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        src = 0, sink = 2*(n+1);
        int t;
        // doubling each vertex into two to set vertex capacities
        for (int i = 1; i <= n; i++) {
            int u = 2*i, v = u ^ 1;
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, v, 1, 0, 0, edges.size()));
            graph[v].push_back(edges.size());
            edges.push_back(edge(v, u, 0, 0, 0, edges.size()));
        }
        scanf("%d", &t);
        for (int i = 0; i < t; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (v < u)
                swap(u, v);
            if (u != 0) // if u is not the source or the sink as they
                                      // are not doubled
                u = 2*u + 1;
            if (v == n + 1)
                v = sink;
            else
                v = 2*v;
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, v, 1, 0, w, edges.size()));
            graph[v].push_back(edges.size());
            edges.push_back(edge(v, u, 0, 0, w, edges.size()));
        }
        scanf("%d", &k);
        // binary search
        int l = 0, h = 100000;
        while (l < h) {
            int m = (l + h) / 2;
            if (flow(m))
                h = m;
            else
                l = m + 1;
        }
        printf("Case %d: ", cs++);
        if (!flow(l))
            printf("no solution\n");
        else
            printf("%d\n", l);
        edges.clear();
        for (int i = 0; i < 600; i++)
            graph[i].clear();
    }
    return 0;
}

