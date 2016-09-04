#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int fact[10010];
ll power(int n, int a) {
    if (n == 1 || a == 0)
        return 1;
    if (a == 1)
        return n % mod;
    int half = power(n, a / 2);
    int sq = ((ll)half * half) % mod;
    if (a % 2 == 0)
        return sq;
    else
        return ((ll)sq * (n % mod)) % mod;
}

int inv(int n) {
    return power(n, mod - 2);
}

int choose(int n, int r) {
    if (n < r)
        return 0;
    int ans = fact[n];
    ans = ((ll)ans * inv(fact[r])) % mod;
    ans = ((ll)ans * inv(fact[n - r])) % mod;
    return ans;
}

ll a[10010];

int main(void) {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 10000; i++)
        fact[i] = ((ll)fact[i-1] * i) % mod;
    int t, cnt = 0;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int val = ((a[i] % mod) * (ll)choose(i, k - 1)) % mod;
            ans = (ans + val) % mod;
        }
        printf("Case #%d: %lld\n", ++cnt, ans);
    }
    return 0;
}
