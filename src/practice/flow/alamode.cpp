#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
typedef pair<int, double> pid;

struct mcmf {
    int n;
    int cap[150][150], flow[150][150];
    double cost[150][150];
    int done[150];
    int lim[150];
    double pi[150];
    double dist[150];
    pair<int, int> parent[150];

    void init(int n) {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(cost, 0, sizeof(cost));
        memset(pi, 0, sizeof(pi));
        this->n = n;
    }

    int dijkstra(int s, int t) {
        fill(dist, dist+n, 1e8);
        fill(lim, lim+n, 0);
        fill(done, done+n, 0);
        dist[s] = 0;
        lim[s] = 1e9;
        int u = s;
        while (u != -1) {
            int best = -1;
            done[u] = 1;
            for (int i = 0; i < n; i++) {
                if (done[i]) continue;
                double v = dist[u] + pi[u] - pi[i] + cost[u][i];
                if (cap[u][i] > flow[u][i] && v < dist[i]) {
                    dist[i] = v;
                    parent[i] = make_pair(u, 1);
                    lim[i] = min(lim[u], cap[u][i] - flow[u][i]);
                }
                v = dist[u] + pi[u] - pi[i] - cost[i][u];
                if (flow[i][u] > 0 && v < dist[i]) {
                    dist[i] =  v;
                    parent[i] = make_pair(u, -1);
                    lim[i] = min(lim[u], flow[i][u]);
                }
                if (best == -1 || dist[i] < dist[best])
                    best = i;
            }
            u = best;
        }

        for (int i = 0; i < n; i++)
            pi[i] = min(pi[i] + dist[i], INF);
        return dist[t] != 1e8;
    }

    pid getFlow(int s, int t) {
        int f = 0;
        double c = 0;
        while (dijkstra(s, t)) {
            int aug = lim[t];
            f += aug;
            int x = t;
            while (x != s) {
                int p = parent[x].first;
                if (parent[x].second == 1) {
                    flow[p][x] += aug;
                    c += aug * cost[p][x];
                }
                else {
                    flow[x][p] -= aug;
                    c -= aug * cost[x][p];
                }
                x = p;
            }
        }
        return make_pair(f, c);
    }

    inline void add_edge(int u, int v, int c, double d) {
        cap[u][v] = c;
        cost[u][v] = d;
    }
};

int main(void) {
    int cnt = 0;
    mcmf mn, mx;
    while (true) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l == 0 && r == 0)
            break;
        mn.init(l+r+2);
        mx.init(l+r+2);
        int s = l + r, t = s + 1;
        for (int i = 0; i < l; i++) {
            int cap;
            scanf("%d", &cap);
            mn.add_edge(s, i, cap, 0);
            mx.add_edge(s, i, cap, 0);
        }
        for (int i = 0; i < r; i++) {
            int cap;
            scanf("%d", &cap);
            mn.add_edge(i + l, t, cap, 0);
            mx.add_edge(i + l, t, cap, 0);
        }
        double cost;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                scanf("%lf", &cost);
                if (cost != -1) {
                    mn.add_edge(i, j+l, 1e6, cost);
                    mx.add_edge(i, j+l, 1e6, -cost);
                }
            }
        }
        pid minans = mn.getFlow(s, t);
        pid maxans = mx.getFlow(s, t);
        printf("Problem %d: %.2lf to %.2lf\n", ++cnt, minans.second, -maxans.second);
    }
    return 0;
}

