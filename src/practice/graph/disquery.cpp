#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n;
vector<pair<int, int> > graph[100100];
int level[100100];

int mx[30][100100];
int mn[30][100100];
int dp[30][100100];

int dfs(int u = 1, int p = -1) {
    for (auto e: graph[u]) {
        int v = e.first, w = e.second;
        if (v != p) {
            level[v] = level[u] + 1;
            dp[0][v] = u;
            mx[0][v] = mn[0][v] = w;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (level[u] < level[v])
        swap(u, v);
    int diff = level[u] - level[v];
    for (int i = 0; i <= 20; i++) {
        if (diff & (1 << i))
            u = dp[i][u];
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--) {
        if (dp[i][u] != dp[i][v])
            u = dp[i][u], v = dp[i][v];
    }
    return dp[0][u];
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i <= 25; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
            mn[i][j] = inf;
            mx[i][j] = -inf;
        }
    }

    dfs();
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] != -1) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][dp[i - 1][j]]);
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][dp[i - 1][j]]);
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }


    int q;
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        int a = lca(u, v);
        int diff = level[u] - level[a];
        int minans = inf, maxans = -inf;
        int x = u;
        for (int i = 0; i <= 20; i++) {
            if (diff & (1 << i)) {
                minans = min(minans, mn[i][x]);
                maxans = max(maxans, mx[i][x]);
                x = dp[i][x];
            }
        }
        diff = level[v] - level[a];
        x = v;
        for (int i = 0; i <= 20; i++) {
            if (diff & (1 << i)) {
                minans = min(minans, mn[i][x]);
                maxans = max(maxans, mx[i][x]);
                x = dp[i][x];
            }
        }
        printf("%d %d\n", minans, maxans);
    }
    return 0;
}
