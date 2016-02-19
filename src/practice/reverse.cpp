// 20:54
#include <bits/stdc++.h>
#define mp make_pair
#define INF 100000000
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;

class cmp {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

vector<int> graph[100100];
int dist[100100] = {0};
int done[100100] = {0};
set<pii> edges;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.insert(mp(u, v));
    }
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
        done[i] = 0;
    }
    dist[1] = 0;
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push(mp(1, 0));
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int u = cur.first;
        if (u == n) {
            printf("%d\n", cur.second);
            return 0;
        }
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            int w;
            if (!edges.count(mp(u, v)))
                w = 1;
            else
                w = 0;
            if (!done[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(mp(v, dist[v]));
            }
        }
        done[u] = 1;
    }
    printf("-1\n");
    return 0;
}

