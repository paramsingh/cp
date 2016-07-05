#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli mul(lli a, lli b, lli mod) {
    if (b == 1)
        return a % mod;
    if (b == 0)
        return 0;
    lli half = mul(a, b/2, mod);
    lli x = (half + half) % mod;
    if (b % 2 == 0)
        return x;
    else
        return (x + (a % mod)) % mod;
}


lli power(lli n, lli a, lli mod) {
    if (n == 1 || a == 0)
        return 1;
    if (a == 1)
        return n % mod;
    lli half = power(n, a / 2, mod);
    lli x = mul(half, half, mod);
    if (a % 2 == 0)
        return x;
    else
        return mul(x, n % mod, mod);
}


int fermat(lli x) {
    if (x == 2)
        return 1;
    int it = 500;
    while (it--) {
        lli a = rand() % (x - 2) + 2;
        if (power(a, x - 1, x) != 1)
            return 0;
    }
    return 1;
}

int main(void) {
    srand(time(NULL));
    int t;
    scanf("%d", &t);
    while (t--) {
        lli x;
        scanf("%lld", &x);
        if (fermat(x))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
