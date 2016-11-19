#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m; ll k;

ll get(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += min((ll)m, x / i);
    return cnt;
}

int main(void) {
    scanf("%d %d %lld", &n, &m, &k);
    ll lo = 1, hi = (ll)n * m;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (get(mid) >= k)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%lld\n", lo);
}
