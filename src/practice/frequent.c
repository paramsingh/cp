#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE ((1 << 18) + 1)
#define max(a, b) a>b?a:b

struct node {
    int l, r;
    int freq, lfreq, rfreq;
    int lval, rval;
} tree[SIZE];

struct node* root = tree + 1;

int max3(int a, int b, int c) {
    int r[] = {a, b, c};
    int max = INT_MIN;
    int i;
    for (i = 0; i < 3; i++) {
        if (r[i] > max)
            max = r[i];
    }
    return max;
}

int a[100001];

void merge(struct node* i, struct node* lc, struct node* rc) {
    if (lc->rval == rc->lval) {
        int c = lc->rfreq + rc->lfreq;
        i->freq = max3(c, lc->freq, rc->freq);
    }
    else {
        i->freq = max(lc->freq, rc->freq);
    }
    if (lc->lval == rc->lval)
        i->lfreq = lc->lfreq + rc->lfreq;
    else
        i->lfreq = lc->lfreq;

    if (rc->rval == lc->rval)
        i->rfreq = lc->rfreq + rc->rfreq;
    else
        i->rfreq = rc->rfreq;
}

void build(int l, int r, int i) {
    tree[i].l = l;
    tree[i].r = r;
    tree[i].lval = a[l];
    tree[i].rval = a[r];
    if (l == r) {
        tree[i].freq = tree[i].lfreq = tree[i].rfreq = 1;
    }
    else {
        int mid = (l + r) / 2;
        build(l, mid, 2*i);
        build(mid+1, r, 2*i + 1);
        merge(tree+i,tree+2*i, tree+2*i+1);
    }
}

struct node* query(int l, int r, int i, int cl, int cr) {
    if (cl > r || cr < l)
        return NULL;
    else if (cl >= l && cr <= r)
        return tree+i;
    else {
        int mid = (cl + cr) / 2;
        struct node* x = query(l, r, 2*i, cl, mid);
        struct node* y = query(l, r, 2*i+1, mid+1, cr);
        if (x != NULL && y != NULL) {
            struct node* result = (struct node *) calloc(1, sizeof(struct node));
            result->l = cl;
            result->r = cr;
            result->lval = a[cl];
            result->rval = a[cr];
            merge(result, x, y);
            return result;
        }
        else if (x != NULL)
            return x;
        else if (y != NULL)
            return y;
        else
            return NULL;
    }
}

int main(void) {
    int n, q, i;
    int l, r;
    scanf("%d", &n);
    while (n != 0) {
        scanf("%d", &q);
        for (i = 0; i < n; i++)
            scanf("%d", a+i);
        build(0, n-1, 1);
        for (i = 0; i < q; i++) {
            scanf("%d %d", &l, &r);
            struct node* result = query(l-1, r-1, 1, 0, n-1);
            printf("%d\n", result->freq);
        }
        scanf("%d", &n);
    }
    return 0;
}
