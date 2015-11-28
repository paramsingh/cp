#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a>b?a:b

char a[201];
int dp[201][201];

int func(int l, int r) {
    int i;
    if (dp[l][r] != -1){
        return dp[l][r];
    }
    int ans = -1;
    int c1 = 0, c0 = 0;
    for (i = l; i <= r; i++) {
        if (a[i] == '1')
            c1++;
        else
            c0++;
    }
    if (c1 > c0)
        ans = r - l + 1;
    else {
        for (i = l; i < r; i++) {
            ans = max(ans, func(l, i) + func(i+1, r));
        }
    }
    if (ans == -1)
        dp[l][r] = 0;
    else
        dp[l][r] = ans;
    return dp[l][r];
}

int main(void) {
    int t, i, j;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", a);
        for (i = 0; i < 201; i++) {
            for (j = 0; j < 201; j++) {
                dp[i][j] = -1;
            }
        }
        printf("%d\n", func(0, n-1));
    }
}
