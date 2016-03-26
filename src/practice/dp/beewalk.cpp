#include <bits/stdc++.h>
int dp[200][200][500];
int n;
int dx[6] = {1, 0, -1, 0, 1, -1};
int dy[6] = {0, -1, 0, 1, 1, -1};

int ans(int x, int y, int rem) {
    if (dp[x][y][rem] != -1)
        return dp[x][y][rem];
    if (x == 50 && y == 50 && rem == 0)
        return dp[x][y][rem] = 1;
    if (rem <= 0)
        return 0;
    dp[x][y][rem] = 0;
    for (int i = 0; i < 6; i++)
        dp[x][y][rem] += ans(x+dx[i], y+dy[i], rem - 1);
    return dp[x][y][rem];
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n",ans(50, 50, n));
    }
    return 0;
}

