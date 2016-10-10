#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, a, b, c;
int dp[5010];

int solve(int n) {
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = -inf;
    if (a <= n)
        ans = max(ans, solve(n - a) + 1);
    if (b <= n)
        ans = max(ans, solve(n - b) + 1);
    if (c <= n)
        ans = max(ans, solve(n - c) + 1);
    return dp[n] = ans;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("%d\n", solve(n));
}
