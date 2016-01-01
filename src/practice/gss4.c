/** http://www.spoj.com/problems/GSS4/ */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100100

long long int tree[4*MAX];
long long int a[MAX];

void build(int i, int l, int r) {
    if (l == r)
        tree[i] = a[l];
    else {
         int mid = (l + r) / 2;
         build(2*i, l, mid);
         build(2*i+1, mid+1, r);
         tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void update(int l, int r, int i, int cl, int cr) {
    if (cl == cr) {
        tree[i] = (long long int) floor(sqrt(tree[i]));
        return;
    }
    else if (cl >= l && cr <= r) {
        if (tree[i] <= cr - cl + 1)
            return;
    }
    int mid = (cl + cr) / 2;
    if (r <= mid)
        update(l, r, 2*i, cl, mid);
    else if(l > mid)
        update(l, r, 2*i+1, mid+1, cr);
    else {
        update(l, r, 2*i, cl, mid);
        update(l, r, 2*i+1, mid+1, cr);
    }
    tree[i] = tree[2*i] + tree[2*i+1];
}

long long int sum(int l, int r, int i, int cl, int cr) {
    if (cl > r || cr < l || cr < cl || r < l)
        return 0;
    else if (cl >= l && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        return sum(l, r, 2*i, cl, mid) + sum(l, r, 2*i+1, mid+1, cr);
    }
}

int main(void) {
    int n;
    int c = 1;
    while(scanf("%d", &n) != EOF) {
        printf("Case #%d:\n", c++);
        int i;
        for (i = 0; i < n; i++)
            scanf("%lld", a+i);
        build(1, 0, n-1);
        int m;
        scanf("%d", &m);
        while (m--) {
            int t, x, y;
            scanf("%d %d %d", &t, &x, &y);
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            if (t == 1)
                printf("%lld\n", sum(x-1, y-1, 1, 0, n-1));
            else
                update(x-1, y-1, 1, 0, n-1);
        }
        printf("\n");
    }
    return 0;
}
