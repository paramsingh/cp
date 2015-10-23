// Author: Param Singh <paramsingh258@gmail.com>
// http://www.spoj.com/problems/GSS3/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE ((1 << 19) + 1)

struct node {
    int lr, rr;
    int max, smax, val;
    int id;
};

struct node st[SIZE];
struct node* root = st+1;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

void init() {
    int i;
    for (i = 0; i < SIZE; i++) {
        st[i].lr = st[i].rr = -1;
        st[i].max = st[i].smax = st[i].val = -1;
        st[i].id = i;
    }
}

void merge(struct node* cur, struct node* a, struct node* b) {
    cur->max = max(a->max, b->max);
    int mini = min(a->max, b->max);
    cur->smax = max(mini, max(a->smax, b->smax));
    cur->val = cur->max + cur->smax;
}

void create(int* a, int left, int right, int i) {
    if (left == right) {
        st[i].lr = st[i].rr = left;
        st[i].val = st[i].max = a[left];
        st[i].smax = 0;
    }
    else {
        st[i].lr = left;
        st[i].rr = right;
        int mid = (left + right) / 2;
        create(a, left, mid, 2*i);
        create(a, mid+1, right, (2*i) + 1);
        merge(st+i, st+(2*i), st+(2*i)+1);
    }
}

struct node* query(struct node* x, int l, int r) {
    int left = x->lr;
    int right = x->rr;
    int i = x->id;
    if (left >= l && right <= r)
        return x;
    else if (left > r || right < l)
        return NULL;
    else {
        struct node* la = query(st + (2*i), l, r);
        struct node* ra = query(st + (2*i) + 1, l, r);
        if (la != NULL && ra != NULL) {
            struct node* result = (struct node*) calloc(1, sizeof(struct node));
            merge(result, la, ra);
            return result;
        }
        else if (la == NULL)
            return ra;
        else
            return la;
    }
}

void update(struct node* s, int i, int value) {
    int lo = s->lr, hi = s->rr, id = s->id;
    if (lo == hi) {
        s->max = s->val = value;
        s->smax = 0;
    }
    else {
        int mid = (lo + hi) / 2;
        if (i <= mid)
            update(st+(2*id), i, value);
        else
            update(st+(2*id+1), i, value);
        merge(s, st+(2*id), st+(2*id + 1));
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
        char t;
        int  x, y;
        scanf(" %c%d%d", &t, &x, &y);
        if (t == 'Q') {
            printf("%d\n", query(root, x-1, y-1) -> val);
        }
        else if (t == 'U') {
            update(root, x-1, y);
        }
    }
}
