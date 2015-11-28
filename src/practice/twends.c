#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b

int main(void) {
    int n, i, j, x, game = 1;
    scanf("%d", &n);
    while (n != 0) {
        int* arr = (int *) calloc(1000, sizeof(int));
        int** dp = (int **) calloc(1000, sizeof(int));
        for (i = 0; i < n; i++) {
            scanf("%d", arr+i);
            dp[i] = (int *) calloc(1000, sizeof(int));
        }
        for (j = 1; j <= n/2; j++) {
            x = j * 2;
            for (i = 0; i <= n - x; i++) {
                if (x == 2) {
                    dp[i][i+1] = abs(arr[i] - arr[i+1]);
                }
                else {
                    int left = arr[i];
                    if (arr[i+1] >= arr[i+x-1]) {
                        left = left - arr[i+1];
                        left += dp[i+2][i+x-1];
                    }
                    else {
                        left -= arr[i+x-1];
                        left += dp[i+1][i+x-2];
                    }
                    int right = arr[i+x-1];
                    if (arr[i] >= arr[i+x-2]) {
                        right = right - arr[i];
                        right += dp[i+1][i+x-2];
                    }
                    else {
                        right = right - arr[i+x-2];
                        right += dp[i][i+x-3];
                    }
                    dp[i][i+x-1] = max(left, right);
                }
            }
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", game, dp[0][n-1]);
        game++;
        scanf("%d", &n);
    }
}
