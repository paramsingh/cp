#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

struct edge {
    int u, v, cap, flow, cost, dup;
    edge(int a, int b, int c, int e) {
        u = a, v = b;
        cap = c; flow = 0;
        cost = dup = e;
    }
    inline int rcap() {
        return cap - flow;
    }
};

class cmp {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

struct mcmf {
    vector<edge> edges;
    vector<int>* graph;
    int *dist, *pedge, *lim;
    int n;
    int src, sink;

    void init(int a, int ss, int sn) {
        n = a, src = ss, sink = sn;
        graph = (vector<int>*) calloc(600, sizeof(vector<int>));
        dist = (int*) calloc(600, sizeof(int));
        pedge = (int*) calloc(600, sizeof(int));
        lim = (int*) calloc(600, sizeof(int));
    }

    void clear() {
        free(graph);
        free(dist);
        free(pedge);
        free(lim);
        edges.clear();
    }

    void add_edge(int u, int v, int cap, int cost) {
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, cap, cost));
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, 0, -cost));
    }

    void bellmanford() {
        for (int i = 0; i < 600; i++)
            dist[i] = INF;
        dist[src] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (edges[j].rcap() <= 0)
                    continue;
                int u = edges[j].u, v = edges[j].v, w = edges[j].cost;
                if (dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
    }

    void reduce() {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].cap != 0 && edges[i].rcap() >= 0) {
                edges[i].cost += dist[edges[i].u] - dist[edges[i].v];
                edges[i^1].cost = 0;
            }
        }
    }

    int dijkstra() {
        for (int i = 0; i < 600; i++) {
            lim[i] = -1;
            dist[i] = INF;
            pedge[i] = -1;
        }
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push(make_pair(src, 0));
        dist[src] = 0;
        lim[src] = INF;
        while (!pq.empty()) {
            int u = pq.top().first, du = pq.top().second;
            pq.pop();
            if (dist[u] < du) continue;
            for (int i = 0; i < graph[u].size(); i++) {
                int id = graph[u][i];
                if (edges[id].rcap() <= 0) continue;
                int v = edges[id].v, w = edges[id].cost;
                if (dist[v] > dist[u] + w) {
                    lim[v] = min(lim[u], edges[id].rcap());
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(v, dist[v]));
                    pedge[v] = id;
                }
            }
        }
        return dist[sink] != INF;
    }

    pii flow() {
        bellmanford();
        reduce();
        int flow = 0, cost = 0;
        while (dijkstra()) {
            reduce();
            int v = sink;
            int aug = lim[sink];
            while (v != src) {
                int id = pedge[v];
                edges[id].flow   += aug;
                edges[id^1].flow -= aug;
                cost += edges[id].dup;
                v = edges[id].u;
            }
            flow += aug;
        }
        return make_pair(flow, cost);
    }

};


int main(void) {
    int t;
    scanf("%d", &t);
    mcmf m;
    while (t--) {
        int n, e;
        scanf("%d %d", &n, &e);
        m.init(2*n+2, 0, 550);
        for (int i = 1; i <= n; i++) {
            m.add_edge(0, 2*i, 1, 0);
            m.add_edge(2*i+1, 550, 1, 0);
        }
        for (int i = 0; i < e; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            m.add_edge(2*u, 2*v + 1, 1, w);
        }
        pii ans = m.flow();
        printf("%d\n", ans.second);
        m.clear();
    }
    return 0;
}
