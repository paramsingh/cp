// dp(l, start): number of numbers that can be made of length l starting with start
// dp(1, x) = 1
// dp(a, b) = dp(a-1, b) + dp(a-1, b+1) ...

#include <bits/stdc++.h>
long long int dp[100][20];

long long int calc(int l, int start) {
    if (dp[l][start] != -1)
        return dp[l][start];
    if (l == 1)
        return dp[l][start] = 1;
    long long int sol = 0;
    for (int i = start; i < 10; i++)
        sol += calc(l-1, i);
    return dp[l][start] = sol;
}

int main(void) {
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 20; j++)
            dp[i][j] = -1;
    int t;
    scanf("%d", &t);
    while (t--) {
        int no, l;
        scanf("%d %d", &no, &l);
        long long int ans = 0;
        for (int i = 0; i < 10; i++)
            ans += calc(l, i);
        printf("%d %lld\n", no, ans);
    }
    return 0;
}
