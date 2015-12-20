#include <stdio.h>
#include <stdlib.h>

struct node {
    long long int ans;
    long long int sum;
    long long int lazy;
    int lazy1;
    int val;
};

struct node* tree;
int a[100100];

void merge(int i, int l, int r) {
    tree[i].ans = tree[2*i].ans + tree[2*i+1].ans;
    tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;
}

void propagate(int i, int l, int r) {
    if (tree[i].lazy1 == 1) {
        tree[i].ans = (r - l + 1) * tree[i].val * tree[i].val;
        tree[i].sum = (r - l + 1) * tree[i].val;
        if (l != r) {
            tree[2*i].lazy1 = 1;
            tree[2*i+1].lazy1 = 1;
            tree[2*i].val = tree[i].val;
            tree[2*i+1].val = tree[2*i+1].val;
            tree[2*i].lazy = tree[2*i+1].lazy = 0;
        }
        tree[i].lazy1 = 0;
        tree[i].lazy = 0;
    }
    else if (tree[i].lazy != 0) {
        tree[i].ans += (((r - l + 1) * tree[i].lazy * tree[i].lazy) + (2 * tree[i].sum * tree[i].lazy));
        tree[i].sum += (tree[i].lazy * (r - l + 1));
        if (l != r) {
            tree[2*i].lazy += tree[i].lazy;
            tree[2*i+1].lazy += tree[i].lazy;
        }
        tree[i].lazy = 0;
    }
}

void build(int i, int l, int r) {
    tree[i].lazy = tree[i].lazy1 = 0;
    tree[i].val = 0;
    if (l == r) {
        tree[i].ans = a[l]*a[l];
        tree[i].sum = a[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        merge(i, l, r);
    }
}

void update(int l, int r, int i, int cl, int cr, int val) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        tree[i].ans += (((cr - cl + 1) * val * val) + 2 * tree[i].sum * val);
        tree[i].sum += (val * (cr - cl + 1));
        if (cl != cr) {
            tree[2*i].lazy += val;
            tree[2*i+1].lazy += val;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, 2*i, cl, mid, val);
        update(l, r, 2*i+1, mid+1, cr, val);
        merge(i, l, r);
    }
}

void update1(int l, int r, int i, int cl, int cr, int val) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        tree[i].ans = (cr - cl + 1) * val * val;
        tree[i].sum = (cr - cl + 1) * val;
        if (cl != cr) {
            tree[2*i].lazy1 = 1;
            tree[2*i+1].lazy1 = 1;
            tree[2*i].val = val;
            tree[2*i+1].val = val;
            tree[2*i].lazy = 0;
            tree[2*i+1].lazy = 0;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update1(l, r, 2*i, cl, mid, val);
        update1(l, r, 2*i+1, mid+1, cr, val);
        merge(i, l, r);
    }
}

long long int query(int l, int r, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r)
        return tree[i].ans;
    else {
        int mid = (cl + cr) / 2;
        long long int a = query(l, r, 2*i, cl, mid);
        long long int b = query(l, r, 2*i+1, mid+1, cr);
        return a+b;
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    int c = 1;
    while (t--) {
        printf("Case %d:\n", c++);
        int n, q;
        scanf("%d %d", &n, &q);
        tree = (struct node*) calloc(4*n, sizeof(struct node));
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", a+i);
        build(1, 0, n-1);
        while (q--) {
            int t, start, end, x;
            scanf("%d", &t);
            if (t == 2) {
                scanf("%d %d", &start, &end);
                printf("%lld\n", query(start-1, end-1, 1, 0, n-1));
            }
            else if (t == 1) {
                scanf("%d %d %d", &start, &end, &x);
                update(start-1, end-1, 1, 0, n-1, x);
            }
            else if (t == 0) {
                scanf("%d %d %d", &start, &end, &x);
                update1(start-1, end-1, 1, 0, n-1, x);
            }
        }
    }
    return 0;
}
