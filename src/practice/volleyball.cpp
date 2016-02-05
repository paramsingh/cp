// http://codeforces.com/problemset/problem/95/C

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define INF LLONG_MAX
typedef long long int lli;
typedef pair<int, lli> pii;

class pri {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

lli dis[1010][1010] = {0};
lli mc[1010] = {0};
vector<pii> graph[1010];
vector<pii> cgraph[1010];
bool done[1010];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int s, d;
    scanf("%d %d", &s, &d);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }
    // calculating all pair shortest path values
    for (int beg = 1; beg <= n; beg++) {
        priority_queue<pii, vector<pii>, pri> pq;
        for (int i = 1; i <= n; i++)
            dis[beg][i] = INF;
        dis[beg][beg] = 0;
        memset(done, false, sizeof(done));
        pq.push(mp(beg, 0));
        while (!pq.empty()) {
            pii a = pq.top();
            int u = a.first;
            lli l = a.second;
            pq.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first;
                lli w = graph[u][i].second;
                if (!done[v] && dis[beg][v] > dis[beg][u] + w) {
                    dis[beg][v] = dis[beg][u] + w;
                    pq.push(mp(v, dis[beg][v]));
                }
            }
            done[u] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        int c, d;
        scanf("%d %d", &d, &c);
        for (int j = 1; j <= n; j++) {
            if (j != i && dis[i][j] <= d) {
                cgraph[i].pb(mp(j, (lli)c));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        mc[i] = INF;
    mc[s] = 0;
    priority_queue<pii, vector<pii>, pri> pq;
    memset(done, false, sizeof(done));
    pq.push(mp(s, 0));
    while (!pq.empty()) {
        pii a = pq.top();
        int u = a.first;
        lli l = a.second;
        if (u == d) {
            cout << l << endl;
            return 0;
        }
        pq.pop();
        for (int i = 0; i < cgraph[u].size(); i++) {
            int v = cgraph[u][i].first;
            lli w = cgraph[u][i].second;
            if (!done[v] && mc[v] > mc[u] + w) {
                mc[v] = mc[u] + w;
                pq.push(mp(v, mc[v]));
            }
        }
        done[u] = true;
    }
    printf("-1\n");
    return 0;
}
