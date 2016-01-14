#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

struct node {
    int sum;
    int lazy;
};

struct node** tree;
int* a;
int n;

inline void propagate(int bit, int i, int l, int r) {
    if (tree[bit][i].lazy != 0) {
        tree[bit][i].sum = (r - l + 1) - tree[bit][i].sum;
        if (l != r) {
            tree[bit][2*i].lazy = 1 - tree[bit][2*i].lazy;
            tree[bit][2*i + 1].lazy = 1 - tree[bit][2*i + 1].lazy;
        }
        tree[bit][i].lazy = 0;
    }
}

void build(int bit, int i, int l, int r) {
    tree[bit][i].lazy = 0;
    if (l == r)
        tree[bit][i].sum = (a[l] >> bit) & 1;
    else {
        int mid = (l + r) / 2;
        build(bit, 2*i, l, mid);
        build(bit, 2*i+1, mid+1, r);
        tree[bit][i].sum = tree[bit][2*i].sum + tree[bit][2*i+1].sum;
    }
}

void invert(int bit, int l, int r, int i, int cl, int cr) {
    propagate(bit, i, cl, cr);
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        tree[bit][i].sum = (cr - cl + 1) - tree[bit][i].sum;
        if (cl != cr) {
            tree[bit][2*i].lazy = 1 - tree[bit][2*i].lazy;
            tree[bit][2*i+1].lazy = 1 - tree[bit][2*i+1].lazy;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        invert(bit, l, r, 2*i, cl, mid);
        invert(bit, l, r, 2*i+1, mid+1, cr);
        tree[bit][i].sum = tree[bit][2*i].sum + tree[bit][2*i+1].sum;
    }
}

lli query(int bit, int l, int r, int i, int cl, int cr) {
    propagate(bit, i, cl, cr);
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r)
        return tree[bit][i].sum;
    else {
        int mid = (cl + cr) / 2;
        return query(bit, l, r, 2*i, cl, mid) + query(bit, l, r, 2*i+1, mid+1, cr);
    }
}

int main(void) {
    scanf("%d", &n);
    tree = (struct node**) calloc(35, sizeof(struct node*));
    int i;
    for (i = 0; i < 35; i++)
        tree[i] = (struct node*) calloc(4*n, sizeof(struct node));
    a = (int*) calloc(n+2, sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    for (i = 0; i <= 31; i++)
        build(i, 1, 0, n-1);
    int q;
    scanf("%d", &q);
    lli ans;
    while (q--) {
        ans = 0;
        int type, l, r, x;
        scanf("%d %d %d", &type, &l, &r);
        l--, r--;
        if (type == 1) {
            for (i = 0; i <= 31; i++) {
                ans += query(i, l, r, 1, 0, n-1) * (1 << i);
            }
            cout << ans << endl;
        }
        else {
            scanf("%d", &x);
            for (i = 0; i <= 31; i++) {
                int k = (x >> i) & 1;
                if (k == 1) {
                    invert(i, l, r, 1, 0, n-1);
                }
            }
        }
    }
    return 0;
}
