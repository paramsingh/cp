#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a>b?a:b

int main(void) {
    int t, i, j;
    scanf("%d", &t);
    while (t--) {
        int k, m;
        scanf("%d %d", &k, &m);
        int* val = (int *) calloc(m, 4);
        int* wts = (int *) calloc(m, 4);
        int **dp = (int **) calloc(m + 1, sizeof(int*));
        for (i = 0; i < m; i++)
            scanf("%d %d", wts+i, val+i);
        for (i = 0; i <= m; i++)
            dp[i] = (int *) calloc(k+1, sizeof(int));
        for (i = 1; i <= m; i++) {
            for (j = 0; j <= k; j++) {
                if (j >= wts[i-1]) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-wts[i-1]] + val[i-1]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        printf("Hey stupid robber, you can get %d.\n", dp[m][k]);
    }
}
