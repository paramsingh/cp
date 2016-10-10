#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct op {
    int l, r, val;
} operations[100100];

ll tree[2][500100];
ll lazy[2][500100];

int n, m, k;
ll a[100100];

void build(ll* tree, int i = 1, int cl = 1, int cr = 100100) {
    if (cl == cr) {
        tree[i] = a[cl];
    }
    else {
        int mid = (cl + cr) / 2;
        build(tree, 2*i, cl, mid);
        build(tree, 2*i+1, mid + 1, cr);
    }
}

inline void propagate(ll* tree, ll* lazy, int i, int cl, int cr) {
    if (lazy[i] != 0) {
        if (cl == cr)
            tree[i] += lazy[i];
        else {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(ll* tree, ll* lazy, int l, int r, ll val, int i = 1, int cl = 1, int cr = 100100) {
    propagate(tree, lazy, i, cl, cr);
    if (cl > r || cr < l)
        return;
    else if (l <= cl && cr <= r) {
        if (cl == cr)
            tree[i] += val;
        if (cl != cr) {
            lazy[2*i] += val;
            lazy[2*i+1] += val;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(tree, lazy, l, r, val, 2*i, cl, mid);
        update(tree, lazy, l, r, val, 2*i+1, mid+1, cr);
    }
}

ll get(ll* tree, ll* lazy, int x, int i = 1, int cl = 1, int cr = 100100) {
    propagate(tree, lazy, i, cl, cr);
    if (cl == cr)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        if (x <= mid)
            return get(tree, lazy, x, 2*i, cl, mid);
        else
            return get(tree, lazy, x, 2*i+1, mid + 1, cr);
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a+i);
    build(tree[1]);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &operations[i].l, &operations[i].r, &operations[i].val);
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        update(tree[0], lazy[0], x, y, 1);
    }
    for (int i = 1; i <= m; i++) {
        ll times = get(tree[0], lazy[0], i);
        update(tree[1], lazy[1], operations[i].l, operations[i].r, times * operations[i].val);
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", get(tree[1], lazy[1], i));
    return 0;
}
