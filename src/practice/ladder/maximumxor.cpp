#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;
ll dp[70][3][3][3][3];

ll solve(int here, int l1, int r1, int l2, int r2) {
    if (here == -1)
        return 0;

    if (dp[here][l1][r1][l2][r2] != -1)
        return dp[here][l1][r1][l2][r2];

    int lbit = (l >> here) & 1;
    int rbit = (r >> here) & 1;

    ll ans = 0;
    if (lbit == 0 || l1 == 1) { // can put 0 in a
        if (lbit == 0 || l2 == 1) // can put 0 in b
            ans = max(ans, solve(here - 1, l1, r1 || (rbit == 1), l2, r2 || (rbit == 1)));
        if (rbit == 1 || r2 == 1)  // can put 1 in b
            ans = max(ans, solve(here - 1, l1, r1 || (rbit == 1), l2 || (lbit == 0), r2) | (1LL << here));
    }

    if (rbit == 1 || r1 == 1) { // can put 1 in a
        if (lbit == 0 || l2 == 1)
            ans = max(ans, solve(here - 1, l1 || (lbit == 0), r1, l2, r2 || (rbit == 1)) | (1LL << here));
        if (rbit == 1 || r2 == 1)
            ans = max(ans, solve(here - 1, l1 || (lbit == 0), r1, l2 || (lbit == 0), r2));
    }

    return dp[here][l1][r1][l2][r2] = ans;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", solve(62, 0, 0, 0, 0));
    return 0;
}
