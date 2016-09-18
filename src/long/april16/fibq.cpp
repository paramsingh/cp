#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int **unit, **beg;
class node {
    public:
        int** a;
        int ans;
};

void mul(int** c, int** a, int** b) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                int x = ((long long)(a[i][k]) * b[k][j]) % MOD;
                c[i][j] = (c[i][j] + x) % MOD;
            }

}

int** mexp(int n) {
    if (n == 0) {
        int **a;
        a = (int**) calloc(2, sizeof(int*));
        for (int i = 0; i < 2; i++)
            a[i] = (int*) calloc(2, sizeof(int));
        a[0][0] = a[1][1] = 1;
        a[0][1] = a[1][0] = 0;
        return a;
    }
    if (n == 1) {
        int** a = (int**) calloc(2, sizeof(int*));
        for (int i = 0; i < 2; i++)
            a[i] = (int*) calloc(2, sizeof(int));
        a[0][0] = a[1][0] = a[0][1] = 1;
        a[1][1] = 0;
        return a;
    }
    if (n % 2 == 0) {
        int **mid = mexp(n/2);
        int **a;
        a = (int**) calloc(2, sizeof(int*));
        for (int i = 0; i < 2; i++)
            a[i] = (int*) calloc(2, sizeof(int));
        mul(a, mid, mid);
        return a;
    }
    else {
        int **mid = mexp((n-1) / 2);
        int **a, **m;
        a = (int**) calloc(2, sizeof(int*));
        m = (int**) calloc(2, sizeof(int*));
        for (int i = 0; i < 2; i++) {
            a[i] = (int*) calloc(2, sizeof(int));
            m[i] = (int*) calloc(2, sizeof(int));
        }
        mul(a, mid, mid);
        mul(m, a, beg);
        return m;
    }
}

node tree[500000];
int arr[100100];
int size;
void build(int in, int l, int r) {
    if (l == r) {
        tree[in].a = mexp(arr[l]);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tree[in].a[i][j] = (tree[in].a[i][j] + unit[i][j]) % MOD;
        tree[in].ans = tree[in].a[0][1];
    }
    else {
        tree[in].a = (int**) calloc(2, sizeof(int*));
        for (int i = 0; i < 2; i++)
            tree[in].a[i] = (int*) calloc(2, sizeof(int));
        int mid = (l + r) / 2;
        build(2*in, l, mid);
        build(2*in + 1, mid+1, r);
        mul(tree[in].a, tree[2*in].a, tree[2*in+1].a);
        tree[in].ans = tree[in].a[0][1];
    }
}

int** query(int l, int r, int in = 1, int cl = 1, int cr = size) {
    if (cr < l || cl > r)
        return unit;
    else if (cl >= l && cr <= r)
        return tree[in].a;
    else {
        int mid = (cl + cr) / 2;
        int** a1 = query(l, r, 2*in, cl, mid);
        int** a2 = query(l, r, 2*in+1, mid+1, cr);
        int** a;
        a = (int**) calloc(2, sizeof(int*));
        for (int i = 0; i < 2; i++)
            a[i] = (int*) calloc(2, sizeof(int));
        mul(a, a1, a2);
        return a;
    }
}

void change(int l, int val, int in = 1, int cl = 1, int cr = size) {
    if (cl == cr && cl == l) {
        tree[in].a = mexp(val);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tree[in].a[i][j] = (tree[in].a[i][j] + unit[i][j]) % MOD;
    }
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            change(l, val, 2*in, cl, mid);
        else
            change(l, val, 2*in+1, mid+1, cr);
        tree[in].a = (int**) calloc(2, sizeof(int*));
        for (int i = 0; i < 2; i++)
            tree[in].a[i] = (int*) calloc(2, sizeof(int));
        mul(tree[in].a, tree[2*in].a, tree[2*in+1].a);
    }
}


int main(void) {
    unit = (int**) calloc(2, sizeof(int*));
    beg = (int**) calloc(2, sizeof(int*));
    for (int i = 0; i < 2; i++) {
        unit[i] = (int*) calloc(2, sizeof(int));
        beg[i] = (int*) calloc(2, sizeof(int));
    }
    unit[0][0] = unit[1][1] = 1;
    unit[0][1] = unit[1][0] = 0;
    beg[0][0] = beg[0][1] = beg[1][0] = 1;
    beg[1][1] = 0;
    int n, q;
    scanf("%d %d", &n, &q);
    size = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", arr+i);
    build(1, 1, n);
    while (q--) {
        char type[4]; int l, r;
        scanf("%s", type);
        if (type[0] == 'Q') {
            scanf("%d %d", &l, &r);
            printf("%d\n", (query(l, r))[0][1]);
        }
        else if (type[0] == 'C') {
            scanf("%d %d", &l, &r);
            change(l, r);
        }
    }
    return 0;
}
