#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

vector<int> f[2010];
vector<int> graph[2010];
int a[2010];
int cnt[2010];
int visited[2010];
int done[2010];
int mn, mx;

int dfs(int u, int p) {
    visited[u] = 1;
    cnt[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != p && done[v] == 0 && mn <= a[v] && a[v] <= mx)
            cnt[u] = (cnt[u] * ((ll)dfs(v, u) + 1)) % mod;
    }
    return cnt[u];
}

int main(void) {
    int n, d;
    scanf("%d %d", &d, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[a[i]].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for (int x = 1; x <= 2000; x++) {
        if (f[x].empty()) continue;
        memset(cnt, 0, sizeof(cnt));
        memset(done, 0, sizeof(done));
        mn = x;
        mx = x + d;
        for (int i = 0; i < f[x].size(); i++) {
            int u = f[x][i];
            ans = (ans + dfs(u, -1)) % mod;
            done[u] = 1;
        }
    }
    printf("%d\n", ans);
}
