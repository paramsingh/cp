/** http://www.spoj.com/problems/SAMER08A/ */
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 100000000000000
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;

class comp {
    public:
        bool operator() (const pii &a, const pii &b) {
            return a.second > b.second;
        }
};


int main(void) {
    int n, m;
    int src, dest;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;
        scanf("%d %d", &src, &dest);
        vector<pii> graph[510];
        vector<int> prev[510];
        lli dist[510];
        int* done;
        int u, v, w;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            graph[u].pb(mp(v, w));
        }
        done = (int*) calloc(n+10, sizeof(int));
        for (int i = 0; i < 510; i++)
            dist[i] = INF;
        dist[src] = 0;
        priority_queue<pii, vector<pii>, comp> q;
        q.push(mp(src, 0));
        while (!q.empty()) {
            u = q.top().first;
            q.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                v = graph[u][i].first;
                w = graph[u][i].second;
                if (!done[v] && dist[u] + w < dist[v]) {
                    prev[v].clear();
                    prev[v].pb(u);
                    dist[v] = dist[u] + w;
                    q.push(mp(v, dist[v]));
                }
                else if (dist[u] + w == dist[v]) {
                    prev[v].pb(u);
                }
            }
            done[u] = 1;
        }
        bool mark[510][510] = {0};
        done = (int*) calloc(n+10, sizeof(int));
        queue<int> q1;
        q1.push(dest);
        while (!q1.empty()) {
            u = q1.front();
            q1.pop();
            for (int i = 0; i < prev[u].size(); i++) {
                v = prev[u][i];
                if (!done[v]) {
                    mark[v][u] = true;
                    q1.push(v);
                }
            }
            done[u] = 1;
        }
        done = (int*) calloc(n+10, sizeof(int));
        for (int i = 0; i < 510; i++)
            dist[i] = INF;
        dist[src] = 0;
        priority_queue<pii, vector<pii>, comp> pq;
        pq.push(mp(src, 0));
        while (!pq.empty()) {
            u = pq.top().first;
            pq.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                v = graph[u][i].first;
                w = graph[u][i].second;
                if (!mark[u][v] && !done[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(mp(v, dist[v]));
                }
            }
            done[u] = 1;
        }
        if (dist[dest] != INF)
            printf("%lld\n", dist[dest]);
        else
            printf("-1\n");
    }
    return 0;
}
