// http://www.spoj.com/problems/AMR11A/
// dp(x, y) = minimum strength required to reach destination from x, y without strength
// dropping to 0 or less at any point.
// Base case: dp(r, c) = 1
// Recurrence: dp(x, y) = min(dp(x + 1, y), dp(x, y + 1)) - val[x][y]
//              if dp(x, y) comes to be <= 0 from the recurrence, dp(x, y) = 1

#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int dp[600][600];
int r, c;
int val[600][600];

int ans(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == r && j == c)
        return dp[i][j] = 1;
    if (i > r || j > c)
        return dp[i][j] = INF;
    int down = ans(i + 1, j);
    int left = ans(i, j + 1);
    int sol = min(down, left) - val[i][j];
    if (sol <= 0)
        sol = 1;
    return dp[i][j] = sol;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 600; i++)
            for (int j = 0; j < 600; j++)
                dp[i][j] = -1;
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%d", &val[i][j]);
        int sol = ans(1, 1);
        printf("%d\n", sol);
    }
    return 0;
}
