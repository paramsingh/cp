#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const ll mod = 1e9 + 7;
int n, m;

struct mat {
    ll a[2][2];
    mat& operator* (const mat& other) {
        mat p;
        p.a[0][0] = ((a[0][0] * other.a[0][0]) % mod + (a[0][1] * other.a[1][0]) % mod) % mod;
        p.a[0][1] = ((a[0][0] * other.a[0][1]) % mod + (a[0][1] * other.a[1][1]) % mod) % mod;
        p.a[1][0] = ((a[1][0] * other.a[0][0]) % mod + (a[1][1] * other.a[1][0]) % mod) % mod;
        p.a[1][1] = ((a[1][0] * other.a[0][1]) % mod + (a[1][1] * other.a[1][1]) % mod) % mod;
        return p;
    }
};

mat fib;
mat unit;

mat power(ll a) {
    mat base = fib;
    mat x = unit;
    while (a > 0) {
        if (a & 1)
            x = x * base;
        base = base * base;
        a >>= 1;
    }
    return x;
}

mat tree[500100];
ll lazy[500100];

int arr[100100];
void build(int i = 1, int l = 1, int r = n) {
    lazy[i] = 0;
    if (l == r) {
        tree[i] = power(arr[l]);
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid + 1, r);
        r = i;
        int lc = 2*r, rc = 2*r + 1;
        tree[r].a[0][0] = (tree[lc].a[0][0] + tree[rc].a[0][0]) % mod;
        tree[r].a[0][1] = (tree[lc].a[0][1] + tree[rc].a[0][1]) % mod;
        tree[r].a[1][0] = (tree[lc].a[1][0] + tree[rc].a[1][0]) % mod;
        tree[r].a[1][1] = (tree[lc].a[1][1] + tree[rc].a[1][1]) % mod;
    }
}

void update(int l, int r, ll val, int i = 1, int cl = 1, int cr = n) {
    if (lazy[i] != 0) {
        tree[i] = tree[i] * power(lazy[i]);
        if (cl != cr) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        tree[i] = tree[i] * power(val);
        if (cl != cr) {
            lazy[2*i] += val;
            lazy[2*i + 1] += val;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, val, 2*i, cl, mid);
        update(l, r, val, 2*i + 1, mid + 1, cr);
        int lc, rc;
        r = i, lc = 2*i, rc = 2*i + 1;
        tree[r].a[0][0] = (tree[lc].a[0][0] + tree[rc].a[0][0]) % mod;
        tree[r].a[0][1] = (tree[lc].a[0][1] + tree[rc].a[0][1]) % mod;
        tree[r].a[1][0] = (tree[lc].a[1][0] + tree[rc].a[1][0]) % mod;
        tree[r].a[1][1] = (tree[lc].a[1][1] + tree[rc].a[1][1]) % mod;
    }
}


ll query(int l, int r, int i = 1, int cl = 1, int cr = n) {
    if (lazy[i] != 0) {
        tree[i] = tree[i] * power(lazy[i]);
        if (cl != cr) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (cl > r || cr < l) {
        return 0;
    }
    else if (cl >= l && cr <= r) {
        return tree[i].a[0][1];
    }
    else {
        int mid = (cl + cr) / 2;
        ll left = query(l, r, 2*i, cl, mid);
        ll right = query(l, r, 2*i+1, mid + 1, cr);
        return (left + right) % mod;
    }
}



int main(void) {
    fib.a[0][0] = fib.a[0][1] = fib.a[1][0] = 1;
    fib.a[1][1] = 0;
    unit.a[0][0] = unit.a[1][1] = 1;
    unit.a[0][1] = unit.a[1][0] = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", arr+i);
    build();
    while (m--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            update(l, r, x);
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(l, r));
        }
    }
    return 0;
}
