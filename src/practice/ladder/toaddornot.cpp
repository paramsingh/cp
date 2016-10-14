#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100100];
ll pref[100100];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a+i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    int ans = -1; ll ansv;
    for (int i = 1; i <= n; ) {
        int x = a[i];
        while (i <= n && a[i] == x)
            i++;
        int last = i - 1;
        int lo = 1, hi = last;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            ll cnt = last - mid + 1;
            ll req = a[last] * cnt - (pref[last] - pref[mid - 1]);
            if (req <= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (ans < last - lo + 1) {
            ans = last - lo + 1;
            ansv = a[last];
        }
    }
    printf("%d %lld\n", ans, ansv);
}
