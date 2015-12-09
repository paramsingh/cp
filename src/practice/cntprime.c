// www.spoj.com/problems/CNTPRIME

#include <stdio.h>
#include <stdlib.h>

int* seive;
int eq[10006];
struct node {
    int sum;
    int lazy;
} tree[40008];

void build(int i, int l, int r) {
    tree[i].lazy = 0;
    if (l == r) {
        tree[i].sum = eq[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;
    }
}

void propagate(int i, int l, int r) {
    if (tree[i].lazy != 0) {
        if (seive[tree[i].lazy] == 0)
            tree[i].sum = r - l + 1;
        else
            tree[i].sum = 0;
        if (l != r) {
            tree[2*i].lazy   = tree[i].lazy;
            tree[2*i+1].lazy = tree[i].lazy;
        }
        tree[i].lazy = 0;
    }
}

int query(int l, int r, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r)
        return tree[i].sum;
    else {
        int mid = (cl + cr) / 2;
        int a = query(l, r, 2*i, cl, mid);
        int b = query(l, r, 2*i+1, mid+1, cr);
        return a + b;
    }
}

void update(int l, int r, int val, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        tree[i].lazy = val;
        propagate(i, cl, cr);
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, val, 2*i, cl, mid);
        update(l, r, val, 2*i+1, mid+1, cr);
        tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;
    }
}

int main(void) {
    int i, j;
    seive = (int *) calloc(1000005, sizeof(int));
    for (i = 2; i < 1000005; i++) {
        if (seive[i] == 0) {
            for (j = 2*i; j < 1000005; j+=i)
                seive[j] = 1;
        }
    }
    int term, cs;
    scanf("%d", &term);
    for (cs = 1; cs <= term; cs++) {
        printf("Case %d:\n", cs);
        int n, q;
        scanf("%d %d", &n, &q);
        int i;
        for (i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (seive[x] == 0)
                eq[i] = 1;
            else
                eq[i] = 0;
        }
        build(1, 0, n-1);
        for (i = 0; i < q; i++) {
            int type, x, y, v;
            scanf("%d", &type);
            if (type == 0) {
                scanf("%d %d %d", &x, &y, &v);
                update(x-1, y-1, v, 1, 0, n-1);
            }
            else {
                scanf("%d %d", &x, &y);
                printf("%d\n", query(x-1, y-1, 1, 0, n-1));
            }
        }
    }
    return 0;
}
