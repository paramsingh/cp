#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long fpow(int n, long long a) {
    if (n == 1)
        return 1;
    if (a == 0)
        return 1;
    if (a == 1)
        return n;
    long long half = fpow(n, a / 2);
    if (a % 2 == 0)
        return (half * (long long) half) % MOD;
    else {
        int x = (half * (long long) half) % MOD;
        return (x * (long long) n) % MOD;
    }
}

long long inverse(int n) {
    return fpow(n, MOD - 2);
}

int main(void) {
    int a, b, x;
    long long n;
    scanf("%d %d %lld %d", &a, &b, &n, &x);
    if (a > 1) {
        long long an = fpow(a, n);
        long long c = (an - 1) % MOD;
        c = (c * (long long) b) % MOD;
        c = (c * (long long) inverse(a - 1)) % MOD;
        long long v = an;
        v = (v * (long long) x) % MOD;
        long long ans = (v + c) % MOD;
        if (ans < 0)
            ans += MOD;
        printf("%lld\n", ans);
    }
    else {
        long long ans = x;
        long long c = ((n % MOD) * (long long) b) % MOD;
        ans = (ans + c) % MOD;
        if (ans < 0)
            ans += MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
