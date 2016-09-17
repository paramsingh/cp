#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

vector<int> graph[100100];
vector<ll> w[100100];
vector<int> k[100100];
ll ans[100100];
int size = 0;
int n;

ll tree[400100];

void update(int id, ll val, int i = 1, int s = 1, int e = n) {
    if (s == e && s == id)
        tree[i] = val;
    else {
        int mid = (s + e) / 2;
        if (id <= mid)
            update(id, val, 2*i, s, mid);
        else
            update(id, val, 2*i+1, mid + 1, e);
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}

ll get(int l, int r, int i = 1, int s = 1, int e = n) {
    if (s > r || e < l)
        return inf;
    else if (s >= l && e <= r)
        return tree[i];
    else {
        int mid = (s + e) / 2;
        ll left = get(l, r, 2*i, s, mid);
        ll right = get(l, r, 2*i+1, mid + 1, e);
        return min(left, right);
    }
}

void dfs(int u, int p = -1) {
    if (u == 1)
        ans[u] = 0;
    else if (!w[u].empty()) {
        ll sol = inf;
        for (int i = 0; i < w[u].size(); i++) {
            int wi = w[u][i], ki = k[u][i];
            sol = min(sol, get(max(1, size - ki + 1), size) + wi);
        }
        ans[u] = sol;
    }
    else
        ans[u] = inf;

    update(++size, ans[u]);
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != p)
            dfs(v, u);
    }
    update(size--, 0);
}

int main(void) {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < m; i++) {
        int vi, ki, wi;
        scanf("%d %d %d", &vi, &ki, &wi);
        w[vi].push_back(wi);
        k[vi].push_back(ki);
    }

    dfs(1);
    int q;
    scanf("%d", &q);
    while (q--) {
        int city;
        scanf("%d", &city);
        assert(ans[city] < inf);
        printf("%lld\n", ans[city]);
    }
    return 0;
}
