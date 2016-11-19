#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = INT_MAX;

int n, m;
vector<int> graph[100100], transpose[100100];
int cost[100100];
int visited[100100];
vector<int> topo;
int mn, cnt;

void dfs(int u) {
    visited[u] = 1;
    for (int v: graph[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
    topo.push_back(u);
}

void dfs2(int u) {
    visited[u] = 1;
    if (cost[u] < mn) {
        mn = cost[u];
        cnt = 1;
    }
    else if (cost[u] == mn) {
        cnt++;
    }
    for (int v: transpose[u]) {
        if (visited[v] == 0)
            dfs2(v);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        transpose[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        if (visited[u] == 0)
            dfs(u);
    }
    ll ways = 1, ans = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = topo.size() - 1; i >= 0; i--) {
        int v = topo[i];
        if (visited[v] == 0) {
            mn = inf;
            cnt = 0;
            dfs2(v);
            ans += mn;
            ways = (ways * cnt) % mod;
        }
    }
    printf("%lld %lld\n", ans, ways);
}
