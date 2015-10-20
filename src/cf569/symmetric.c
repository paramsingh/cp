// Author: Param Singh <paramsingh258@gmail.com>
// Symmetric and Transitive: http://codeforces.com/contest/568/problem/B

#include <stdio.h>
#include <stdlib.h>
#define BIG 1000000007

int main(void) {
    int n;
    int i, j;
    scanf("%d", &n);
    int** dp = (int **) calloc(n+1, sizeof(int *));
    int* eq = (int *) calloc(n, sizeof(int));
    eq[0] = eq[1] = 1;
    for (i = 0; i <= n; i++) {
        dp[i] = (int *) calloc(n+1, sizeof(int));
        if (i == 1)
            dp[i][1] = 1;
        else if (i != 0) {
            for (j = 1; j <= n; j++) {
                dp[i][j] = (dp[i-1][j-1] +(((long long)(j) * dp[i-1][j]) % BIG)) % BIG;
                eq[i] = (eq[i] + dp[i][j]) % BIG;
            }
        }
    }

    int **c = (int **) calloc(n+1, sizeof(int *));
    for (i = 0; i <= n; i++) {
        c[i] = (int *) calloc(n+1, sizeof(int));
        c[i][0] = 0;
        c[i][1] = i;
        if (i == 0)
            continue;
        for (j = 2; j <= n; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % BIG;
        }
    }

    int ans = 0;
    for (i = 1; i <= n; i++) {
        int x = ((long long)(c[n][i]) * eq[n-i]) % BIG;
        ans = (ans + x) % BIG;
    }

    printf("%d\n", ans);
    return 0;
}

