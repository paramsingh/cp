#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(a, b) a<b?a:b

struct pilot {
    int x, y;
} pilots[10005];

int dp[10005][10005];

int main(void) {
    int n;
    scanf("%d", &n);
    int i, sum = 0, j;
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &pilots[i].x, &pilots[i].y);
    }
    dp[1][0] = pilots[1].y;
    dp[1][1] = 1000000000;
    for (i = 2; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (i - j < j)
                dp[i][j] = 1000000000;
            else {
                if (j == 0)
                    dp[i][j] = dp[i-1][j] + pilots[i].y;
                else {
                    dp[i][j] = min(dp[i-1][j-1] + pilots[i].x, dp[i-1][j] + pilots[i].y);
                }
            }
        }
    }
    printf("%d\n", pilots[n].x + dp[n-1][n/2 - 1]);
    return 0;
}
