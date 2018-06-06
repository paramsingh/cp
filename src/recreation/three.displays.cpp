#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;



ll dp[5][3003];
int s[3030], c[3030];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++)
        dp[1][i] = c[i];
    for (int i = 2; i <= 3; i++) {
        for (int j = n; j >= 1; j--) {
            dp[i][j] = inf;
            for (int nxt = j  + 1; nxt <= n; nxt++)
                if (s[nxt] > s[j])
                    dp[i][j] = min(dp[i][j], c[j] + dp[i - 1][nxt]);
        }
    }
    ll ans = inf;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[3][i]);
    printf("%lld\n", ans == inf ? -1 : ans);
    return 0;
}

