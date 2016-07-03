#include <stdio.h>

int main(void) {
    long long int dp[30][30];
    int i, j;
    for (i = 0; i <= 20; i++) {
        for (j = 0; j <= 20; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    printf("%lld\n", dp[20][20]);
    return 0;
}
