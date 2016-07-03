#include <stdio.h>
#define min(a, b) a<b?a:b

int main(void) {
    int a[80][80];
    int dp[80][80];
    int i, j;
    for (i = 0; i < 80; i++)
        for (j = 0; j < 80; j++)
            scanf("%d", &a[i][j]);
    for (i = 79; i >= 0; i--) {
        if (i == 79)
            dp[79][i] = a[79][i];
        else
            dp[79][i] = dp[79][i+1] + a[79][i];
    }
    for (i = 78; i >= 0; i--) {
        for (j = 79; j >= 0; j--) {
            if (j == 79)
                dp[i][j] = a[i][j] + dp[i+1][j];
            else
                dp[i][j] = a[i][j] + (min(dp[i+1][j], dp[i][j+1]));
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}
