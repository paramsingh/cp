#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const double INF = 1e18;

struct line {
    int type;
    lli m, c;
    mutable long double left;
    long double l;
    line(int t, lli a, lli b, long double x) {
        type = t;
        m = a, c = b;
        l = left = x;
    }
    bool operator<(const line& a) const {
        if (type == 0) {
            if (m == a.m)
                return c < a.c;
            return m > a.m;
        }
        else
            return l < a.l;
    }
};

struct ConvexHullDynamic {
    set<line> hull;
    set<line> queries;
    typedef set<line>::iterator lit;

    int bad(lit y) {
        if (hull.size() <= 2)
            return 0;
        else if (y == hull.begin() || next(y) == hull.end())
            return 0;
        else {
            lit x = prev(y), z = next(y);
            return (y->c - x->c) * (x->m - z->m) >= (z->c - x->c) * (x->m - y->m);
        }
    }

    long double setleft(lit y) {
        if (y == hull.begin())
            return y->left = -INF;
        else {
            lit x = prev(y);
            y->left = (x->c - y->c) / (long double) (y->m - x->m);
            return y->left;
        }
    }

    void insert(lli m, lli c) {
        lit y = hull.insert(line(0, m, c, 0.0)).first;
        lit x, z;

        if (y != hull.begin()) {
            x = prev(y);
            if (x->m == y->m) {
                hull.erase(y);
                return;
            }
        }

        if (next(y) != hull.end()) {
            z = next(y);
            if (z->m == y->m) {
                queries.erase(line(1, z->m, z->c, z->left));
                hull.erase(z);
            }
        }

        if (bad(y)) {
            hull.erase(y);
            return;
        }

        while (next(y) != hull.end() && bad(next(y))) {
            z = next(y);
            queries.erase(line(1, z->m, z->c, z->left));
            hull.erase(z);
        }

        if (next(y) != hull.end()) {
            z = next(y);
            long double pl = z->left;
            long double l = setleft(z);
            queries.erase(line(1, z->m, z->c, pl));
            queries.insert(line(1, z->m, z->c, l));
        }

        while (y != hull.begin() && bad(prev(y))) {
            x = prev(y);
            queries.erase(line(1, x->m, x->c, x->left));
            hull.erase(x);
        }

        long double l = setleft(y);
        queries.insert(line(1, m, c, l));
    }

    lli find(lli x) {
        if (queries.empty())
            return LLONG_MAX;
        lit y = queries.upper_bound(line(1, 0, 0, x));
        y = prev(y);
        return (y->m * x) + y->c;
    }
};

ConvexHullDynamic tree[600000 * 4];

int p[500100];
int a[500100];
int h[500100];
pair<int, int> ord[500100];
lli dp[500100];
int n;


void update(int l, lli m, lli c, int id = 1, int cl = 1, int cr = n) {
    tree[id].insert(m, c);
    if (cl < cr) {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update(l, m, c, 2*id, cl, mid);
        else
            update(l, m, c, 2*id +1, mid + 1, cr);
    }
}

lli query(int l, int r, lli x, int id = 1, int cl = 1, int cr = n) {
    if (cl > r || cr < l)
        return LLONG_MAX;
    else if (cl >= l && cr <= r) {
        lli val = tree[id].find(x);
        return val;
    }
    else {
        int mid = (cl + cr) / 2;
        lli left = query(l, r, x, 2*id, cl, mid);
        lli right = query(l, r, x, 2*id + 1, mid + 1, cr);
        return min(left, right);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p+i);
        ord[i] = make_pair(p[i], i);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int i = 1; i <= n; i++)
        scanf("%d", h+i);

    sort(ord + 1, ord + n + 1);
    dp[1] = a[1];
    update(1, -2 * h[1], dp[1] + h[1] * (long long)h[1]);
    for (int i = 2; i <= n; i++) {
        int x = ord[i].first, r = ord[i].second;
        dp[r] = query(1, r - 1, h[r]) + a[r] + h[r] * (long long) h[r];
        update(r, -2 * h[r], dp[r] + h[r] * (long long) h[r]);
    }
    printf("%lld\n", dp[n]);
    return 0;
}
