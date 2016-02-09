// http://www.spoj.com/problems/TRAFFICN/

#include <bits/stdc++.h>
#define INF 1000010000
#define mp make_pair
using namespace std;
typedef long long int lli;
typedef pair<int, lli> pii;

class pri {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

lli from[10100];
lli to[10100];
bool done[10100];

vector<pii> graph[10100];
vector<pii> rev[10100];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 10100; i++) {
            graph[i].clear();
            rev[i].clear();
        }
        int n, m, k, s, t;
        scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
        int dup = m;
        while (dup--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(mp(v, w));
            rev[v].push_back(mp(u, w));
        }
        for (int i = 1; i <= n; i++)
            from[i] = INF;
        memset(done, false, sizeof(done));
        from[s] = 0;
        priority_queue<pii, vector<pii>, pri> pq;
        pq.push(mp(s, from[s]));
        while (!pq.empty()) {
            pii a = pq.top();
            pq.pop();
            int u = a.first;
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i].first;
                lli w = graph[u][i].second;
                if (!done[v] && from[v] > from[u] + w) {
                    from[v] = from[u] + w;
                    pq.push(mp(v, from[v]));
                }
            }
            done[u] = true;
        }
        memset(done, false, sizeof(done));
        for (int i = 1; i <= n; i++)
            to[i] = INF;
        to[t] = 0;
        pq.push(mp(t, to[t]));
        while (!pq.empty()) {
            pii a = pq.top();
            pq.pop();
            int u = a.first;
            for (int i = 0; i < rev[u].size(); i++) {
                int v = rev[u][i].first;
                lli w = rev[u][i].second;
                if (!done[v] && to[v] > to[u] + w) {
                    to[v] = to[u] + w;
                    pq.push(mp(v, to[v]));
                }
            }
            done[u] = true;
        }
        lli mi = from[t];
        while (k--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (from[u] + w + to[v] < mi)
                mi = from[u] + w + to[v];
            if (from[v] + w + to[u] < mi)
                mi = from[v] + w + to[u];
        }
        if (mi == INF)
            printf("-1\n");
        else
            printf("%lld\n", mi);
    }
    return 0;
}
