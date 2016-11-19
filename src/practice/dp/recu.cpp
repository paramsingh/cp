#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int fact[100];
int id[100];
int sieve[100];
int n, mx;
int a[101];
int dp[110][(1 << 17) + 100];
int best[110][(1 << 17) + 100];
int lim;

int solve(int i, int mask) {
    if (i == n + 1)
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    dp[i][mask] = inf;
    for (int use = 1; use <= lim; use++) {
        if (fact[use] & mask) continue;
        int x = solve(i + 1, mask | fact[use]) + abs(a[i] - use);
        if (dp[i][mask] > x) {
            dp[i][mask] = x;
            best[i][mask] = use;
        }
    }
    return dp[i][mask];
}

int main(void) {
    int cnt = 0;
    for (int i = 2; i <= 60; i++) {
        if (sieve[i] == 0) {
            id[i] = cnt++;
            for (int j = i; j <= 60; j += i) {
                fact[j] |= (1 << id[i]);
                sieve[j] = 1;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    lim = mx << 1;
    solve(1, 0);
    int now = 1, mask = 0;
    while (now <= n) {
        printf("%d ", best[now][mask]);
        mask |= fact[best[now][mask]];
        now++;
    }
    printf("\n");
}
