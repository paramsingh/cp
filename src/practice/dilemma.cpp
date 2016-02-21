// 11:11
#include <bits/stdc++.h>
#define mp make_pair
#define INF 1000000000
using namespace std;
typedef long long int lli;

class state {
    public:
        int taken;
        int d;
        int id;
        state(int a, int b, int c) {
            id = a;
            taken = b;
            d = c;
        }
};

class cmp {
    public:
        bool operator() (const state& a, const state& b) {
            return a.d > b.d;
        }
};

vector<int> adj[4000];
vector<int> w[4000];
vector<int> car[4000];

int dist[4][4000];
int done[4][4000];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            w[i].clear();
            car[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v, wt, c;
            scanf("%d %d %d %d", &u, &v, &wt, &c);
            adj[u].push_back(v);
            w[u].push_back(wt);
            car[u].push_back(c);
            adj[v].push_back(u);
            w[v].push_back(wt);
            car[v].push_back(c);
        }
        int s, dest;
        scanf("%d %d", &s, &dest);
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i <= n; i++) {
                dist[j][i] = INF;
                done[j][i] = 0;
            }
        }
        priority_queue<state, vector<state>, cmp> pq;
        dist[0][s] = 0;
        pq.push(state(s, 0, 0));
        int ans = -1;
        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            int u = cur.id, taken = cur.taken, d = cur.d;
            if (u == dest) {
                ans = d;
                break;
            }
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                int wt = w[u][i];
                int take = car[u][i];
                if (taken == 1) {
                    if (!done[1][v] && dist[1][v] > dist[1][u] + wt) {
                        dist[1][v] = dist[1][u] + wt;
                        pq.push(state(v, 1, dist[1][v]));
                    }
                }
                else {
                    if (!done[0][v] && dist[0][v] > dist[0][u] + wt) {
                        dist[0][v] = dist[0][u] + wt;
                        pq.push(state(v, 0, dist[0][v]));
                    }
                    if (!done[1][v] && dist[1][v] > dist[0][u] + take) {
                        dist[1][v] = dist[0][u] + take;
                        pq.push(state(v, 1, dist[1][v]));
                    }
                }
            }
            done[taken][u] = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
