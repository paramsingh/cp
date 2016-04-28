#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
char field[200][200];
int man[200][2];
int house[200][2];

struct mcmf {
    int n;
    int dist[500];
    int lim[500];
    pii parent[500];
    int cost[500][500];
    int cap[500][500];
    int pi[500];
    int flow[500][500];
    int done[500];

    mcmf(int n) {
        this->n = n;
        memset(cost, 0, sizeof(cost));
        memset(pi, 0, sizeof(pi));
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
    }

    int dijkstra(int s, int t) {
        for (int i = 0; i < n; i++) {
            dist[i] = 1000000000;
            lim[i] = 0;
            done[i] = 0;
        }
        dist[s] = 0;
        lim[s] = 100000000;
        int u = s;
        while (u != -1) {
            int best = -1;
            done[u] = 1;
            for (int v = 0; v < n; v++) {
                if (done[v]) continue;
                int d = dist[u] + pi[u] - pi[v] + cost[u][v];
                if (cap[u][v] > flow[u][v] && d < dist[v]) {
                    dist[v] = d;
                    lim[v] = min(lim[u], cap[u][v] - flow[u][v]);;
                    parent[v] = make_pair(u, 1);
                }
                d = dist[u] + pi[u] - pi[v] - cost[v][u];
                if (flow[v][u] > 0 && d < dist[v]) {
                    dist[v] = d;
                    lim[v] = min(lim[u], flow[v][u]);
                    parent[v] = make_pair(u, -1);
                }
                if (best == -1 || dist[v] < dist[best])
                    best = v;
            }
            u = best;
        }
        return dist[t] != 1000000000;
    }

    pii getFlow(int s, int t) {
        int f = 0;
        int c = 0;
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

    inline void add_edge(int u, int v, int cp, int ct) {
        cap[u][v] = cp;
        cost[u][v] = ct;
    }
};


int main(void) {
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++) {
            scanf("%s", field[i]);
        }
        int men = 0, houses = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == 'm') {
                    man[men][0] = i;
                    man[men][1] = j;
                    men++;
                }
                else if (field[i][j] == 'H') {
                    house[houses][0] = i;
                    house[houses][1] = j;
                    houses++;
                }
            }
        }
        int src = men + houses, sink = src + 1;
        mcmf mf(men+houses+2);
        for (int i = 0; i < men; i++) {
            for (int j = 0; j < houses; j++) {
                int dist = abs(man[i][0] - house[j][0]) + abs(man[i][1] - house[j][1]);
                mf.add_edge(i, men+j, 1e8, dist);
            }
            mf.add_edge(src, i, 1, 0);
        }
        for (int i = 0; i < houses; i++)
            mf.add_edge(i+men, sink, 1, 0);
        printf("%d\n", mf.getFlow(src, sink).second);
    }
    return 0;
}
