#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[101][1 << 19];
int m, d;
int digit[30];
ll fact[22];
int freq[30];

ll solve(int mask, int mod) {
    if (mask == ((1 << d) - 1))
        return mod == 0;
    if (dp[mod][mask] != -1)
        return dp[mod][mask];
    ll ans = 0;
    for (int i = 0; i < d; i++) {
        if (mask & (1 << i)) continue;
        if (digit[i] == 0) {
            if (mask)
                ans += solve(mask | (1 << i), (mod * 10) % m);
        }
        else
            ans += solve(mask | (1 << i), (mod * 10 + digit[i]) % m);
    }
    return dp[mod][mask] = ans;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    ll n;
    fact[0] = 1;
    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    scanf("%lld %d", &n, &m);
    while (n > 0) {
        digit[d++] = n % 10;
        freq[n % 10]++;
        n /= 10;
    }
    ll ans = solve(0, 0);
    for (int i = 0; i < 10; i++)
        ans /= fact[freq[i]];
    printf("%lld\n", ans);
}
