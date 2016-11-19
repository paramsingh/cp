#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, w;
int a[100100];
ll req[100100];
ll tree[400100];
ll lazy[400100];

inline void propagate(int i, int cl, int cr) {
    if (lazy[i] != 0) {
        tree[i] += lazy[i];
        if (cl != cr) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int l, int r, ll val, int i = 1, int cl = 1, int cr = n) {
    propagate(i, cl, cr);
    if (cl > r || cr < l) return;
    if (l <= cl && cr <= r) {
        tree[i] += val;
        if (cl != cr) {
            lazy[2*i] += val;
            lazy[2*i+1] += val;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, val, 2*i, cl, mid);
        update(l, r, val, 2*i+1, mid+1, cr);
    }
}

ll get(int l, int i = 1, int cl = 1, int cr = n) {
    propagate(i, cl, cr);
    if (cl == cr)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid) return get(l, 2*i, cl, mid);
        else          return get(l, 2*i+1, mid+1, cr);
    }
}

int check(int h) {
    for (int i = 1; i <= n; i++) {
        req[i] = max(0, h - a[i]);
        if (req[i] > m)
            return 0;
    }
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll need = max(0ll, req[i] - get(i));
        cnt += need;
        if (need > 0)
            update(i, min(n, i + w - 1), need);
    }
    return cnt <= m;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int lo = a[1], hi = a[1];
    for (int i = 1; i <= n; i++) {
        lo = min(a[i], lo);
        hi = max(a[i], hi);
    }
    hi += m;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    printf("%d\n", lo);
}
