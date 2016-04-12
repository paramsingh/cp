#include <bits/stdc++.h>
using namespace std;

int dp[2100][2100];
int k;
char a[2100], b[2100];

int ans(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];
    else if (x == 0)
        return dp[x][y] = k * y;
    else if (y == 0)
        return dp[x][y] = k * x;
    else {
        int sol = min(min(ans(x-1, y) + k, ans(x, y-1) + k), ans(x-1, y-1) + abs(a[x] - b[y]));
        return dp[x][y] = sol;
    }
}


int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%s", a+1);
    scanf("%s", b+1);
    scanf("%d", &k);
    int x = strlen(a+1);
    int y = strlen(b+1);
    printf("%d\n", ans(x, y));
    return 0;
}
