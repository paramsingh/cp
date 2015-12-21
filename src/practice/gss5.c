#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int sum;
    int lsum, rsum;
    int val;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max5(int a, int b, int c, int d, int e) {
    int arr[5] = {a, b, c, d, e};
    int mx = arr[0];
    int i;
    for (i = 1; i < 5; i++) {
        if (mx < arr[i])
            mx = arr[i];
    }
    return mx;
}

struct node* tree;
int a[10005];

void merge(struct node* a, struct node* l, struct node* r) {
    a->sum = l->sum + r->sum;
    a->lsum = max(l->lsum, l->sum + r->lsum);
    a->rsum = max(r->rsum, r->sum + l->rsum);
    a->val = max5(a->lsum, a->rsum, l->val, r->val, l->rsum + r->lsum);
}

void build(int i, int l, int r) {
    if (l == r) {
        tree[i].sum = tree[i].lsum = tree[i].rsum = tree[i].val = a[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        merge(tree+i, tree+2*i, tree+2*i+1);
    }
}

struct node* query(int l, int r, int i, int cl, int cr) {
    if (cl > r || cr < l || r < l || cr < cl)
        return tree;
    else if (cl >= l && cr <= r)
        return tree+i;
    else {
        int mid = (cl + cr) / 2;
        if (r <= mid)
            return query(l, r, 2*i, cl, mid);
        else if (l > mid)
            return query(l, r, 2*i+1, mid+1, cr);
        else {
            struct node* a = query(l, r, 2*i, cl, mid);
            struct node* b = query(l, r, 2*i+1, mid+1, cr);
            struct node* x = (struct node*) calloc(1, sizeof(struct node));
            merge(x, a, b);
            return x;
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        tree = (struct node*) calloc(4*n, sizeof(struct node));
        tree[0].sum = tree[0].rsum = tree[0].lsum = tree[0].val = 0;
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", a+i);
        build(1, 0, n-1);
        int q;
        scanf("%d", &q);
        while (q--) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x1--; y1--; x2--; y2--;
            if (y1 < x2)  {
                struct node* a = query(x1, y1, 1, 0, n-1);
                struct node* mid = query(y1+1, x2-1, 1, 0, n-1);
                struct node* b = query(x2, y2, 1, 0, n-1);
                printf("%d\n", a->rsum + mid->sum + b->lsum);
            }
            else {
                int res = query(x2, y1, 1, 0, n-1)->val;
                int a = query(x1, x2-1, 1, 0, n-1)->rsum;
                int b = query(x2, y2, 1, 0, n-1)->lsum;
                int c = query(x1, y1, 1, 0, n-1)->rsum;
                int d = query(y1+1, y2, 1, 0, n-1)->lsum;
                int e = max(a+b, c+d);
                res = max(res, e);
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
