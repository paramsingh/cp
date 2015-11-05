#include <stdio.h>
#include <stdlib.h>

struct dpcell {
    int up;
    int left;
};

struct cell {
    int y;
    int b;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int n, m;
    int i, j;
    scanf("%d %d", &n, &m);
    while (n != 0 && m != 0) {
        struct cell arr[n][m];
        struct dpcell dp[n][m];
        struct dpcell sums[n][m];
        int sum = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &(arr[i][j].y));
                sum += arr[i][j].y;
            }
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &(arr[i][j].b));
        for (j = 0; j < m; j++) {
            for (i = n-1; i >= 0; i--) {
                if (i == n-1)
                    sums[i][j].left = arr[i][j].b;
                else
                    sums[i][j].left = arr[i][j].b + sums[i+1][j].left;
            }
        }

        for (i = 0; i < n; i++) {
            for (j = m-1; j >= 0; j--) {
                if (j == m-1)
                    sums[i][j].up = arr[i][j].y;
                else
                    sums[i][j].up = arr[i][j].y + sums[i][j+1].up;
            }
        }

        for (j = 0; j < m; j++) {
            for (i = 0; i < n; i++) {
                if (i == 0 && j == 0) {
                    dp[i][j].up = sum;
                    dp[i][j].left = sum - sums[i][j].up + sums[i][j].left;
                }
                else if (i == 0) {
                    dp[i][j].left = dp[i][j-1].left - sums[;
                else {
                    dp[i][j].up = dp[i-1][j].up;
                    dp[i][j].left = max(dp[i-1][j].up, dp[i-1][j].left);
                }
            }
        }

        printf("%d\n", max(dp[n-1][m-1].left, dp[n-1][m-1].up));
        scanf("%d %d", &n, &m);
    }
}

