#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int dp[4];
int dp1[4];

int main(void) {
    int n;
    scanf("%d", &n);
    dp[0] = dp[1] = dp[2] = 1;
    for (int i = 2; i <= n; i++) {
        for (int x = 0; x < 4; x++) {
            dp1[x] = 0;
            for (int from = 0; from < 4; from++) {
                if (from == x) continue;
                dp1[x] = (dp1[x] + dp[from]) % mod;
            }
        }
        for (int x = 0; x < 4; x++)
            dp[x] = dp1[x];
    }
    printf("%d\n", dp[3]);
}
