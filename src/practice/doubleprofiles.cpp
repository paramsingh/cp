// http://codeforces.com/contest/154/problem/C

#include <bits/stdc++.h>
#define MAX 1000100
#define MOD 1000000007
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
typedef long long int lli;
typedef unsigned long long llu;

lli powers[MAX];
vector<pii> edges;
llu hashes[MAX] = {0};
llu ts[MAX] = {0};

int main(void) {
    powers[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        powers[i] = (powers[i-1] * (llu)41);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        hashes[u] = (hashes[u] + powers[v]);
        hashes[v] = (hashes[v] + powers[u]);
        ts[u-1] = hashes[u];
        ts[v-1] = hashes[v];
        edges.pb(mp(u, v));
    }
    sort(ts, ts+n);
    int cur = 0;
    lli ans = 0;
    for (int i = 1; i < n; i++) {
        if (ts[i] != ts[cur]) {
            lli n = i - cur;
            ans += n * (n - 1) / 2;
            cur = i;
        }
    }
    lli a = n - cur;
    ans += a * (a - 1) / 2;
    for (int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        llu hu = (hashes[u] + powers[u]) % MOD;
        llu hv = (hashes[v] + powers[v]) % MOD;
        if (hu == hv)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
