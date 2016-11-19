#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const int mod = 1e9 + 7;

ll dp[3][100100];
vector<int> graph[100100];
int black[100100];

void dfs(int u, int p = -1) {
    dp[0][u] = 1 - black[u];
    dp[1][u] = black[u];
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != p) {
            dfs(v, u);
            ll p0 = dp[0][u], p1 = dp[1][u];
            dp[0][u] = dp[1][u] = 0;
            // dont take v
            dp[0][u] = (p0 * dp[1][v]) % mod;
            dp[1][u] = (p1 * dp[1][v]) % mod;
            // take v
            dp[1][u] += (p1 * dp[0][v]) % mod;
            dp[1][u] += (p0 * dp[1][v]) % mod;
            dp[1][u] %= mod;

            dp[0][u] += (p0 * dp[0][v]) % mod;
            dp[0][u] %= mod;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u = i, v;
        scanf("%d", &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &black[i]);
    dfs(0);
    printf("%lld\n", dp[1][0]);
    return 0;
}
