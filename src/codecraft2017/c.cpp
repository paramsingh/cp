#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const int mod = 1e9 + 7;
const ull p1 = 1e5 + 7;
const ull p2 = 1e5 + 3;

ull pow1[100100], pow2[100100];
ull h1[1001000], h2[1000100];
map<int, int> freq[100010];
ll fact[1001000];


int main(void) {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        pow1[i] = pow1[i - 1] * p1;
        pow2[i] = pow2[i - 1] * p2;
    }
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1e6; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    int n, m, x, type;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= x; j++) {
            scanf("%d", &type);
            freq[i][type]++;
        }
        for (map<int, int>::iterator it = freq[i].begin(); it != freq[i].end(); it++) {
            type = it->first;
            int f = it->second;
            h1[type] = h1[type] + f * pow1[i];
            h2[type] = h2[type] + f * pow2[i];
        }
    }
    vector<pair<ull, ull> > v;
    for (int i = 1; i <= m; i++)
        v.push_back(make_pair(h1[i], h2[i]));
    sort(v.begin(), v.end());
    ll ans = 1;
    for (int i = 0; i < v.size();) {
        ull one = v[i].first, two = v[i].second;
        int cnt = 0;
        while (i < v.size() && v[i].first == one && v[i].second == two) {
            cnt++; i++;
        }
        ans = (ans * fact[cnt]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
