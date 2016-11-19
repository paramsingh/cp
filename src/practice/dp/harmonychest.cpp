#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int dp[110][(1 << 17) + 100];
int best[110][(1 << 17) + 100];
int a[110];
int fact[110];
int id[110], sieve[110];

int main(void) {
    int cnt = 0;
    for (int i = 2; i <= 60; i++) {
        if (sieve[i] == 0) {
            id[i] = cnt++;
            for (int j = i; j <= 60; j += i) {
                sieve[j] = 1;
                fact[j] |= (1 << id[i]);
            }
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << 17); j++)
            dp[i][j] = inf;
    for (int i = n; i >= 1; i--) {
        for (int use = 1; use <= 60; use++) {
            int m = (~fact[use]) & ((1 << 17) - 1);
            for (int s = m; ;s = (s - 1) & m) {
                if (dp[i][s] > dp[i + 1][s | fact[use]] + abs(a[i] - use)) {
                    dp[i][s] = dp[i + 1][s | fact[use]] + abs(a[i] - use);
                    best[i][s] = use;
                }
                if (s == 0) break;
            }
        }
    }
    int now = 1, mask = 0;
    while (now <= n) {
        printf("%d ", best[now][mask]);
        mask |= fact[best[now][mask]];
        now++;
    }
    printf("\n");
}
