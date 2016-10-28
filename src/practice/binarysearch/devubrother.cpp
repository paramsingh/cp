#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

int n, m;
int a[100100];
int b[100100];

ll f(int k) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] < k)
            cnt += k - a[i];
    for (int i = 1; i <= m; i++)
        if (b[i] > k)
            cnt += b[i] - k;
    return cnt;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    ll ans = inf;
    int lo = 0, hi = 1e9 + 1;
    for (int it = 0; it < 100; it++) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        ll f1 = f(mid1), f2 = f(mid2);
        if (f1 < ans)
            ans = f1;
        if (f2 < ans)
            ans = f2;
        if (f1 >= f2)
            lo = mid1;
        else
            hi = mid2;
    }
    printf("%lld\n", ans);
}
