// Author: Param Singh <paramsingh258@gmail.com>
// Can you answer these queries I: http://www.spoj.com/problems/GSS1/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX ((1 << 17) + 1)

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct node {
    int lr, rr;
    int val, lsum, rsum, sum;
    int index;
};
struct node st[MAX];
struct node* root;

void init() {
    int i;
    for (i = 0; i < MAX; i++) {
        st[i].lr = st[i].rr = st[i].val = -1;
        st[i].lsum = st[i].rsum = st[i].sum = -1;
        st[i].index = i;
    }
    root = st+1;
}

void create(int* a, int left, int right, int sti) {
    if (left == right) {
        st[sti].lr = st[sti].rr = left;
        st[sti].val = st[sti].lsum = st[sti].rsum = st[sti].sum = a[left];
    }
    else {
        st[sti].lr = left;
        st[sti].rr = right;
        int mid = (left + right) / 2;
        create(a, left, mid, 2*sti);
        create(a, mid+1, right, (2*sti) + 1);
        struct node left = st[2*sti];
        struct node right = st[2*sti + 1];
        st[sti].sum  = left.sum + right.sum;
        st[sti].lsum = max(left.lsum, left.sum + right.lsum);
        st[sti].rsum = max(right.rsum, right.sum + left.rsum);
        st[sti].val = max(st[sti].rsum, max(st[sti].lsum, max(left.val, max(right.val, left.rsum + right.lsum))));
    }
}

struct node* query(struct node* x, int l, int r) {
    int left = x->lr;
    int right = x->rr;
    int index = x->index;
    if (left >= l && right <= r)
        return x;
    else if (left > r || right < l)
        return NULL;
    else {
        struct node* la = query(st+(index*2), l, r);
        struct node* ra = query(st+((index*2) + 1), l, r);
        if (la != NULL && ra != NULL) {
            struct node* result = (struct node *) calloc(1, sizeof(struct node));
            result->lsum = max(la->lsum, la->sum + ra->lsum);
            result->rsum = max(ra->rsum, ra->sum + la->rsum);
            result->val = max(result->rsum, max(result->lsum, max(la->val, max(ra->val, la->rsum + ra->lsum))));
            return result;
        }
        else if (la == NULL)
            return ra;
        else
            return la;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
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
        printf("%d\n", query(root, x-1, y-1)->val);
    }
    return 0;
}

