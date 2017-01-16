#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll inf = 1e18;

struct cmp {
    bool operator() (const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

ll dist[110][110];
vector<pii> tasks;
vector<pii> graph[110];
ll dp[4][110][5010];
int n, m, k;
int done[110];

void dijkstra(int u) {
    for (int i = 1; i <= n; i++)
        dist[u][i] = inf;
    dist[u][u] = 0;
    memset(done, 0, sizeof(done));
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push(make_pair(u, dist[u][u]));
    while (!pq.empty()) {
        pii x = pq.top(); pq.pop();
        for (int i = 0; i < graph[x.first].size(); i++) {
            int v = graph[x.first][i].first, w = graph[x.first][i].second;
            if (done[v]) continue;
            if (dist[u][v] > dist[u][x.first] + w) {
                dist[u][v] = dist[u][x.first] + w;
                pq.push(make_pair(v, dist[u][v]));
            }
        }
        done[x.first] = 1;
    }
}

void clear() {
    for (int i = 1; i <= n; i++)
        graph[i].clear();
    memset(dist, 0, sizeof(dist));
    memset(done, 0, sizeof(done));
    tasks.clear();
}

ll go(int u, int t, int have) {
    if (t == k) {
        if (have == 0)
            return 0;
        if (have == 1)
            return dist[u][tasks[k - 1].second];
        if (have == 2) {
            int dest1 = tasks[k - 2].second, dest2 = tasks[k - 1].second;
            return dist[u][dest1] + dist[dest1][dest2];
        }
    }
    if (dp[have][u][t] != -1) return dp[have][u][t];
    if (have == 0) {
        // dont have a task so need to take one
        int nxt = tasks[t].first;
        return dp[have][u][t] = dist[u][nxt] + go(nxt, t + 1, 1);
    }
    else if (have == 1) {
        ll ans = inf;
        // finish task we have
        int nxt = tasks[t - 1].second;
        ans = min(ans, dist[u][nxt] + go(nxt, t, 0));
        // or take the next task also
        nxt = tasks[t].first;
        ans = min(ans, dist[u][nxt] + go(nxt, t + 1, 2));
        return dp[have][u][t] = ans;
    }
    else if (have == 2) {
        // can only finish the first task we have
        int nxt = tasks[t - 2].second;
        return dp[have][u][t] = dist[u][nxt] + go(nxt, t, 1);
    }
}


int main(void) {
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        for (int i = 1; i <= n; i++)
            dijkstra(i);
        int flag = 0;
        for (int i = 1; i <= k; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (dist[u][v] == inf) flag = 1;
            tasks.push_back(make_pair(u, v));
        }
        if (flag == 1) {
            printf("Case #%d: -1\n", c);
            clear();
            continue;
        }
        memset(dp, -1, sizeof(dp));
        ll ans = go(1, 0, 0);
        printf("Case #%d: %lld\n", c, ans);
        clear();
    }
}
