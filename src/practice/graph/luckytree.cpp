#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const int mod = 1e9 + 7;

int lucky(int n) {
    while (n > 0) {
        if (n % 10 != 7 && n % 10 != 4)
            return 0;
        n /= 10;
    }
    return 1;
}

vector<pii> graph[100100];
int cnt[100100];
int subtree[100100];
int up[100100];
int lft[100100];
int rgt[100100];
ll ans;
int n;

void root(int u, int p = -1) {
    subtree[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        if (v == p)
            graph[u].erase(graph[u].begin() + i);
    }
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        root(v, u);
        subtree[u] += subtree[v];
    }
}

void dfs1(int u) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second;
        dfs1(v);
        if (w == 1)
            cnt[u] += subtree[v];
        else
            cnt[u] += cnt[v];
    }
}

void dfs2(int u) {
    ll total = cnt[u] + up[u];
    ans += (total * (total - 1));
    if (graph[u].empty()) return;

    for (int i = 1; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second;
        int prv = graph[u][i - 1].first, prvw = graph[u][i - 1].second;
        if (prvw == 0)
            lft[v] = lft[prv] + cnt[prv];
        else
            lft[v] = lft[prv] + subtree[prv];
    }

    for (int i = graph[u].size() - 2; i >= 0; i--) {
        int v = graph[u][i].first, w = graph[u][i].second;
        int nxt = graph[u][i + 1].first, nxtw = graph[u][i + 1].second;
        if (nxtw == 0)
            rgt[v] = rgt[nxt] + cnt[nxt];
        else
            rgt[v] = rgt[nxt] + subtree[nxt];
    }

    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second;
        if (w == 1)
            up[v] = n - subtree[v];
        else
            up[v] = up[u] + lft[v] + rgt[v];
        dfs2(v);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        w = lucky(w);
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    root(1);
    dfs1(1);
    dfs2(1);
    printf("%lld\n", ans);
    return 0;
}
