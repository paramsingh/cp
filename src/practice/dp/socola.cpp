#include <bits/stdc++.h>
using namespace std;
const int MAX = 16;

int dp[110][1 << MAX];
int a[20];
int sum[1 << MAX];

int solve(int width, int mask) {
    if (dp[width][mask] != -1) return dp[width][mask];
    if (sum[mask] % width != 0) return 0;
    int h = sum[mask] / width;
    if (__builtin_popcount(mask) == 1) return 1;
    int ans = 0;
    for (int s = mask & (mask - 1); s && (ans == 0); s = (s - 1) & mask) {
        int other = s ^ mask;
        ans |= solve(width, s) && solve(width, other);
        ans |= solve(h, s) && solve(h, other);
    }
    return dp[width][mask] = ans;
}


int main(void) {
    int c = 1;
    int n;
    while (true) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        if (n == 0) break;
        int x, y;
        scanf("%d%d", &x, &y);
        int total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            total += a[i];
        }
        for (int i = 0; i < (1 << n); i++) {
            sum[i] = 0;
            for (int x = 0; x < n; x++) {
                if ((i >> x) & 1)
                    sum[i] += a[x];
            }
        }
        if (x * y != total) {
            printf("Case %d: No\n", c++);
            continue;
        }
        if (solve(x, (1 << n) - 1))
            printf("Case %d: Yes\n", c++);
        else
            printf("Case %d: No\n", c++);
    }
}
