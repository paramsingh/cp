// Author: Param Singh <paramsingh258@gmail.com>
// Horrible Queries: http://www.spoj.com/problems/HORRIBLE

#include <stdio.h>
#include <stdlib.h>
#define SIZE ((1 << 19) + 1)

struct node {
    int lr, rr;
    long long int sum;
    int id;
    long long int lazy;
};

struct node st[SIZE];
struct node* root = st + 1;

void build(int left, int right, int i) {
    st[i].id = i;
    st[i].lr = left;
    st[i].rr = right;
    st[i].sum = 0;
    st[i].lazy = 0;
    if (left == right) {
        return;
    }
    else {
        int l = (2*i);
        int r = (2*i) + 1;
        int mid = (left + right) / 2;
        build(left, mid, l);
        build(mid+1, right, r);
    }
}

long long int update(struct node* x, int left, int right, long long int v) {
    int lr = x->lr, rr = x->rr;
    int i = x->id;
    if (x->lazy != 0) {
        x->sum += x->lazy;
        if (lr != rr) {
            int mid = (lr + rr) / 2;
            st[2*i].lazy     += (((x->lazy) / (rr - lr + 1)) * (mid - lr + 1));
            st[2*i + 1].lazy += (((x->lazy) / (rr - lr + 1)) * (rr - mid));
        }
        x->lazy = 0;
    }
    if (left > rr || right < lr) {
        return x->sum;
    }
    else if (lr >= left && rr <= right) {
        x->sum += v * (rr - lr + 1);
        if (lr != rr) {
            int mid = (lr + rr) / 2;
            st[2*i].lazy     += (v * (mid - lr + 1));
            st[2*i + 1].lazy += (v * (rr - mid));
        }
        return x->sum;
    }
    else {
        long long int a = update(st + (2*i), left, right, v);
        long long int b = update(st + (2*i) + 1, left, right, v);
        x->sum = (a + b);
        return x->sum;
    }
}

long long int query(struct node* x, int left, int right) {
    int lr = x->lr, rr = x->rr;
    int i = x->id;
    if (x->lazy != 0) {
        x->sum += x->lazy;
        if (lr != rr) {
            int mid = (lr + rr) / 2;
            st[2*i].lazy += ((x->lazy) / (rr - lr + 1)) * (mid - lr + 1);
            st[2*i + 1].lazy += ((x->lazy) / (rr - lr + 1)) * (rr - mid);
        }
        x->lazy = 0;
    }
    if (left > rr || right < lr) {
        return 0;
    }
    else if (lr >= left && rr <= right) {
        return x->sum;
    }
    else {
        long long int a = query(st + (2*i), left, right);
        long long int b = query(st + (2*i) + 1, left, right);
        return a + b;
    }
}

int main(void) {
    int t, j;
    scanf("%d", &t);
    while (t--) {
        int n, c;
        scanf("%d %d", &n, &c);
        int i;
        build(0, n-1, 1);
        int a[n];
        for (i = 0; i < n; i++)
            a[i] = 0;
        for (i = 0; i < c; i++) {
            int type, p, q;
            long long int v;
            scanf("%d", &type);
            if (type == 0) {
                scanf("%d %d %lld", &p, &q, &v);
                update(root, p-1, q-1, v);
            }
            else if (type == 1) {
                scanf("%d %d", &p, &q);
                printf("%lld\n", query(root, p-1, q-1));
            }
        }
    }
    return 0;
}

