// Author: Param Singh <paramsingh258@gmail.com>
// Range Minimum Query: http://www.spoj.com/problems/RMQSQ/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX ((1 << 18) + 1)

struct node {
    int lr, rr;
    int val;
    int index;
};
struct node* st;
struct node* root;

void init() {
    st = (struct node*) calloc(MAX, sizeof(struct node));
    int i;
    for (i = 0; i < MAX; i++) {
        st[i].lr = st[i].rr = st[i].val = -1;
        st[i].index = i;
    }
    root = st+1;
}

int create(int* a, int left, int right, int sti) {
    if (left == right) {
        st[sti].lr = st[sti].rr = left;
        st[sti].val = a[left];
        return a[left];
    }
    else {
        st[sti].lr = left;
        st[sti].rr = right;
        int mid = (left + right) / 2;
        int leftans  = create(a, left, mid, 2*sti);
        int rightans = create(a, mid+1, right, (2*sti) + 1);
        if (leftans > rightans) {
            st[sti].val = rightans;
            return rightans;
        }
        else {
            st[sti].val = leftans;
            return leftans;
        }
    }
}

int query(struct node* x, int l, int r) {
    int left = x->lr;
    int right = x->rr;
    int index = x->index;
    if (left >= l && right <= r)
        return x->val;
    else if (left > r || right < l)
        return INT_MAX;
    else {
        int la = query(st+(index*2), l, r);
        int ra = query(st+((index*2) + 1), l, r);
        return la > ra ? ra : la;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int *a = (int *) calloc(n, 4);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    init();
    create(a, 0, n-1, 1);
    int q;
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n",query(root, x, y));
    }
    return 0;
}

