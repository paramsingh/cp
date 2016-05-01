#include <bits/stdc++.h>
#define INF 1000000000
#define SIZE 1000
using namespace std;
typedef pair<int, int> pii;


struct mcmf {
    int n;
    int s, t;
    int cap[SIZE][SIZE];
    int flow[SIZE][SIZE];
    int cost[SIZE][SIZE];
    int pi[SIZE];
    int dist[SIZE];
    int lim[SIZE];
    int done[SIZE];
    pii parent[SIZE];

    void init(int x, int y, int z) {
        n = x, s = y, t = z;
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(cost, 0, sizeof(cost));
        memset(pi, 0, sizeof(pi));
    }

    void add(int u, int v, int c, int ct) {
        cap[u][v] = c;
        cost[u][v] = ct;
    }

    int dijkstra() {
        for (int i = 0; i <= n; i++) {
            dist[i] = INF;
            lim[i] = -1;
            done[i] = 0;
        }
        dist[s] = 0;
        lim[s] = INF;
        int u = s;
        while (u != -1) {
            int best = -1;
            done[u] = 1;
            for (int i = 0; i <= n; i++) {
                if (done[i] == 0) {
                    int v = i;
                    int c = dist[u] + pi[u] - pi[i] + cost[u][v];
                    if (cap[u][v] > flow[u][v] && dist[i] > c) {
                        dist[i] = c;
                        parent[i] = make_pair(u, 1);
                        lim[i] = min(lim[u], cap[u][i] - flow[u][i]);
                    }
                    c = dist[u] + pi[u] - pi[i] - cost[v][u];
                    if (flow[v][u] > 0 && dist[i] > c) {
                        dist[i] = c;
                        parent[i] = make_pair(u, -1);
                        lim[i] = min(lim[u], flow[i][u]);
                    }
                    if (best == -1 || dist[i] < dist[best])
                        best = i;
                }
            }
            u = best;
        }

        for (int i = 0; i <= n; i++) {
            pi[i] = min(pi[i] + dist[i], INF);
        }
        return dist[t] != INF;
    }

    pii getflow() {
        int f = 0;
        int c = 0;
        while (dijkstra()) {
            int aug = lim[t];
            f += aug;
            int x = t;
            while (x != s) {
                int p = parent[x].first;
                if (parent[x].second == 1) {
                    flow[p][x] += aug;
                    c += cost[p][x] * aug;
                }
                else {
                    flow[x][p] -= aug;
                    c -= cost[x][p] * aug;
                }
                x = p;
            }
        }
        return make_pair(f, c);
    }
};


int freq[1000];
mcmf mf;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        mf.init(n+2, 0, n+1);
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            freq[x]++;
        }
        int e;
        scanf("%d", &e);
        while (e--) {
            int u, v;
            scanf("%d %d", &u, &v);
            mf.add(v, u, 1e8, 1);
            mf.add(u, v, 1e8, 1);
        }
        for (int i = 1; i <= n; i++) {
            if (freq[i] != 0)
                mf.add(0, i, freq[i], 0);
            mf.add(i, n+1, 1, 0);
        }
        pii ans = mf.getflow();
        assert(ans.first == n);
        printf("%d\n", ans.second);
    }
    return 0;
}
