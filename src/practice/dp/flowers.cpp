#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int dp[100100];
int prefix[100100];

int main(void) {
    int t, k;
    scanf("%d %d", &t, &k);
    prefix[0] = dp[0] = 1;
    for (int i = 1; i < k; i++) {
        dp[i] = 1;
        prefix[i] = (dp[i] + prefix[i-1]) % MOD;
    }
    for (int i = k; i <= 100000; i++) {
        dp[i] = (dp[i-1] + dp[i-k]) % MOD;
        prefix[i] = (dp[i] + prefix[i-1]) % MOD;
    }
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = (prefix[b] - prefix[a-1]) % MOD;
        if (ans < 0)
            ans += MOD;
        cout << ans << endl;
    }
    return 0;
}
