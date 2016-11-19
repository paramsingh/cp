#include <bits/stdc++.h>
using namespace std;

double dp[2][1010][1010];

double solve(int princess, int white, int black) {
    if (white == 0 && black == 0)
        return 0;
    if (white == 0)
        return princess ^ 1;
    if (black == 0)
        return princess;
    if (dp[princess][white][black] != -1)
        return dp[princess][white][black];
    if (princess) {
        double ans = white / (double) (white + black);
        ans += solve(princess ^ 1, white, black - 1) * (black / (double) (white + black));
        return dp[princess][white][black] = ans;
    }
    else {
        double ans = solve(princess ^ 1, white - 1, black - 1) * (white / (double)(white + black - 1));
        if (black > 1)
            ans += solve(princess ^ 1, white, black - 2) * ((black - 1) / (double)(white + black - 1));
        ans *= black / (double) (white + black);
        return dp[princess][white][black] = ans;
    }
}

int main(void) {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            dp[0][i][j] = dp[1][i][j] = -1;
        }
    }
    int w, b;
    scanf("%d %d", &w, &b);
    printf("%.15f\n", solve(1, w, b));
}
