#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 1e9 + 1e8 + 10;

set<pii> adj[100100];
int dp[32][100100];
int level[100100];
int depth[100100];
int weights[100100];
int n;

void parents(int u, int p = -1) {
    dp[0][u] = p;
    for (auto e: adj[u]) {
        int v = e.first, w = weights[e.second];
        if (v != p) {
            level[v] = level[u] + w;
            depth[v] = depth[u] + 1;
            parents(v, u);
        }
    }
}

void preprocess() {
    memset(dp, -1, sizeof(dp));
    parents(1);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; i <= 20; i++) {
        if (diff & (1 << i)) {
            u = dp[i][u];
        }
    }
    if (u == v)
        return u;

    for (int i = 20; i >= 0; i--) {
        if (dp[i][u] != dp[i][v])
            u = dp[i][u], v = dp[i][v];
    }
    return dp[0][u];
}

int dist(int u, int v) {
    return level[u] + level[v] - 2 * level[lca(u, v)];
}


int parent[100100];
int subtree[100100];
int cmp;

int dfs(int u, int p = -1) {
    subtree[u] = 1;
    for (auto e: adj[u]) {
        int v = e.first;
        if (v != p)
            subtree[u] += dfs(v, u);
    }
    return subtree[u];
}

int findcentroid(int u, int p = -1) {
    for (auto e: adj[u]) {
        int v = e.first;
        if (v != p && subtree[v] > cmp / 2)
            return findcentroid(v, u);
    }
    return u;
}

int root;

void decompose(int u, int p = -1) {
    cmp = dfs(u);
    int c = findcentroid(u);
    if (p == -1) p = c, root = c;
    parent[c] = p;
    for (auto e: adj[c]) {
        int v = e.first;
        adj[v].erase(make_pair(c, e.second));
        decompose(v, c);
    }
}

int ans[100100];
struct nd {
    int u, dist;
    nd(int a, int b): u(a), dist(b) {}
    bool operator<(const nd& b) const {
        return dist > b.dist;
    }
};

set<nd> whites[100100];
int color[100100];

void add(int u) {
    int x = u;
    while (true) {
        whites[x].insert(nd(u, dist(u, x)));
        if (x == parent[x])
            return;
        x = parent[x];
    }
}

void remove(int u) {
    int x = u;
    while (true) {
        whites[x].erase(nd(u, dist(u, x)));
        if (x == parent[x])
            return;
        x = parent[x];
    }
}

void update(int u) {
    printf("update at %d\n", u);
    color[u] ^= 1;
    if (color[u] == 1)
        add(u);
    else
        remove(u);

    int x = u;
    while (true) {
        int toadd = -inf;
        for (auto n: whites[x]) {
            if (n.u == u)
                continue;
            else {
                toadd = n.dist;
                break;
            }
        }
        printf("x = %d, toadd = %d, dist(x, u) = %d\n", x, toadd, dist(x, u));
        if (toadd != -inf)
            ans[x] = max(ans[x], toadd + dist(x, u));
        if (x == parent[x])
            break;
        x = parent[x];
    }
}


int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        ans[i] = -inf;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].insert(make_pair(v, i));
        adj[v].insert(make_pair(u, i));
        weights[i] = w;
    }
    preprocess();
    decompose(1);
    for (int i = 1; i <= n; i++)
        update(i);
    int q;
    scanf("%d", &q);
    while (q--) {
        char c = getchar_unlocked();
        while (c < 'A' || c > 'Z')
            c = getchar_unlocked();
        if (c == 'C') {
            int x;
            scanf("%d", &x);
            update(x);
        }
        else {
            if (ans[root] == -inf)
                printf("They have disappeared.\n");
            else
                printf("%d\n", ans[root]);
        }
    }
    return 0;
}
