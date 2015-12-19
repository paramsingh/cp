#include <stdio.h>
#include <stdlib.h>

struct node {
    int two, three, five;
};

struct node* tree;
int* a;

void propagate(int i, int cl, int cr) {
    if (cl != cr) {
        tree[2*i].two += tree[i].two;
        tree[2*i+1].two += tree[i].two;
        tree[2*i].three += tree[i].three;
        tree[2*i+1].three += tree[i].three;
        tree[2*i].five += tree[i].five;
        tree[2*i+1].five += tree[i].five;
        tree[i].two = tree[i].three = tree[i].five = 0;
    }
}

void update(int l, int r, int i, int cl, int cr, int val) {
    propagate(i, cl, cr);
    if (cr < l || cl > r) {
        return;
    }
    else if (cl >= l && cr <= r) {
        if (val == 2)
            tree[i].two++;
        else if (val == 3)
            tree[i].three++;
        else
            tree[i].five++;
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, 2*i, cl, mid, val);
        update(l, r, 2*i+1, mid+1, cr, val);
    }
}

void update1(int l, int i, int cl, int cr, int val) {
    propagate(i, cl, cr);
    if (cl == l && cr == l) {
        tree[i].two = 0;
        tree[i].three = 0;
        tree[i].five = 0;
        a[l] = val;
    }
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update1(l, 2*i, cl, mid, val);
        else
            update1(l, 2*i+1, mid+1, cr, val);
    }
}

int query(int l, int i, int cl, int cr, int two, int three, int five) {
    if (cl == l && cr == l) {
        int x = a[l];
        two += tree[i].two;
        three += tree[i].three;
        five += tree[i].five;
        while (two && (x % 2 == 0)) {
            x /= 2;
            two--;
        }
        while (three && (x % 3 == 0)) {
            x /= 3;
            three--;
        }
        while (five && (x % 5 == 0)) {
            x /= 5;
            five--;
        }
        return x;
    }
    else {
        two += tree[i].two;
        three += tree[i].three;
        five += tree[i].five;
        int mid = (cl + cr) / 2;
        if (l <= mid)
            return query(l, 2*i, cl, mid, two, three, five);
        else
            return query(l, 2*i+1, mid+1, cr, two, three, five);
    }
}


int main(void) {
    int n;
    scanf("%d", &n);
    a = (int *) calloc(n, sizeof(int));
    tree = (struct node*) calloc(4*n, sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    int type, l, r, p;
    while (m--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d", &l, &r, &p);
            update(l-1, r-1, 1, 0, n-1, p);
        }
        else {
            scanf("%d %d", &l, &r);
            update1(l-1, 1, 0, n-1, r);
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", query(i, 1, 0, n-1, 0, 0, 0));
    }
    return 0;
}
