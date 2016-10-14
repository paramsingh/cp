#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100100];

int main(void) {
    ll n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    sort(a + 1, a + n + 1);
    ll lo = a[n], hi = 2e9;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += mid - a[i];
        if (cnt >= mid)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%lld\n", lo);
    return 0;
}
