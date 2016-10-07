#include <bits/stdc++.h>
using namespace std;

int n, m;
int weights[100100];
vector<int> compress;
vector<int> graph[100100];

inline int scanint() {
    register int x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar_unlocked();
    }
    return x;
}

int dp[32][100100];
int level[100100];

int find(int val) {
    int lo = 0, hi = compress.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (compress[mid] >= val)
            hi = mid;
        else
            lo = mid + 1;
    }
    assert(compress[lo] == val);
    return lo;
}

void findparent(int u = 1, int p = -1) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != p) {
            level[v] = level[u] + 1;
            dp[0][v] = u;
            findparent(v, u);
        }
    }
}

inline int lca(int u, int v) {
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

int nodes = 1;

struct node {
    int val;
    int l, r;
} tree[5001000];

int roots[100100];

void build(int node, int l = 0, int r = compress.size() - 1) {
    if (l == r)
        return;
    tree[node].l = nodes++;
    tree[node].r = nodes++;
    int mid = (l + r) / 2;
    build(tree[node].l, l, mid);
    build(tree[node].r, mid + 1, r);
}

int update(int id, int prev, int node, int l = 0, int r = compress.size() - 1) {
    if (l == r && l == id) {
        tree[node].val = tree[prev].val + 1;
        return node;
    }
    else {
        int mid = (l + r) / 2;
        if (id <= mid) {
            tree[node].l = update(id, tree[prev].l, nodes++, l, mid);
            tree[node].r = tree[prev].r;
        }
        else {
            tree[node].l = tree[prev].l;
            tree[node].r = update(id, tree[prev].r, nodes++, mid + 1, r);
        }
        int lc = tree[node].l, rc = tree[node].r;
        tree[node].val = tree[lc].val + tree[rc].val;
        return node;
    }
}

int query(int l, int r, int nid, int cl = 0, int cr = compress.size() - 1) {
    if (cl > r || cr < l || l > r)
        return 0;
    if (l <= cl && cr <= r)
        return tree[nid].val;
    int mid = (cl + cr) / 2;
    int left = query(l, r, tree[nid].l, cl, mid);
    int right = query(l, r, tree[nid].r, mid + 1, cr);
    return left + right;
}

void build_trees(int u, int p) {
    roots[u] = update(find(weights[u]), roots[p], nodes++);
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != p)
            build_trees(v, u);
    }
}

int findans(int u, int v, int a, int pa, int k, int l = 0, int r = compress.size() - 1) {
    if (l == r)
        return l;

    int left = tree[tree[u].l].val + tree[tree[v].l].val - tree[tree[a].l].val - tree[tree[pa].l].val;
    int mid = (l + r) / 2;

    if (left >= k)
        return findans(tree[u].l, tree[v].l, tree[a].l, tree[pa].l, k, l, mid);
    else
        return findans(tree[u].r, tree[v].r, tree[a].r, tree[pa].r, k - left, mid + 1, r);
}

int main(void) {
    n = scanint(), m = scanint();
    for (int i = 1; i <= n; i++) {
        weights[i] = scanint();
        compress.push_back(weights[i]);
    }
    sort(compress.begin(), compress.end());
    vector<int>::iterator it = unique(compress.begin(), compress.end());
    compress.resize(distance(compress.begin(), it));

    for (int i = 0; i < n - 1; i++) {
        int u = scanint(), v = scanint();
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // lca calculations
    memset(dp, -1, sizeof(dp));
    findparent();
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    roots[0] = nodes;
    build(nodes++);
    build_trees(1, 0);

    while (m--) {
        int u, v, k;
        u = scanint(), v = scanint(), k = scanint();
        int ancestor = lca(u, v);
        int lo = findans(roots[u], roots[v], roots[ancestor], (dp[0][ancestor] == -1) ? 0 : roots[dp[0][ancestor]], k);
        printf("%d\n", compress[lo]);
    }
    return 0;
}
