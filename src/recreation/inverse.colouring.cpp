#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;

int n, area;
int dp[2][510][510];
int cnt[510];
int pr[510];

int main(void) {
    scanf("%d %d", &n, &area);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        memset(dp[(i + 1) %2], 0, sizeof(dp[(i + 1) % 2]));
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                dp[(i + 1)%2][j + 1][max(k, j + 1)] += dp[i%2][j][k];
                dp[(i + 1)%2][j + 1][max(k, j + 1)] %= mod;

                dp[(i + 1)%2][1][max(k, 1)] += dp[i%2][j][k];
                dp[(i + 1)%2][1][max(k, 1)] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt[i] = (cnt[i] + dp[n%2][j][i]) % mod;
        }
    }

    for (int i = 0; i <= n; i++) {
        pr[i + 1] = (pr[i + 1] + pr[i]) % mod;
        pr[i + 1] = (pr[i + 1] + cnt[i]) % mod;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a = i, b = (area - 1) / i;
        ll x = ((ll)cnt[i] * pr[min(n + 1, b + 1)]) % mod;
        ans = (ans + x) % mod;
    }
    printf("%lld\n", (ans * (ll)(mod + 1) / 2) % mod);
    return 0;
}
