#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

set<int> graph[100100];
multiset<int> ans[100100];
int color[100100];
int n;

// LCA Stuff
int level[100100];
int dp[32][100100];

void findparent(int u, int p = -1) {
    dp[0][u] = p;
    for (auto v: graph[u]) {
        if (v != p) {
            level[v] = level[u] + 1;
            findparent(v, u);
        }
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);

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

inline int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u, v)];
}

// Centroid decomposition stuff
int cmp;
int subtree[100100];
int parent[100100];

int dfs1(int u, int p = -1) {
    subtree[u] = 1;
    for (auto v: graph[u]) {
        if (v != p) {
            subtree[u] += dfs1(v, u);
        }
    }
    return subtree[u];
}

int findcentroid(int u, int p = -1) {
    for (auto v: graph[u]) {
        if (v != p && subtree[v] > cmp / 2)
            return findcentroid(v, u);
    }
    return u;
}

void decompose(int u, int p = -1) {
    cmp = dfs1(u);
    int centroid = findcentroid(u);
    if (p == -1) p = centroid;
    parent[centroid] = p;
    for (auto v: graph[centroid]) {
        graph[v].erase(centroid);
        decompose(v, centroid);
    }
    graph[centroid].clear();
}


// update and query
void update(int u) {
    color[u] ^= 1;
    if (color[u] == 0) {
        int x = u;
        while (true) {
            ans[x].erase(ans[x].find(dist(u, x)));
            if (parent[x] == x)
                break;
            x = parent[x];
        }
    }
    else {
        int x = u;
        while (true) {
            ans[x].insert(dist(x, u));
            if (parent[x] == x)
                break;
            x = parent[x];
        }
    }
}

int query(int u) {
    int ret = inf;
    int x = u;
    while (true) {
        int val = inf;
        if (!ans[x].empty())
            val = *(ans[x].begin());
        ret = min(ret, val + dist(x, u));
        if (parent[x] == x)
            break;
        x = parent[x];
    }
    return ret;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }
    findparent(1);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    decompose(1);
    int q;
    scanf("%d", &q);
    while (q--) {
        int t, u;
        scanf("%d %d", &t, &u);
        if (t == 0)
            update(u);
        else {
            int ret = query(u);
            if (ret == inf)
                printf("-1\n");
            else
                printf("%d\n", ret);
        }
    }
    return 0;
}
