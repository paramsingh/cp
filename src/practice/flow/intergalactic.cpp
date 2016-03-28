#include <bits/stdc++.h>
using namespace std;
class edge {
    public:
        int u, v, cap, flow;
        edge(int a, int b, int c, int f) {
            u = a, v = b, cap = c, flow = f;
        }
        int rcap() { return cap - flow; }
};
vector<int> graph[100100];
vector<edge> edges;
int src, sink;
int lim[100100];
int pedge[100100];

int bfs() {
    memset(lim, -1, sizeof(lim));
    memset(pedge, -1, sizeof(pedge));
    queue<int> q;
    q.push(src);
    lim[src] = 1e9;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            edge& e = edges[id];
            int v = e.v;
            if (lim[v] != -1 || e.rcap() <= 0)
                continue;
            else {
                lim[v] = min(lim[u], e.rcap());
                pedge[v] = id;
                q.push(v);
            }
        }
    }
    if (lim[sink] == -1)
        return 0;
    else {
        int cap = lim[sink];
        int v = sink;
        while (v != src) {
            int id = pedge[v];
            edges[id].flow += cap;
            edges[id^1].flow -= cap;
            v = edges[id].u;
        }
        return cap;
    }
}

int flow() {
    int f = 0;
    while (int pushed = bfs()) {
        f += pushed;
    }
    return f;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        src = 0, sink = 100000;
        for (int i = 1; i <= 40000; i++) {
            if (i == 2)
                continue;
            int u = 2*i;
            int v = u ^ 1;
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, v, 1, 0));
            graph[v].push_back(edges.size());
            edges.push_back(edge(v, u, 0, 0));
        }
        // from naboo to sink
        graph[3].push_back(edges.size());
        edges.push_back(edge(3, sink, 1, 0));
        graph[sink].push_back(edges.size());
        edges.push_back(edge(sink, 3, 0, 0));
        // from coruscant to sink
        graph[7].push_back(edges.size());
        edges.push_back(edge(7, sink, 1, 0));
        graph[sink].push_back(edges.size());
        edges.push_back(edge(sink, 7, 0, 0));
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int u1 = u << 1, u2 = u1 ^ 1;
            int v1 = v << 1, v2 = v1 ^ 1;
            if (u == 2) {
                graph[src].push_back(edges.size());
                edges.push_back(edge(src, v1, 1, 0));
                graph[v1].push_back(edges.size());
                edges.push_back(edge(v1, src, 0, 0));
                graph[v2].push_back(edges.size());
                edges.push_back(edge(v2, src, 1, 0));
                graph[src].push_back(edges.size());
                edges.push_back(edge(src, v2, 0, 0));
            }
            else if (v == 2) {
                graph[src].push_back(edges.size());
                edges.push_back(edge(src, u1, 1, 0));
                graph[u1].push_back(edges.size());
                edges.push_back(edge(u1, src, 0, 0));
                graph[u2].push_back(edges.size());
                edges.push_back(edge(u2, src, 1, 0));
                graph[src].push_back(edges.size());
                edges.push_back(edge(src, u2, 0, 0));
            }
            else {
                graph[u2].push_back(edges.size());
                edges.push_back(edge(u2, v1, 1, 0));
                graph[v1].push_back(edges.size());
                edges.push_back(edge(v1, u2, 0, 0));
                graph[v2].push_back(edges.size());
                edges.push_back(edge(v2, u1, 1, 0));
                graph[u1].push_back(edges.size());
                edges.push_back(edge(u1, v2, 0, 0));
            }
        }
        if (flow() >= 2)
            printf("YES\n");
        else
            printf("NO\n");
        for (int i = 0; i < 100100; i++)
            graph[i].clear();
        edges.clear();
    }
    return 0;
}

