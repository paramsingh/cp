#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int val;
        int lazy;
};

node* tree;
int* a;
int* b;

int n, m;

inline void propagate(int i, int cl, int cr) {
    if (tree[i].lazy != 0) {
        tree[i].val = tree[i].lazy;
        if (cl != cr) {
            int mid = (cl + cr) / 2;
            tree[2*i].lazy = tree[i].lazy;
            tree[2*i+1].lazy = tree[i].lazy + mid + 1 - cl;
        }
        tree[i].lazy = 0;
    }
}

void update(int l, int r, int val, int cl = 1, int cr = n, int i = 1) {
    propagate(i, cl, cr);
    int mid = (cl + cr) / 2;
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        tree[i].val = val + cl - l;
        if (cl != cr) {
            tree[2*i].lazy = tree[i].val;
            tree[2*i + 1].lazy = tree[i].val + mid + 1 - cl;
        }
    }
    else {
        update(l, r, val, cl, mid, 2*i);
        update(l, r, val, mid+1, cr, 2*i+1);
    }
}

int get(int id, int cl = 1, int cr = n, int i = 1) {
    propagate(i, cl, cr);
    if (cl == cr && cl == id)
        return tree[i].val;
    else {
        int mid = (cl + cr) / 2;
        if (id <= mid)
            return get(id, cl, mid, 2*i);
        else
            return get(id, mid+1, cr, 2*i+1);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    a = (int*) calloc(n+10, sizeof(int));
    b = (int*) calloc(n+10, sizeof(int));
    int i;
    for (i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (i = 1; i <= n; i++)
        scanf("%d", b+i);
    tree = (node*) calloc(4*n, sizeof(node));
    int x, y, k;
    while (m--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &x, &y, &k);
            // have to put an AP [x ... x+k-1]
            update(y, y+k-1, x);
        }
        else {
            scanf("%d", &x);
            int id = get(x);
            if (id == 0)
                printf("%d\n", b[x]);
            else
                printf("%d\n", a[id]);
        }
    }
    return 0;
}
