#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
int n, m, a;
ll b[100100], p[100100];

int check(int x) {
    ll rem = a;
    int id = x;
    for (int i = 1; i <= x; i++) {
        ll have = b[i], req = p[id];
        id--;
        if (have < req) {
            req -= have;
            if (req > rem)
                return 0;
            rem -= req;
        }
    }
    return 1;
}

ll get(int x) {
    ll req = 0;
    for (int i = 1; i <= x; i++)
        req += p[i];
    return max(0ll, req - a);
}

int main(void) {
    scanf("%d %d %d", &n, &m, &a);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]);
    sort(b + 1, b + 1 + n, greater<ll>());
    for (int i = 1; i <= m; i++)
        scanf("%lld", &p[i]);
    sort(p + 1, p + 1 + m);
    int lo = 0, hi = min(n, m);
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    printf("%d %lld\n", lo, get(lo));
    return 0;
}
