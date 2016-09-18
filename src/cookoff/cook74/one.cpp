#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, b, m;
        scanf("%lld %lld %lld", &n, &b, &m);
        ll cnt = 0;
        while (n > 0) {
            ll solve = n / 2;
            if (n % 2 != 0)
                solve++;
            cnt += solve * m + b;
            n /= 2;
            m *= 2;
        }
        printf("%lld\n", cnt - b);
    }
    return 0;
}
