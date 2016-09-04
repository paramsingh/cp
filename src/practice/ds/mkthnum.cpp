#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> num, dis;

struct node {
    int l, r;
    int val;
} tree[5000000];

int nodes = 0;
int root[100100];
int a[100100];

void build(int n, int s = 0, int e = dis.size() - 1) {
    if (s < e) {
        int mid = (s + e) / 2;
        tree[n].l = nodes++;
        tree[n].r = nodes++;
        build(tree[n].l, s, mid);
        build(tree[n].r, mid + 1, e);
    }
}

int update(int pn, int cn, int id, int s = 0, int e = dis.size() - 1) {
    if (s == e && s == id) {
        tree[cn].val = tree[pn].val + 1;
        return cn;
    }
    else {
        int mid = (s + e) / 2;
        if (id <= mid) {
            tree[cn].l = update(tree[pn].l, nodes++, id, s, mid);
            tree[cn].r = tree[pn].r;
        }
        else {
            tree[cn].l = tree[pn].l;
            tree[cn].r = update(tree[pn].r, nodes++, id, mid + 1, e);
        }
        int lc = tree[cn].l, rc = tree[cn].r;
        tree[cn].val = tree[lc].val + tree[rc].val;
        return cn;
    }
}

int query(int n, int l, int r, int s = 0, int e = dis.size() - 1) {
    if (l > e || r < s)
        return 0;
    else if (s >= l && e <= r)
        return tree[n].val;
    else {
        int mid = (s + e) / 2;
        int lc = tree[n].l, rc = tree[n].r;
        int left = query(lc, l, r, s, mid);
        int right = query(rc, l, r, mid + 1, e);
        return left + right;
    }
}

int find(int val) {
    int lo = 0, hi = dis.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (val <= dis[mid])
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        num.push_back(a[i]);
    }
    sort(num.begin(), num.end());
    int id = 0;
    while (id < num.size()) {
        int x = num[id];
        dis.push_back(x);
        while (id < num.size() && x == num[id])
            id++;
    }
    build(nodes++);
    root[0] = update(0, nodes++, find(a[0]));
    for (int i = 1; i < n; i++) {
        root[i] = update(root[i - 1], nodes++, find(a[i]));
    }
    for (int q = 0; q < m; q++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        l--, r--;
        int lo = 0, hi = dis.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int inr = query(root[r], 0, mid);
            int inl;
            if (l > 0)
                inl = query(root[l - 1], 0, mid);
            else
                inl = 0;
            if (inr - inl < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        printf("%d\n", dis[lo]);
    }
    return 0;
}

