#include <bits/stdc++.h>
#define MAX 30000
using namespace std;

vector<int> tree[MAX << 4];
int a[MAX];


void build(int i, int l, int r) {
    if (l == r) {
        tree[i].push_back(a[l]);
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        tree[i].resize(tree[2*i].size()+tree[2*i+1].size());
        merge(tree[2*i].begin(), tree[2*i].end(), tree[2*i+1].begin(), tree[2*i+1].end(), tree[i].begin());
    }
}

int query(int l, int r, int i, int cl, int cr, int k) {
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r) {
        return tree[i].end() - upper_bound(tree[i].begin(), tree[i].end(), k);
    }
    else {
        int mid = (cl + cr) / 2;
        return query(l, r, 2*i, cl, mid, k) + query(l, r, 2*i+1, mid+1, cr, k);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    build(1, 0, n-1);
    int ans = 0;
    int q;
    scanf("%d", &q);
    while (q--) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        a = a ^ ans;
        b = b ^ ans;
        k = k ^ ans;
        ans = query(a-1, b-1, 1, 0, n-1, k);
        printf("%d\n", ans);
    }
    return 0;
}
