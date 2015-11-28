#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a>b?a:b

long long int dp[10001];
long long int arr[10001];
int n;

int main(void) {
    int t;
    scanf("%d", &t);
    int c;
    for (c = 1; c <= t; c++) {
        scanf("%d", &n);
        if (n == 0) {
            printf("Case %d: 0\n", c);
            continue;
        }
        int i;
        for (i = 0; i < n; i++)
            scanf("%lld", arr+i);
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-2], arr[n-1]);
        for (i = n-3; i >= 0; i--)
            dp[i] = max(arr[i] + dp[i+2], dp[i+1]);
        printf("Case %d: %lld\n", c, dp[0]);
    }
    return 0;
}
