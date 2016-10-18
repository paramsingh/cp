#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;

ll dp[200100];
ll pref[200100];
ll a[200100];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
        pref[i] = pref[i - 1] + a[i];
    }
    // base case
    dp[n] = 0;
    // general
    // dp[i] = max(pref[i + 1] - dp[i + 1], pref[i + 2] - dp[i + 2] .. )
    ll mx = pref[n];
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = mx;
        mx = max(mx, pref[i] - dp[i]);
    }
    printf("%lld\n", dp[1]);
    return 0;
}
