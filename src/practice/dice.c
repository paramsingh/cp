#include <stdio.h>
#include <stdlib.h>

double dp[1010][6010]; // dp(n, k) is the probability that we get sum k after n throws
int main(void) {
    int i, j;
    for (i = 0; i <= 1000; i++) {
        for (j = 0; j <= 6000; j++) {
            dp[i][j] = -1;
        }
    }
    // dp(1, k) = 100 / 6 for 1 <= k <= 6 and 0 for the rest
    for (i = 1; i <= 6; i++)
        dp[1][i] = 100 / 6.0;
    for (i = 7; i <= 6000; i++)
        dp[1][i] = 0;
    for (i = 0; i <= 6000; i++)
        dp[0][i] = 0;
    for (i = 0; i <= 1000; i++)
        dp[i][0] = 0;

    for (i = 2; i <= 1000; i++) {
        for (j = 1; j <= 6000; j++) {
            if (j < i || j > 6 * i) {
                dp[i][j] = 0;
            }
            else {
                double sum = 0;
                int k;
                for (k = 1; k <= 6; k++) {
                    if (j - k < 0)
                        break;
                    sum += dp[i-1][j-k];
                }
                sum = sum / 6.0;
                dp[i][j] = sum;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        if (n <= 1000)
            printf("%d\n", (int)dp[n][k]);
        else
            printf("0\n");
    }
    return 0;
}

