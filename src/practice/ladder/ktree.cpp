#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, k, d;
int dp[200][4];

int solve(int need, int taken) {
    if (need < 0)
        return 0;
    if (need == 0)
        return taken;
    if (dp[need][taken] != -1)
        return dp[need][taken];
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        if (i < d)
            ans = (ans + solve(need - i, taken)) % mod;
        else
            ans = (ans + solve(need - i, 1)) % mod;
    }
    return dp[need][taken] = ans;
}



int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &n, &k, &d);
    printf("%d\n", solve(n, 0));
}
