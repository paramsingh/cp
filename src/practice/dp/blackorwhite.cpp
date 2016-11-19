#include <bits/stdc++.h>
using namespace std;

int dp[210][210][210];
int n;
int a[210];

int ans(int at, int pb, int pw) {
    if (at == 0)
        return 0;
    if (dp[at][pb][pw] != -1)
        return dp[at][pb][pw];
    int w = 100000000;
    if (pw == n + 1 || a[at] > a[pw])
        w = ans(at - 1, pb, at);
    int b = 100000000;
    if (pb == n + 1 || a[at] < a[pb])
        b = ans(at - 1, at, pw);
    int dont = ans(at - 1, pb, pw) + 1;
    int ret = min(dont, min(w, b));
    return dp[at][pb][pw] = ret;
}

int main(void) {
    scanf("%d", &n);
    while (n != -1) {
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        printf("%d\n", ans(n, n+1, n+1));
        scanf("%d", &n);
    }
    return 0;
}
