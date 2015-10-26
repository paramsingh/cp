#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[n];
        int i, j, k;
        for (i = 0; i < n; i++)
            scanf("%d", a+i);
        int cost[n][n];
        int result[n][n];

        // initializing base cases of dp table
        for (i = 0; i < n; i++) {
            cost[i][i] = 0;
            result[i][i] = a[i];
        }

        // filling up dp table bottom up
        for (i = 2; i <= n; i++) {
            for (j = 0; j < n - i + 1; j++) {
                int dest = j + i - 1;
                cost[j][dest] = INT_MAX;
                for (k = j; k < dest; k++) {
                    int x = cost[j][k] + cost[k+1][dest] + (result[j][k] * result[k+1][dest]);
                    int res = (result[j][k] + result[k+1][dest]) % 100;
                    if (x < cost[j][dest]) {
                        cost[j][dest] = x;
                        result[j][dest] = res;
                    }
                }
            }
        }

        printf("%d\n", cost[0][n-1]);
    }
    return 0;
}

