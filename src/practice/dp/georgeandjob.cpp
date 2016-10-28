#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

ll dp[5001][5001];
int a[5010];
ll pref[5010];
int n, m, k;

ll sum(int l, int r) {
    return pref[r] - pref[l - 1];
}

ll solve(int here, int k) {
    if (here == n + 1) {
        if (k > 0)
            return -inf;
        else
            return 0;
    }

    if (k == 0)
        return 0;
    if (dp[here][k] != -1)
        return dp[here][k];

    ll dont = solve(here + 1, k);
    ll take = -inf;
    if (here + m - 1 <= n)
        take = solve(here + m, k - 1) + sum(here, here + m - 1);
    return dp[here][k] = max(dont, take);
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pref[i] = pref[i - 1] + a[i];
    }
    printf("%lld\n", solve(1, k));
    return 0;
}
