#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct node {
    lli ans, lsum, rsum, sum;
    int use;
} tree[500100];

int n;
int a[100100];

inline void merge(int i, int l, int r) {
    if (tree[l].use && tree[r].use) {
        tree[i].lsum = max(tree[l].lsum, tree[l].sum + tree[r].lsum);
        tree[i].rsum = max(tree[r].rsum, tree[r].sum + tree[l].rsum);
        tree[i].sum = tree[l].sum + tree[r].sum;
        tree[i].ans = max(tree[i].rsum, tree[i].lsum);
        tree[i].ans = max(tree[i].ans , tree[l].ans);
        tree[i].ans = max(tree[i].ans, tree[r].ans);
        tree[i].ans = max(tree[i].ans, tree[l].rsum + tree[r].lsum);
    }
    else if (tree[l].use) {
        tree[i].lsum = tree[l].lsum;
        tree[i].rsum = tree[l].rsum;
        tree[i].sum = tree[l].sum;
        tree[i].ans = tree[l].ans;
    }
    else if (tree[r].use) {
        tree[i].lsum = tree[r].lsum;
        tree[i].rsum = tree[r].rsum;
        tree[i].sum = tree[r].sum;
        tree[i].ans = tree[r].ans;
    }
}

void build(int i = 1, int l = 1, int r = n) {
    if (l == r) {
        tree[i].lsum = a[l];
        tree[i].rsum = a[l];
        tree[i].sum = a[l];
        tree[i].ans = a[l];
        tree[i].use = 1;
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid + 1, r);
        merge(i, 2*i, 2*i+1);
        tree[i].use = 1;
    }
}

void change(int id, int val, int i = 1, int cl = 1, int cr = n) {
    if (id == cl && cl == cr) {
        tree[i].use = val;
    }
    else {
        int mid = (cl + cr) / 2;
        if (id <= mid)
            change(id, val, 2*i, cl, mid);
        else
            change(id, val, 2*i+1, mid+1, cr);
        merge(i, 2*i, 2*i+1);
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    int cnt = 1;
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        build();
        lli ans = tree[1].ans;
        for (int i = 1; i <= n; i++) {
            change(i, 0);
            ans = max(ans, tree[1].ans);
            change(i, 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
