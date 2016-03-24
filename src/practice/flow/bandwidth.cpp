#include <bits/stdc++.h>
using namespace std;

class edge {
    public: int u, v, cap, flow, id;
            edge(int a, int b, int c, int d, int e) {
                u = a;
                v = b;
                cap = c;
                flow = d;
                id = e;
            }
            inline int rcap() {
                return cap - flow;
            }
};

vector<edge> edges;
vector<int> graph[200];
int lim[200];
int parent[200];
int pedge[200];
int n;

int bfs(int src, int sink) {
    memset(lim, 0, sizeof(lim));
    memset(parent, -1, sizeof(parent));
    memset(pedge, -1, sizeof(pedge));
    queue<int> q;
    lim[src] = 1e9;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            edge& e = edges[ graph[u][i] ];
            int v = e.v;
            if (lim[v] != 0 || e.rcap() <= 0)
                continue;
            else {
                lim[v] = min(lim[u], e.rcap());
                parent[v] = u;
                pedge[v] = e.id;
                q.push(v);
            }
        }
    }
    if (lim[sink] == 0)
        return 0;
    else {
        // augment
        int pushed = lim[sink];
        int v = sink;
        while (v != src) {
            int i = pedge[v];
            edges[i].flow += pushed;
            edges[i^1].flow -= pushed;
            v = parent[v];
        }
        return pushed;
    }
}


int ford(int src, int sink) {
    int flow = 0;
    while (int pushed = bfs(src, sink))
        flow += pushed;
    return flow;
}

int main(void) {
    int cnt = 0;
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        int src, sink, e;
        scanf("%d %d %d", &src, &sink, &e);
        for (int i = 0; i < e; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, v, w, 0, edges.size()));
            graph[v].push_back(edges.size());
            edges.push_back(edge(v, u, 0, 0, edges.size()));

            graph[v].push_back(edges.size());
            edges.push_back(edge(v, u, w, 0, edges.size()));
            graph[u].push_back(edges.size());
            edges.push_back(edge(u, v, 0, 0, edges.size()));
        }
        printf("Network %d\n", ++cnt);
        printf("The bandwidth is %d.\n", ford(src, sink));
        printf("\n");
        edges.clear();
        for (int i = 0; i < 200; i++)
            graph[i].clear();
    }
    return 0;
}
