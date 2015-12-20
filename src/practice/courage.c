#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a<b?a:b

struct node {
    long long int sum;
    long long int m;
};

struct node tree[400000];
long long int a[100004];

void merge(int i, int cl, int cr) {
    tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;
    tree[i].m = min(tree[2*i].m, tree[2*i+1].m);
}

void build(int i, int l, int r) {
    if (l == r) {
        tree[i].sum = a[l];
        tree[i].m = a[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        merge(i, l, r);
    }
}

void update(int id, int i, int l, int r, int val) {
    if (l == r && id == l) {
        tree[i].sum += val;
        tree[i].m += val;
    }
    else {
        int mid = (l + r) / 2;
        if (id <= mid)
            update(id, 2*i, l, mid, val);
        else
            update(id, 2*i+1, mid+1, r, val);
        merge(i, l, r);
    }
}

struct node* count(int l, int r, int i, int cl, int cr) {
    if (cl > r || cr < l)
        return NULL;
    else if (cl >= l && cr <= r) {
        return tree+i;
    }
    else {
        int mid = (cl + cr) / 2;
        struct node* a = count(l, r, 2*i, cl, mid);
        struct node* b = count(l, r, 2*i+1, mid+1, cr);
        if (a != NULL && b != NULL) {
            struct node* result = (struct node*) calloc(1, sizeof(struct node));
            result->sum = a->sum + b->sum;
            result->m = min(a->m, b->m);
            return result;
        }
        else if (a != NULL)
            return a;
        else if (b != NULL)
            return b;
    }
}

int main(void) {
    char choice[10];
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%lld", a+i);
    build(1, 0, n-1);
    int p, x, y;
    scanf("%d", &p);
    while (p--) {
        scanf("%s %d %d", choice, &x, &y);
        if (choice[0] == 'E')
            update(y, 1, 0, n-1, -x);
        else if (choice[0] == 'G')
            update(y, 1, 0, n-1, x);
        else {
            struct node* ans = count(x, y, 1, 0, n-1);
            printf("%lld\n", ans->sum - ans->m);
        }
    }
    return 0;
}

