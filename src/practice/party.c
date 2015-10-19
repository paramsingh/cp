// Author: Param Singh <paramsingh258@gmail.com>
// Party Schedule: http://www.spoj.com/problems/PARTY/
// Knapsack problem

#include <stdio.h>
#include <stdlib.h>

void knapsack(int* cost, int* fun, int w, int n) {
    int **dp   = (int **) calloc(n+1, sizeof(int*));
    int **keep = (int **) calloc(n+1, sizeof(int*));
    int i, j;
    for (i = 0; i <= n; i++) {
        dp[i] = (int *) calloc(w+1, sizeof(int));
        keep[i] = (int *) calloc(w+1, sizeof(int));
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= w; j++) {
            if ((cost[i-1] <= j) && (fun[i-1] + dp[i-1][j-cost[i-1]] > dp[i-1][j])) {
                keep[i][j] = 1;
                dp[i][j] = fun[i-1] + dp[i-1][j-cost[i-1]];
            }
            else {
                keep[i][j] = 0;
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int k = dp[n][w];
    int net;
    for (i = 0; i <= w; i++) {
        if (dp[n][i] == k) {
            net = i;
            break;
        }
    }

    printf("%d %d\n", net, dp[n][w]);
}

int main(void) {
    int w, n;
    while (scanf("%d%d", &w, &n) != EOF) {
        if (w == 0 && n == 0)
            break;
        int i;
        int *fun = (int *) calloc(n, sizeof(int));
        int *cost = (int *) calloc(n, sizeof(int));
        for (i = 0; i < n; i++)
            scanf("%d%d", cost+i, fun+i);
        knapsack(cost, fun, w, n);
    }
    return 0;
}
