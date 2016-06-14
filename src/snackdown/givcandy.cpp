#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli gcd(lli a, lli b) {
    while (b != 0) {
        lli t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        lli a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        lli g = gcd(c, d);
        lli right = b - a;
        lli rem = right % g;
        if (rem < 0)
            rem += g;
        lli ans = min(rem, g - rem);
        printf("%lld\n", ans);
    }
}


