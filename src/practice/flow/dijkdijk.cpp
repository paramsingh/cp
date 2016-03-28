/** Successive Shortest Path algorithm for finding minimum cost mximum flow
  * Algorithm:
  *     Transform network G by adding source and sink
  *     Set initial flow x = 0
  *     Establish potentials pi // use bellman ford if negative edges
  *     for each edge (i, j) in Ex
  *         set cost(i, j) = cost(i, j) + pi(i) - pi(j)
  *         set cost(rev(i, j)) = 0 // not cost(j, i)
  *     while residual graph contains a path from s to t:
  *         run dijkstra to find shortest path from s to t hence
  *         modifying pi
  *         for each edge in residual graph
  *             set cost(i, j) = cost(i, j) + pi(i) - pi(j)
  *             set cost(rev(i, j)) = 0
  *         augment flow x along P
  *         update Gx
  *
  * source: topcoder
  **/

#include <bits/stdc++.h>
#define INF 100000000
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
class edge {
    public:
        int u, v, cap, flow, cost, id, dup;
        edge(int a, int b, int c, int d, int e, int f) {
            u = a, v = b, cap = c, flow = d, cost = e, id = f;
            dup = cost;
        }
        int rcap() {
            return cap - flow;
        }
};

class cmp {
    public:
        bool operator() (const pii a, const pii b) {
            return a.second > b.second;
        }
};
class mincostmaxflow {
public:
    vector<edge> edges;
    vector<int>* graph;
    int* dist;
    int* pedge;
    int* lim;
    int src, sink;
    int n;

    mincostmaxflow(int nodes, int ss, int snk) {
        graph = (vector<int>*) calloc(200, sizeof(vector<int>));
        dist = (int*) calloc(200, sizeof(int));
        lim = (int*) calloc(200, sizeof(int));
        pedge = (int*) calloc(200, sizeof(int));
        src = ss;
        sink = snk;
        n = nodes;
    }

    void add_edge(int u, int v, int cap, int cost) {
        // for edge u -> v
        graph[u].push_back(edges.size());
        edges.push_back(edge(u, v, cap, 0, cost, edges.size()));
        graph[v].push_back(edges.size());
        edges.push_back(edge(v, u, 0, 0, -cost, edges.size()));
    }

    // fast dijkstra algorithm for finding the shortest path in the residual
    // network after its costs have been reduced
    int dijkstra(int src, int sink) {
        for (int i = 0; i < 200; i++) {
            pedge[i] = -1;
            dist[i] = INF;
            lim[i] = INF;
        }
        dist[src] = 0;
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push(mp(src, 0));
        while (!pq.empty()) {
            int u = pq.top().first, w = pq.top().second;
            pq.pop();
            if (dist[u] < w) continue;
            for (int i = 0; i < graph[u].size(); i++) {
                int id = graph[u][i];
                edge& e = edges[id];
                int v = e.v;
                if (e.rcap() <= 0) continue;
                if (dist[v] > dist[u] + e.cost) {
                    dist[v] = dist[u] + e.cost;
                    pedge[v] = id;
                    lim[v] = min(lim[u], e.rcap());
                    pq.push(mp(v, dist[v]));
                }
            }
        }
        return pedge[sink] != -1;
    }

    // reduce the costs of the network so that they all remain positive
    void reduce() {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].cap != 0 && edges[i].rcap() >= 0) {
                edges[i].cost += dist[edges[i].u] - dist[edges[i].v];
                edges[i^1].cost = 0;
            }
        }
    }

    // bellman ford algorithm for finding the shortest paths in a graph
    // with negative edges
    void bellmanford() {
        for (int i = 0; i < 200; i++)
            dist[i] = INF;
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (edges[j].rcap() <= 0) continue;
                int u = edges[j].u, v = edges[j].v, w = edges[j].cost;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // returns the minimum cost max flow using the successive path algorithm
    pii mcmf() {
        int cost = 0;
        int flow = 0;
        // use bellman ford to find the shortest path and then reduce the costs
        // accordingly
        bellmanford();
        reduce();
        // while there exists a shortest path in the residual graph
        while (dijkstra(src, sink)) {
            int cap = lim[sink];
            int v = sink;
            // reduce again
            reduce();
            // augment the flow and cost and create the residual graph
            while (v != src) {
                int id = pedge[v];
                edges[id].flow += cap;
                edges[id^1].flow -= cap;
                cost += cap * edges[id].dup;
                v = edges[id].u;
            }
            flow += cap;
        }
        return mp(flow, cost);
    }
};

int main(void) {
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        int m;
        scanf("%d", &m);
        mincostmaxflow mf(n+2, 0, n+1);
        mf.add_edge(0, 1, 2, 0);
        mf.add_edge(n, n+1, 2, 0);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            mf.add_edge(u, v, 1, w);
            mf.add_edge(v, u, 1, w);
        }
        pii ans = mf.mcmf();
        if (ans.first != 2)
            printf("Back to jail\n");
        else
            printf("%d\n", ans.second);
    }
    return 0;
}
