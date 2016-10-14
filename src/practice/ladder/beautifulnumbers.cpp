#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

ll fact[1001000];

ll power(ll n, ll a) {
    if (a == 0 || n == 1)
        return 1;
    else if (a == 1)
        return n % mod;
    else {
        ll half = power(n, a / 2);
        ll sq = (half * half) % mod;
        return a % 2 == 0 ? sq : (sq * n) % mod;
    }
}

ll inv(ll n) {
    return power(n, mod - 2);
}

ll choose(int n, int r) {
    if (n < r)
        return 0;
    ll ans = fact[n];
    ans = (ans * inv(fact[r])) % mod;
    ans = (ans * inv(fact[n - r])) % mod;
    return ans;
}

int a, b, n;
int good(ll x) {
    while (x > 0) {
        int digit = x % 10;
        if (digit != a && digit != b)
            return 0;
        x /= 10;
    }
    return 1;
}

int main(void) {
    scanf("%d %d %d", &a, &b, &n);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ll sum = i * a + (n - i) * b;
        if (good(sum))
            ans = (ans + choose(n, i)) % mod;
    }
    printf("%d\n", ans);
}
