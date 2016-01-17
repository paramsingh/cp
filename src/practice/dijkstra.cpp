/** http://codeforces.com/problemset/problem/20/C */
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 100000000000
typedef long long int lli;
typedef pair<int, lli> pii;

class comp {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pii> graph[n+10];
    int u, v, w;
    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    priority_queue<pii, vector<pii>, comp> pq;
    pq.push(mp(1, 0));
    lli dist[n+10];
    dist[1] = 0;
    int* done = (int*) calloc(n+10, sizeof(int));
    int prev[n+10];
    prev[1] = -1;
    for (int i = 2; i <= n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    while (!pq.empty()) {
        u = pq.top().first;
        pq.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i].first;
            w = graph[u][i].second;
            if (!done[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(mp(v, dist[v]));
            }
        }
        done[u] = 1;
    }
    if (dist[n] == INF)
        printf("-1\n");
    else {
        vector<int> path;
        int cur = n;
        while (cur != 1) {
            path.push_back(cur);
            cur = prev[cur];
        }
        printf("1 ");
        for (int i = path.size()-1; i >= 0; i--)
            printf("%d ", path[i]);
        printf("\n");
    }
    return 0;
}
