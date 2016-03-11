// dp(i, j) = minimum wastage in rectangle of size i * j
// dp(1, 1) = 1
// dp(i, 0) = 0
// dp(0, i) = 0
// dp(x, y) = 0 for all rectangles of size x & y
// recurrence:
// dp(x, y) = cut vertically or cut horizontally
//          = min(dp(i, y) + dp(x - i, y)) for i from 1 to w,  dp(x, i) + dp(x, y-i))

#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int w, h;

int ans(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];
    if (x == 1 && y == 1)
        return dp[x][y] = 1;
    if (x == 0 || y == 0)
        return dp[x][y] = 0;
    int mn = 1000000000;
    for (int i = 1; i < x; i++)
        mn = min(mn, ans(i, y) + ans(x - i, y));
    for (int i = 1; i < y; i++)
        mn = min(mn, ans(x, i) + ans(x, y - i));
    return dp[x][y] = mn;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                dp[i][j] = -1;
            }
        }
        scanf("%d %d", &w, &h);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            dp[x][y] = 0;
        }
        printf("%d\n", ans(w, h));
    }
}
