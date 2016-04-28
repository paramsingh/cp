#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli dp[100100];
int a[100100];
int n;

lli ans(int i) {
    if (dp[i] != -1)
        return dp[i];

    if (i > n)
        return 0;

    lli sol = 0;
    int cnt = 0;
    for (int take = 1; (take <= 3) && ((i + take - 1) <= n); take++) {
        lli calc = 0;
        for (int j = 0; j < take; j++)
            calc += a[j+i];
        if (i + take + take <= n)
            calc += ans(i+take+take);
        if (sol < calc) {
            cnt = take;
            sol = calc;
        }
    }
    return dp[i] = sol;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        printf("%lld\n", ans(1));
    }
    return 0;
}
