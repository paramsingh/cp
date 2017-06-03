#include <bits/stdc++.h>
using namespace std;
const int inf = 1e8;


int a[5010];
int f[5010], e[5010];
int done[5010];
int dp[5010];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int num = 0; num <= 5000; num++) {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == num) {
                e[num] = i;
                if (flag == 0) f[num] = i, flag = 1;
            }
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int mn = f[a[i]], mx = e[a[i]];
        int cnt = 0;
        int val = 0;
        memset(done, 0, sizeof(done));
        dp[i] = dp[i - 1];
        for (int j = i; j >= 1; j--) {
            mn = min(mn, f[a[j]]);
            mx = max(mx, e[a[j]]);
            if (!done[a[j]]) {
                val ^= a[j];
                done[a[j]] = 1;
            }
            if (j <= mn && mx <= i)
                dp[i] = max(dp[i], dp[j - 1] + val);
        }
    }
    printf("%d\n", dp[n]);
}
