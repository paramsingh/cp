// double each vertex with an edge of capacity equal to the vertex's capacity
// between the two
#include <bits/stdc++.h>
#define INF 1e9
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
int cap[200];

class edge {
public:
    int u, v, cap, flow;
    edge(int a, int b, int c) {
        u = a, v = b, cap = c, flow = 0;
    }
    int rcap() { return cap - flow; }
};

vector<edge> edges;
vector<int> graph[1000];
int lim[1000];
int pedge[1000];
int src = 0, sink;

void add_edge(int u, int v, int cap) {
    graph[u].push_back(edges.size());
    edges.push_back(edge(u, v, cap));
    graph[v].push_back(edges.size());
    edges.push_back(edge(v, u, 0));
}

int bfs() {
    for (int i = 0; i < 1000; i++) {
        lim[i] = INF;
        pedge[i] = -1;
    }
    lim[src] = 1e8;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int id = graph[u][i];
            if (lim[edges[id].v] != INF || edges[id].rcap() <= 0)
                continue;
            else {
                lim[edges[id].v] = min(lim[u], edges[id].rcap());
                pedge[edges[id].v] = id;
                q.push(edges[id].v);
            }
        }
    }
    if (lim[sink] == INF)
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

int ford() {
    int flow = 0;
    while (int pushed = bfs())
        flow += pushed;
    return flow;
}

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", cap+i);
            add_edge(2*i, 2*i+1, cap[i]);
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            add_edge(2*u+1, 2*v, c);
        }
        src = 0, sink = 2*n+2;
        int b, d;
        scanf("%d %d", &b, &d);
        for (int i = 0; i < b; i++) {
            int u;
            scanf("%d", &u);
            add_edge(src, 2*u, 1e7);
        }
        for (int i = 0; i < d; i++) {
            int u;
            scanf("%d", &u);
            add_edge(2*u+1, sink, 1e7);
        }
        printf("%d\n", ford());
        for (int i = 0; i < 1000; i++)
            graph[i].clear();
        edges.clear();
    }
    return 0;
}
