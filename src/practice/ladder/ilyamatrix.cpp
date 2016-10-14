#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pref[2001000];
ll a[2001000];

int main(void) {
    int cnt;
    scanf("%d", &cnt);
    int n = 0;
    int dup = cnt;
    for (int i = 1; i <= dup; i++)
        scanf("%lld", a+i);
    sort(a + 1, a + dup + 1, greater<ll>());
    for (int i = 1; i <= dup; i++)
        pref[i] = pref[i - 1] + a[i];
    ll ans = 0;
    while (cnt > 0) {
        int req = dup / cnt;
        ans += pref[req];
        cnt /= 4;
    }
    printf("%lld\n", ans);
    return 0;
}
