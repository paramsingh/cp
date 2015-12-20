#include <stdio.h>
#include <stdlib.h>

struct node {
    int zero;
    int one;
    int two;
    int lazy;
};

struct node tree[400000];

void merge(int i, int l, int r) {
    tree[i].zero = tree[2*i].zero + tree[2*i+1].zero;
    tree[i].one = tree[2*i].one + tree[2*i+1].one;
    tree[i].two = tree[2*i].two + tree[2*i+1].two;
}

void propagate(int i, int l, int r) {
    if (tree[i].lazy == 1) {
        int temp = tree[i].zero;
        tree[i].zero = tree[i].two;
        tree[i].two = tree[i].one;
        tree[i].one = temp;
        if (l != r) {
            tree[2*i].lazy++;
            tree[2*i].lazy %= 3;
            tree[2*i+1].lazy++;
            tree[2*i+1].lazy %= 3;
        }
        tree[i].lazy = 0;
    }
    else if (tree[i].lazy == 2) {
        int temp = tree[i].zero;
        tree[i].zero = tree[i].one;
        tree[i].one = tree[i].two;
        tree[i].two = temp;
        if (l != r) {
            tree[2*i].lazy += 2;
            tree[2*i+1].lazy += 2;
            tree[2*i].lazy %= 3;
            tree[2*i+1].lazy %= 3;
        }
        tree[i].lazy = 0;
    }
}

void build(int i, int l, int r) {
    tree[i].lazy = 0;
    if (l == r) {
        tree[i].zero = 1;
        tree[i].one = 0;
        tree[i].two = 0;
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        merge(i, l, r);
    }
}

void update(int l, int r, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        int temp = tree[i].zero;
        tree[i].zero = tree[i].two;
        tree[i].two = tree[i].one;
        tree[i].one = temp;
        if (cl != cr) {
            tree[2*i].lazy = (tree[2*i].lazy + 1) % 3;
            tree[2*i+1].lazy = (tree[2*i+1].lazy + 1) % 3;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, 2*i, cl, mid);
        update(l, r, 2*i+1, mid+1, cr);
        merge(i, cl, cr);
    }
}

int query(int l, int r, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r) {
        return tree[i].zero;
    }
    else {
        int mid = (cl + cr) / 2;
        int a = query(l, r, 2*i, cl, mid);
        int b = query(l, r, 2*i+1, mid+1, cr);
        return a + b;
    }
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    build(1, 0, n-1);
    while (q--) {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        if (t == 0)
            update(a, b, 1, 0, n-1);
        else
            printf("%d\n", query(a, b, 1, 0, n-1));
    }
    return 0;
}
