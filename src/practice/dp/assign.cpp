#include <bits/stdc++.h>

typedef long long lli;

lli dp[1100000];
int n;
int likes[30][30];

lli ans(int mask) {
    if (dp[mask] != -1)
        return dp[mask];

    int assigned = 0;
    for (int i = 0; i < n; i++)
        if ((mask >> i) & 1)
            assigned++;
    if (assigned == n)
        return 1;
    else {
        lli sol = 0;
        int student = assigned;
        for (int i = 0; i < n; i++) {
            if (likes[student][i] && ((mask >> i) & 1) == 0)
                sol += ans(mask | (1 << i));
        }
        return dp[mask] = sol;
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &likes[i][j]);
        printf("%lld\n", ans(0));
    }
    return 0;
}
