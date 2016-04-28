#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

struct mcmf {
    int n;
    int cost[100][100];
    int flow[100][100];
    int cap[100][100];
    int dist[100];
    int pi[100];
    int done[100];
    int lim[100];
    pii parent[100];
    void init(int n) {
        this->n = n;
        memset(cost, 0, sizeof(cost));
        memset(flow, 0, sizeof(flow));
        memset(cap, 0, sizeof(cap));
        memset(pi, 0, sizeof(pi));
    }

    int dijkstra(int s, int t) {
        fill(dist, dist+n+1, INF);
        fill(lim, lim+n+1, 0);
        fill(done, done+n+1, 0);
        dist[s] = 0;
        lim[s] = 1e9;
        int u = s;
        while (u != -1) {
            int best = -1;
            done[u] = 1;
            for (int i = 1; i <= n; i++) {
                if (done[i]) continue;
                int v = dist[u] + pi[u] - pi[i] + cost[u][i];
                if (cap[u][i] > flow[u][i] && dist[i] > v) {
                    dist[i] = v;
                    parent[i] = make_pair(u, 1);
                    lim[i] = min(lim[u], cap[u][i] - flow[u][i]);
                }
                v = dist[u] + pi[u] - pi[i] - cost[i][u];
                if (flow[i][u] > 0 && dist[i] > v) {
                    dist[i] = v;
                    parent[i] = make_pair(u, -1);
                    lim[i] = min(lim[u], flow[i][u]);
                }
                if (best == -1 || dist[i] < dist[best])
                    best = i;
            }
            u = best;
        }

        for (int i = 1; i <= n; i++)
            pi[i] = min(pi[i] + dist[i], INF);
        return dist[t] != INF;
    }

    pii getFlow(int s, int t) {
        int c = 0;
        int f = 0;
        while (dijkstra(s, t)) {
            int aug = lim[t];
            f += aug;
            int u = t;
            while (u != s) {
                int p = parent[u].first;
                if (parent[u].second == 1) {
                    flow[p][u] += aug;
                    c += aug * cost[p][u];
                }
                else {
                    flow[u][p] -= aug;
                    c -= aug * cost[u][p];
                }
                u = p;
            }
        }
        return make_pair(f, c);
    }

    inline void add_edge(int u, int v, int cp, int ct) {
        cap[u][v] = cp;
        cost[u][v] = ct;
    }
};

int main(void) {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        pii baby[n+10];
        pii correct[n+10];
        int c;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c);
            baby[i] = make_pair(i, c);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c);
            correct[i] = make_pair(i, c);
        }
        mcmf mf;
        mf.init(2*n+2);
        int src = 2*n+1, sink = src + 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int dist = abs(baby[i].first - correct[j].first)
                            + abs(baby[i].second - correct[j].second);
                mf.add_edge(i, n+j, 1, dist);
            }
            mf.add_edge(src, i, 1, 0);
            mf.add_edge(i+n, sink, 1, 0);
        }
        pii ans = mf.getFlow(src, sink);
        printf("%d\n", ans.second);
    }
    return 0;
}
