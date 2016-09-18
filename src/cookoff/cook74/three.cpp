#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int mod = 1e9 + 7;

char s[100100];
int l;
ll dp[3][3][100100];
ll solve(int big, int req, int x) {
    if (x == l) {
        if (big == 0)
            return 0;
        if (big == 1) {
            if (req == 1)
                return 0;
            else
                return 1;
        }
    }

    if (dp[big][req][x] != -1)
        return dp[big][req][x];

    ll ans = 0;
    if (big == 1) {
        for (char ch = 'A'; ch < s[x]; ch++)
            ans = (ans + solve(1, 1, x + 1)) % mod;
        ans = (ans + solve(1, req, x + 1)) % mod;
        for (char ch = s[x] + 1; ch <= 'Z'; ch++)
            ans = (ans + solve(1, 0, x + 1)) % mod;
    }
    else {
        for (char ch = s[x]; ch <= 'Z'; ch++) {
            if (ch == s[x])
                ans = (ans + solve(0, 0, x + 1)) % mod;
            else
                ans = (ans + solve(1, 0, x + 1)) % mod;
        }
    }

    return dp[big][req][x] = ans;

}

int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%s", s);
    l = strlen(s);
    printf("%lld\n", solve(0, 0, 0));
    return 0;
}
