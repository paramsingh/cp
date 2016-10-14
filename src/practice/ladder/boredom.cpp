#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100100];
ll freq[100100];

ll solve(int x) {
    if (x <= 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    ll ans = max(solve(x - 1), freq[x] * x + solve(x - 2));
    return dp[x] = ans;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        freq[x]++;
    }
    printf("%lld\n", solve(100000));
    return 0;
}
