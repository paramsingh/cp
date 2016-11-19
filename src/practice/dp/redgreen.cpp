#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int dp[300100];

int main(void) {
    int r, g;
    scanf("%d %d", &r, &g);
    int total = r + g;
    int h = 0;
    while ((h * (h + 1)) / 2 <= total)
        h++;
    h--;
    dp[0] = 1;
    for (int ht = 1; ht <= h; ht++) {
        for (int use = r; use >= ht; use--) {
            dp[use] = (dp[use] + dp[use - ht]) % mod;
        }
    }
    int ans = 0;
    for (int use = max(0, (h * (h + 1) / 2) - g); use <= r; use++)
        ans = (ans + dp[use]) % mod;
    printf("%d\n", ans);
}
