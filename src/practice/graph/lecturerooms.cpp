#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100100];
int dp[30][100100];
int down[100100];
int level[100100];

void dfs(int u, int p = 0) {
    level[u] = level[p] + 1;
    dp[0][u] = p;
    down[u] = 1;
    for (int v: graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        down[u] += down[v];
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    int diff = level[u] - level[v];
    for (int i = 0; i <= 20; i++)
        if (diff & (1 << i))
            u = dp[i][u];
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) {
        if (dp[i][u] != dp[i][v]) {
            u = dp[i][u];
            v = dp[i][v];
        }
    }
    return dp[0][u];
}

int n;

int goup(int u, int ht) {
    for (int i = 0; i <= 20; i++)
        if (ht & (1 << i))
            u = dp[i][u];
    return u;
}

int get(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    int a = lca(u, v);
    if (level[u] == level[v]) {
        int ht = level[v] - (level[a] + 1);
        int pu = goup(u, ht), pv = goup(v, ht);
        return n - down[pu] - down[pv];
    }
    else {
        int du = level[u] - level[a];
        int dv = level[v] - level[a];
        // du - x = dv + x
        // du + dv = 2 * x
        if ((du + dv) & 1) return 0;
        int mid = (du + dv) / 2;
        int ht = mid;
        int pu = goup(u, ht);
        int rem = goup(u, ht - 1);
        return down[pu] - down[rem];
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    for (int lg = 1; lg <= 20; lg++) {
        for (int u = 1; u <= n; u++) {
            if (dp[lg - 1][u] != 0)
                dp[lg][u] = dp[lg - 1][dp[lg - 1][u]];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", get(u, v));
    }
}
