// Centroid Decomposition

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

set<int> graph[100100];
int n;

// lca stuff
int dp[34][100100];
int level[100100];
void findparent(int u, int p = -1) {
    dp[0][u] = p;
    set<int>::iterator it;
    for (it = graph[u].begin(); it != graph[u].end(); it++) {
        int v = *it;
        if (v != p) {
            level[v] = level[u] + 1;
            findparent(v, u);
        }
    }
}

int lca(int u, int v) {
    if (level[u] > level[v]) swap(u, v);

    int diff = level[v] - level[u];
    for (int i = 0; i <= 20; i++)
        if (diff & (1 << i))
            v = dp[i][v];
    if (u == v)
        return u;

    for (int i = 20; i >= 0; i--) {
        if (dp[i][u] != dp[i][v])
            u = dp[i][u], v = dp[i][v];
    }
    return dp[0][v];
}

int dist(int u, int v) {
    return level[u] + level[v] - 2*level[lca(u, v)];
}


// centroid decomposition
int parent[100100];
int subtree[100100];
int cmp;

void dfs1(int u, int p = -1) {
    subtree[u] = 1;
    cmp++;
    set<int>::iterator it;
    for (it = graph[u].begin(); it != graph[u].end(); it++) {
        int v = (*it);
        if (v != p) {
            dfs1(v, u);
            subtree[u] += subtree[v];
        }
    }
}

int findcentroid(int u, int p = -1) {
    set<int>::iterator it;
    for (it = graph[u].begin(); it != graph[u].end(); it++) {
        int v = (*it);
        if (v != p && subtree[v] > cmp / 2)
            return findcentroid(v, u);
    }
    return u;
}

void decompose(int u, int p = -1) {
    cmp = 0;
    dfs1(u);
    int centroid = findcentroid(u);
    if (p == -1) p = centroid;
    parent[centroid] = p;
    set<int>::iterator it;
    for (it = graph[centroid].begin(); it != graph[centroid].end(); it++) {
        int v = (*it);
        graph[v].erase(centroid);
        decompose(v, centroid);
    }
    graph[centroid].clear();
}

int ans[100100];

void update(int u) {
    int v = u;
    while (true) {
        ans[u] = min(ans[u], dist(u, v));
        if (u == parent[u])
            break;
        u = parent[u];
    }
}

int query(int u) {
    int sol = inf;
    int v = u;
    while (true) {
        sol = min(sol, ans[u] + dist(u, v));
        if (u == parent[u])
            break;
        u = parent[u];
    }
    return sol;
}


int main(void) {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        ans[i] = inf;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }

    // calculate lca dp array;
    memset(dp, -1, sizeof(dp));
    level[1] = 0;
    findparent(1);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    // create centroid decomposed tree
    decompose(1);

    // 1 is already colored
    update(1);
    while (m--) {
        int t, v;
        scanf("%d %d", &t, &v);
        if (t == 1)
            update(v);
        else
            printf("%d\n", query(v));
    }
    return 0;
}
