#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
vector<pii> graph[10010];
int dp[20][10010];
int level[10010];
int subsize[10010];

void findparents(int u = 1, int p = -1) {
    subsize[u] = 1;
    for (auto pr: graph[u]) {
        int v = pr.first;
        if (v != p) {
            dp[0][v] = u;
            level[v] = level[u] + 1;
            findparents(v, u);
            subsize[u] += subsize[v];
        }
    }
}

int mapped[10010];
int head[10010];
int chain[10010];
int cnt = 1;
vector<int> base;

void hld(int u, int wt, int p = -1) {
    if (head[cnt] == 0)
        head[cnt] = u;

    chain[u] = cnt;
    mapped[u] = base.size();
    base.push_back(wt);

    int nxt = -1;
    int mx = -1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        if (v != p && mx < subsize[v]) {
            mx = subsize[v];
            nxt = i;
        }
    }

    if (nxt != -1)
        hld(graph[u][nxt].first, graph[u][nxt].second, u);

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second;
        if (i == nxt || v == p) continue;
        ++cnt;
        hld(v, w, u);
    }

}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    int diff = level[u] - level[v];
    for (int i = 0; i <= 15; i++) {
        if (diff & (1 << i))
            u = dp[i][u];
    }
    if (u == v) return u;
    for (int i = 15; i >= 0; i--) {
        if (dp[i][u] != dp[i][v])
            u = dp[i][u], v = dp[i][v];
    }
    return dp[0][u];
}

ll tree[50010];

void build(int i = 1, int l = 0, int r = base.size() - 1) {
    if (l == r) {
        tree[i] = base[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid + 1, r);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

ll get(int l, int r, int i = 1, int cl = 0, int cr = base.size() - 1) {
    if (cl > r || cr < l)
        return 0;
    else if (l <= cl && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        ll left = get(l, r, 2*i, cl, mid);
        ll right = get(l, r, 2*i + 1, mid + 1, cr);
        return left + right;
    }
}


ll query_up(int u, int v) {
    // v is an ancestor of u
    ll ans = 0;
    while (true) {
        if (chain[u] == chain[v]) {
            int pu = mapped[u], pv = mapped[v];
            ans += get(pv + 1, pu);
            break;
        }
        else {
            int pu = mapped[u];
            int h = head[chain[u]];
            ans += get(mapped[h], pu);
            u = dp[0][h];
        }
    }
    return ans;
}

ll dist(int u, int v) {
    int a = lca(u, v);
    return query_up(u, a) + query_up(v, a);
}

int kth(int u, int v, int k) {
    int a = lca(u, v);
    k--;
    if (level[u] - level[a] >= k) {
        int up = k;
        int ans = u;
        for (int i = 0; i <= 15; i++) {
            if (up & (1 << i))
                ans = dp[i][ans];
        }
        return ans;
    }
    else {
        int dist = level[v] - level[a];
        int need = k - (level[u] - level[a]);
        int up = dist - need;
        int ans = v;
        for (int i = 0; i <= 15; i++) {
            if (up & (1 << i))
                ans = dp[i][ans];
        }
        return ans;
    }
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        // lca calc
        memset(dp, -1, sizeof(dp));
        findparents();
        for (int i = 1; i <= 15; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i - 1][j] != -1)
                    dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }

        hld(1, 0);
        build();

        while (true) {
            char s[10]; int u, v, k;
            scanf("%s", s);
            if (s[1] == 'I') {
                scanf("%d %d", &u, &v);
                printf("%lld\n", dist(u, v));
            }
            if (s[1] == 'O')
                break;
            if (s[1] == 'T') {
                scanf("%d %d %d", &u, &v, &k);
                printf("%d\n", kth(u, v, k));
            }
        }
        printf("\n");

        for (int i = 1; i <= n; i++)
            graph[i].clear();
        base.clear();
        memset(subsize, 0, sizeof(subsize));
        memset(level, 0, sizeof(level));
        memset(mapped, 0, sizeof(mapped));
        memset(head, 0, sizeof(head));
        memset(chain, 0, sizeof(chain));
        cnt = 1;
    }
}
