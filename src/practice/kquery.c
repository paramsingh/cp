#include <stdio.h>
#include <stdlib.h>

int bit[30005];
int maxval;

void update(int id, int val) {
    while (id <= maxval) {
        bit[id] += val;
        id += (id & (-id));
    }
}

int query(int id) {
    int sum = 0;
    while (id > 0) {
        sum += bit[id];
        id -= (id & (-id));
    }
    return sum;
}

struct kquery {
    int i;
    int j;
    int k;
    int num;
} queries[200001];

int cmp(const void* a, const void* b) {
    struct kquery* x = (struct kquery*) a;
    struct kquery* y = (struct kquery*) b;
    if (y->k == x->k)
        return y->j - x->j;
    return (y->k) - (x->k);
}

struct num {
    int val, index;
} arr[30005];

int cmp1(const void* a, const void* b) {
    struct num* x = (struct num*) a;
    struct num* y = (struct num*) b;
    return (y->val) - (x->val);
}

int main(void) {
    int n;
    scanf("%d", &n);
    maxval = n;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].index = i+1;
        bit[i] = 0;
    }
    qsort(arr, n, sizeof(struct num), cmp1);
    int q;
    scanf("%d", &q);
    int res[q];
    for (i = 0; i < q; i++) {
        scanf("%d %d %d", &queries[i].i, &queries[i].j, &queries[i].k);
        queries[i].num = i;
    }
    qsort(queries, q, sizeof(struct kquery), cmp);
    int j = 0;
    for (i = 0; i < q; i++) {
        while (j < n && arr[j].val > queries[i].k) {
            update(arr[j].index, 1);
            j++;
        }
        res[queries[i].num] = query(queries[i].j) - query(queries[i].i - 1);
    }
    for (i = 0; i < q; i++)
        printf("%d\n", res[i]);
    return 0;
}

