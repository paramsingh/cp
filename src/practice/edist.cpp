// dp(x, y) = number of operations required to convert s[:x] into t[:y]
// dp(x, 0) = x
// dp(0, y) = y
// dp(x, y) = dp(x-1, y-1) if s[x] == t[y]
// dp(x, y) = min(dp(x-1, y), dp(x, y-1), dp(x-1, y-1)) + 1
// then in the recurrence apply all possible operations

#include <bits/stdc++.h>
using namespace std;
int dp[2010][2010];
char* from;
char* to;
int lf, lt;

int ans(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];
    if (y == 0)
        return dp[x][y] = x;
    if (x == 0)
        return dp[x][y] = y;
    if (from[x-1] == to[y-1])
        return dp[x][y] = ans(x-1, y-1);
    else {
        int d = ans(x-1, y);
        int i = ans(x, y-1);
        int s = ans(x-1, y-1);
        return dp[x][y] = min(min(d, i), s) + 1;
    }
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 2010; i++)
            for (int j = 0; j < 2010; j++)
                dp[i][j] = -1;
        from = (char*) calloc(2010, sizeof(char));
        to = (char*) calloc(2010, sizeof(char));
        scanf("%s", from);
        scanf("%s", to);
        lf = strlen(from);
        lt = strlen(to);
        printf("%d\n", ans(lf, lt));
        free(from);
        free(to);
    }
    return 0;
}
