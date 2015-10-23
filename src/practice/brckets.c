// Author: Param Singh <paramsingh258@gmail.com>
// Brackets: http://www.spoj.com/problems/BRCKTS/

#include <stdio.h>
#include <stdlib.h>
#define SIZE ((1 << 17) + 1)

struct node {
    int lr, rr;
    int open, closed;
    int id;
};

struct node st[SIZE];
struct node* root = st + 1;

void init() {
    int i;
    for (i = 0; i < SIZE; i++) {
        st[i].lr = st[i].rr = st[i].open = st[i].closed = 0;
        st[i].id = i;
    }
}

void merge(struct node* a, struct node* left, struct node* right) {
    int nm = ((left->open) < (right->closed)) ? (left->open) : (right->closed);
    a->open = (right->open) + (left->open) - nm;
    a->closed = (right->closed) + (left->closed) - nm;
}

void build(char* a, int left, int right, int i) {
    if (left == right) {
        st[i].lr = st[i].rr = left;
        if (a[left] == '(') {
            st[i].open   = 1;
            st[i].closed = 0;
        }
        else {
            st[i].open   = 0;
            st[i].closed = 1;
        }
    }
    else {
        st[i].lr = left;
        st[i].rr = right;
        int mid = (left + right) / 2;
        build(a, left, mid, 2*i);
        build(a, mid+1, right, 2*i + 1);
        merge(st+i, st+(2*i), st+(2*i)+1);
    }
}

void update(struct node* a, int i) {
    int la = a->lr, ra = a->rr;
    if (la == ra) {
        a->open   = 1 - a->open;
        a->closed = 1 - a->closed;
    }
    else {
        int mid = (la + ra) / 2;
        struct node* left = st + (2*(a->id));
        struct node* right = st + (2*(a->id)) + 1;
        if (i <= mid)
            update(left, i);
        else
            update(right, i);
        merge(a, left, right);
    }
}

int check() {
    return (root->open == 0 && root->closed == 0);
}

int main(void) {
    int i = 1;
    int t = 10;
    while (t--) {
        printf("Test %d:\n", i);
        int n;
        scanf("%d", &n);
        char a[n+1];
        scanf("%s", a);
        init();
        build(a, 0, n-1, 1);
        int q;
        scanf("%d", &q);
        int j;
        for (j = 0; j < q; j++) {
            int x;
            scanf("%d", &x);
            if (x == 0) {
                if (check())
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else {
                update(root, x-1);
            }
        }
        i++;
    }
}
