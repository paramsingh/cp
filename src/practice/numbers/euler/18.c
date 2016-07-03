#include <stdio.h>
#define max(a, b) a>b?a:b

int main(void) {
    int a[500][500];
    int i, j;
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < i+1; j++)
            scanf("%d", &a[i][j]);
    }
    int dp[500][500];
    for (i = n-1; i >= 0; i--) {
        for (j = 0; j < i+1; j++) {
            if (i == n-1)
                dp[i][j] = a[i][j];
            else {
                int x = a[i][j];
                int y = max(dp[i+1][j], dp[i+1][j+1]);
                dp[i][j] = x + y;
            }
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}
