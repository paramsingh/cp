#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
const double INF = ((long long)1) << 62;
struct line {
    lli m, c;
    mutable double left;
    line(lli a, lli b) {
        m = a, c = b;
        left = 0;
    }
    bool operator<(const line& a) const {
        if (m == a.m)
            return c < a.c;
        return m < a.m;
    }
};

struct query {
    lli m, c;
    double left;
    query(lli a, lli b, double x) {
        m = a, c = b;
        left = x;
    }
    bool operator<(const query& a) const {
        return left < a.left;
    }
};

struct ConvexHullDynamic {
    set<line> hull;
    set<query> q;
    typedef set<line>::iterator idl;
    typedef set<query>::iterator idq;

    int bad(idl y) {
        idl x, z;
        if (hull.size() == 1)
            return 0;
        else if (y == hull.begin()) {
            z = next(y);
            if (next(z) == hull.end())
                return y->m == z->m && y->c < z->c;
            else return 0;
        }
        else if (next(y) == hull.end()) {
            x = prev(y);
            if (x == hull.begin())
                return y->m == x->m && y->c < x->c;
            else
                return 0;
        }
        else {
            x = prev(y);
            z = next(y);
            return (z->c - x->c) * (y->m - x->m) > (x->m - z->m) * (x->c - y->c);
        }
    }

    void setleft(idl y) {
        lli m = y->m, c = y->c; double l = y->left;
        if (y == hull.begin())
            y->left = -INF;
        else {
            idl x = prev(y);
            y->left = (x->c - y->c) / (double) (y->m - x->m);
        }
    }

    void insert(lli m, lli c) {
        idl y = hull.insert(line(m, c)).first;
        if (next(y) != hull.end()) {
            idl z = next(y);
            if (z->m == y->m) {
                hull.erase(y);
                return;
            }
        }
        if (y != hull.begin()) {
            idl x = prev(y);
            if (x->m == y->m) {
                q.erase(query(x->m, x->c, x->left));
                hull.erase(x);
            }
        }
        setleft(y);
        idq yq = q.insert(query(m, c, y->left)).first;
        if (bad(y)) {
            hull.erase(y);
            q.erase(yq);
            return;
        }

        while (next(y) != hull.end() && bad(next(y))) {
            idl z = next(y);
            q.erase(query(z->m, z->c, z->left));
            hull.erase(z);
        }
        if (next(y) != hull.end()) {
            idl z = next(y);
            double pl = z -> left;
            setleft(z);
            q.erase(query(z->m, z->c, pl));
            q.insert(query(z->m, z->c, z->left));
        }
        while (y != hull.begin() && bad(prev(y))) {
            idl x = prev(y);
            q.erase(query(x->m, x->c, x->left));
            hull.erase(x);
        }
        double pl = y->left;
        setleft(y);
        q.erase(query(m, c, pl));
        q.insert(query(m, c, y->left));
    }

    void print() {
        printf("printing hull\n");
        for (idl it = hull.begin(); it != hull.end(); it++)
            printf("%lld %lld %lf\n", it->m, it->c, it->left);
        printf("----------------------------------\n");
        for (idq it = q.begin(); it != q.end(); it++)
            printf("%lld %lld %lf\n", it->m, it->c, it->left);
        printf("end\n\n");
    }

    lli find(lli x) {
        idq a = q.lower_bound(query(0, 0, x));
        a = std::prev(a);
        return a->m * x + a->c;
    }
};

lli a[1000100];
lli d[1000100];
lli dp[1000100];

int main(void) {
    ConvexHullDynamic chd;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld %lld", a+i, d+i);
    dp[1] = a[1];
    chd.insert(-d[1], dp[1] + d[1]);
    for (int i = 2; i <= n + 1; i++) {
        dp[i] = chd.find(i) + a[i];
        if (i <= n)
            dp[i] = max(dp[i], a[i]);
        chd.insert(-d[i], dp[i] + i * (long long)d[i]);
    }
    printf("%lld\n", dp[n + 1]);
    return 0;
}

