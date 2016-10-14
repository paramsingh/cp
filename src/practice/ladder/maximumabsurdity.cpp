#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

struct rng {
    int l;
    ll sum;
    rng(int a, ll s) {
        l = a, sum = s;
    }
    bool operator< (const rng& a) const {
        if (sum == a.sum)
            return l < a.l;
        return sum > a.sum;
    }
};

set<rng> mp;
ll a[200100];
ll pref[200100];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
        pref[i] = pref[i - 1] + a[i];
    }
    for (int i = k + 1; i + k - 1 <= n; i++) {
        ll s = pref[i + k - 1] - pref[i - 1];
        mp.insert(rng(i, s));
    }
    ll ans = -inf;
    int aid = -1, bid = -1;
    if (ans < (*mp.begin()).sum + pref[k]) {
        ans = (*mp.begin()).sum + pref[k];
        aid = 1; bid = (*mp.begin()).l;
    }
    for (int a = 2; a + k - 1 <= n; a++) {
        int toremove = a + k - 1;
        if (toremove > n || toremove + k - 1 > n)
            break;
        ll s = pref[toremove + k - 1] - pref[toremove - 1];
        ll cur = pref[a + k - 1] - pref[a - 1];
        //printf("erase %d\n", toremove);
        mp.erase(rng(toremove, s));
        if (mp.empty())
            break;
        if (ans < (*mp.begin()).sum + cur) {
            ans = (*mp.begin()).sum + cur;
            aid = a; bid = (*mp.begin()).l;
        }
    }
    printf("%d %d\n", aid, bid);
    return 0;
}
