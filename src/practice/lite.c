#include <stdio.h>
#include <stdlib.h>
#define SIZE 4000000

struct node {
    int ans;
    int lazy;
};

struct node* tree;

void merge(int i, int l, int r) {
    tree[i].ans = tree[2*i].ans + tree[2*i+1].ans;
}

void propagate(int i, int l, int r) {
    if (tree[i].lazy == 1) {
        tree[i].ans = r - l + 1 - tree[i].ans;
        if (l != r) {
            tree[2*i].lazy = !tree[2*i].lazy;
            tree[2*i+1].lazy = !tree[2*i+1].lazy;
        }
        tree[i].lazy = 0;
    }
}

void update(int l, int r, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return;
    else if (cl >= l && cr <= r) {
        tree[i].ans = cr - cl + 1 - tree[i].ans;
        if (cl != cr) {
            tree[2*i].lazy = !tree[2*i].lazy;
            tree[2*i+1].lazy = !tree[2*i+1].lazy;
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
    else if (cl >= l && cr <= r)
        return tree[i].ans;
    else {
        int mid = (cl + cr) / 2;
        int a = query(l, r, 2*i, cl, mid);
        int b = query(l, r, 2*i+1, mid+1, cr);
        return a + b;
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    tree = (struct node*) calloc(4*n, sizeof(struct node));
    while (m--) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        l--; r--;
        if (t == 0)
            update(l, r, 1, 0, n-1);
        else
            printf("%d\n", query(l, r, 1, 0, n-1));
    }
    return 0;
}
