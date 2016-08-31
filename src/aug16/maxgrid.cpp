#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n;
struct point {
    int x, y, val;
    point(int a, int b, int v) {
        x = a, y = b;
        val = v;
    }
    bool operator< (const point& a) const {
        return x < a.x;
    }
};

vector<point> bx;

struct node {
    lli val;
    lli lazy;
} tree[400100];

inline void propagate(int i, int l, int r) {
    if (tree[i].lazy != 0) {
        tree[i].val += tree[i].lazy;
        if (l != r) {
            tree[2*i].lazy += tree[i].lazy;
            tree[2*i+1].lazy += tree[i].lazy;
        }
        tree[i].lazy = 0;
    }
}

void update(int l, int r, int up, int i = 1, int cl = 0, int cr = 100001) {
    propagate(i, cl, cr);
    if (l > cr || r < cl) {
        return;
    }
    else if (cl >= l && cr <= r) {
        tree[i].val += up;
        if (cl != cr) {
            tree[2*i].lazy += up;
            tree[2*i+1].lazy += up;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, up, 2*i, cl, mid);
        update(l, r, up, 2*i+1, mid + 1, cr);
        tree[i].val = max(tree[2*i].val, tree[2*i+1].val);
    }
}

lli find(int l) {
    for (int i = 0; i < 400100; i++)
        tree[i].val = tree[i].lazy = 0;
    int pi = 0, pj = 0;
    lli ans = -1;
    for (int x = 0; x <= 100000; x++) {
        while (pi < bx.size() && bx[pi].x < x + l) {
            update(max(bx[pi].y - l + 1, 0), bx[pi].y, bx[pi].val);
            pi++;
        }
        while (pj < bx.size() && bx[pj].x < x) {
            update(max(bx[pj].y - l + 1, 0), bx[pj].y, -bx[pj].val);
            pj++;
        }
        ans = max(ans, tree[1].val);
    }
    return ans;
}

int main(void) {
    int l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        int x, y, val;
        scanf("%d %d %d", &x, &y, &val);
        bx.push_back(point(x, y, val));
    }
    sort(bx.begin(), bx.end());
    lli ans1 = find(l);
    printf("%lld ", ans1);
    int lo = 0, hi = l;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        lli x = find(mid);
        if (x < ans1)
            lo = mid + 1;
        else
            hi = mid;
    }
    printf("%d\n", lo);
    return 0;
}

