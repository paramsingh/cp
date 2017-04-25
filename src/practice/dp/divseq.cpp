#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000009;

vector<int> factors[1010];
ll dp[1010][1010];
int n, k;

ll solve(int u, int prev) {
    if (dp[u][prev] != -1) return dp[u][prev];
    if (u == n) {
        return 1;
    }
    else {
        ll ans = 0;
        for (int i = 0; i < factors[prev].size(); i++)
            ans = (ans + solve(u + 1, factors[prev][i])) % mod;
        for (int x = prev + prev; x <= k; x += prev)
            ans = (ans + solve(u + 1, x)) % mod;
        return dp[u][prev] = ans;
    }
}

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        for (int x = i; x <= k; x += i)
            factors[x].push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (ans + solve(1, i)) % mod;
    printf("%lld\n", ans);
    return 0;
}
