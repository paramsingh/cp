#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[101000];
int cnt[100100];
int parent[100100];
int dp[3][100100];

int count_children(int u, int p) {
    parent[u] = p;
    cnt[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != p)
            cnt[u] += count_children(v, u);
    }
    return cnt[u];
}


int dfs(int u) {
    int odd, even, oddcnt, evencnt;
    odd = even = oddcnt = evencnt = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v == parent[u]) continue;
        if (cnt[v] % 2 == 0) {
            evencnt++;
            even += dfs(v);
        }
        else {
            oddcnt++;
            odd += dfs(v);
        }
    }

    return even + odd + evencnt;
}


int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    count_children(1, -1);
    int ans;
    if (n % 2 != 0)
        ans = -1;
    else
        ans = dfs(1);
    printf("%d\n", ans);
    return 0;
}
