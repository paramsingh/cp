#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sieve[1001000];
set<ll> tprimes;

int main(void) {
    for (int i = 2; i <= 1e6; i++) {
        if (sieve[i] == 0) {
            tprimes.insert((ll)i * i);
            for (int j = i; j <= 1e6; j += i)
                sieve[j] = 1;
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        if (tprimes.count(x))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
