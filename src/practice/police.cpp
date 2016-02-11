// http://codeforces.com/contest/208/problem/C

#include <bits/stdc++.h>
#define INF 1000000000
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

class pri {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

vector<int> graph[200];
vector<int> prev[200];
vector<int> next[200];
int dist[200];
int done[200];

long long int dp[200][200];

long long int rec(int cur, int base) {
    if (cur == base) {
        dp[cur][base] = 1;
        return 1;
    }

    if (dp[cur][base] != -1)
        return dp[cur][base];

    long long int ans = 0;
    for (int i = 0; i < prev[cur].size(); i++)
        ans += rec(prev[cur][i], base);

    return dp[cur][base] = ans;
}

int main(void) {
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++)
            dp[i][j] = -1;
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(done, 0, sizeof(done));
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;
    priority_queue<pii, vector<pii>, pri> pq;
    pq.push(mp(1, 0));
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int u = cur.first;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (done[v] == 0 && dist[v] > dist[u] + 1) {
                prev[v].clear();
                prev[v].push_back(u);
                dist[v] = dist[u] + 1;
                pq.push(mp(v, dist[v]));
            }
            else if (dist[v] == dist[u] + 1) {
                prev[v].push_back(u);
            }
        }
        done[u] = 1;
    }

    for (int i = 1; i <= n; i++)
        rec(n, i);
    long long int mx = 0;
    long long int total = dp[n][1];
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            mx = max(mx, dp[n][i]);
        else if (i == n)
            mx = max(mx, dp[i][1]);
        else
            mx = max(mx, 2*dp[i][1]*dp[n][i]);
    }
    double ans = mx / (double)(total);
    printf("%0.12lf\n", ans);
    return 0;
}
