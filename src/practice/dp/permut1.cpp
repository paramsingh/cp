#include <bits/stdc++.h>
using namespace std;
long long dp[15][100];
int n;
long long ans(int x, int k) {
    if (n == 0)
        return 0;

    if (k == 0)
        return 1;

    if (dp[x][k] != -1)
        return dp[x][k];

    long long val = 0;
    for (int i = 0; i < x && k - i >= 0; i++)
        val += ans(x - 1, k - i);

    return dp[x][k] = val;

}

int main(void) {
    int d, k;
    scanf("%d", &d);
    while (d--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &n, &k);
        long long x = 0;
        printf("%lld\n", ans(n, k));
    }
    return 0;
}
