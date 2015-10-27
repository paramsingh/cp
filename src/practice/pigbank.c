// Author: Param Singh <paramsingh258@gmail.com>
// http://www.spoj.com/problems/PIGBANK/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int e, f, w;
        scanf("%d %d", &e, &f);
        w = f - e;
        int n;
        scanf("%d", &n);
        int p[n], wt[n];
        int i, j, k;
        for (i = 0; i < n; i++)
            scanf("%d %d", p+i, wt+i);
        int dp[w+1];
        for (i = 0; i <= w; i++)
            dp[i] = -1;
        dp[0] = 0;
        for (i = 1; i <= w; i++) {
            for (j = 0; j < n; j++) {
                if (wt[j] > i || dp[i-wt[j]] == -1)
                    continue;
                else {
                    if (dp[i] == -1 || p[j] + dp[i-wt[j]] < dp[i])
                        dp[i] = p[j] + dp[i-wt[j]];
                }
            }
        }

        if (dp[w] == -1)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[w]);
    }
    return 0;
}
