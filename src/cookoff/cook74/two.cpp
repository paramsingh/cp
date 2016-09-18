#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

ll a[100100];
ll diff[100100];
map<ll, ll> mp;
set<ll> freq;


void add(ll val) {
    if (mp.find(val) != mp.end())
        mp[val]++;
    else
        mp[val] = 1;
}

void remove(ll val) {
    mp[val]--;
    if (mp[val] == 0)
        mp.erase(val);
}

bool check() {
    return mp.size() <= 1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a+i);
        for (int i = 1; i < n; i++) {
            diff[i] = a[i+1] - a[i];
            add(diff[i]);
        }
        ll ans = inf;
        // remove middle elements
        for (int i = 2; i < n; i++) {
            ll rem1 = diff[i], rem2 = diff[i-1];
            ll ndiff = rem1 + rem2;
            remove(rem1);
            remove(rem2);
            add(ndiff);
            if (check())
                ans = min(ans, a[i]);
            add(rem1);
            add(rem2);
            remove(ndiff);
        }

        // remove first element
        remove(diff[1]);
        if (check())
            ans = min(ans, a[1]);
        add(diff[1]);
        remove(diff[n-1]);
        if (check())
            ans = min(ans, a[n]);
        if (ans == inf)
            printf("-1\n");
        else
            printf("%lld\n", ans);
        mp.clear();
        freq.clear();
    }
    return 0;
}
