#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int dp[5010][5010];
int pref[5010][5010];

int main(void) {
    int n, a, b, k;
    scanf("%d %d %d %d", &n, &a, &b, &k);
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
        pref[0][i] = (dp[0][i] + pref[0][i - 1]) % mod;
    }
    for (int ride = 1; ride <= k; ride++) {
        for (int i = 1; i <= n; i++) {
            int dist = abs(b - i);
            int l = max(1, i - dist + 1);
            int r = min(n, i + dist - 1);
            dp[ride][i] = (pref[ride - 1][r] - pref[ride - 1][l - 1]) % mod;
            dp[ride][i] = (dp[ride][i] - dp[ride - 1][i]) % mod;
            if (dp[ride][i] < 0)
                dp[ride][i] = (dp[ride][i] + mod) % mod;
            pref[ride][i] = (pref[ride][i - 1] + dp[ride][i]) % mod;
        }
    }
    printf("%d\n", dp[k][a]);
}
