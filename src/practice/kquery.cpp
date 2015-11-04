#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct query {
    int l, r;
    int id;
} queries[200000];

int s;

int cmp(const void* a, const void* b) {
    struct query* x = (struct query *) a;
    struct query* y = (struct query *) b;
    if ( (x->l) / s == (y->l) / s) {
        return ((x->l)/s - (y->l)/s);
    }
    return ((x->r) - (y->r))
}

int main(void) {
    int n;
    scanf("%d", &n);
    s = sqrt(n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &(q[i].l), &(q[i].r));
        q[i].l--;
        q[i].r--;
        q[i].id = i;
    }

    qsort(queries, q, sizeof(struct query), cmp);

    int ans[q];

    for (int i = 0; i < q; i++) {

