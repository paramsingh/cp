#include <bits/stdc++.h>

int dp[2100][2100];
int n;
int a[2100];

int ans(int l, int r) {
    int day = n - (r - l + 1) + 1;
    if (dp[l][r] != -1)
        return dp[l][r];
    else if (l == r) {
        return dp[l][r] = day * a[l];
    }
    else {
        int sol = std::max(ans(l+1, r) + day * a[l], ans(l, r-1) + day * a[r]);
        return dp[l][r] = sol;
    }
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    printf("%d\n", ans(1, n));
    return 0;
}

