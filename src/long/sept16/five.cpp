#include <bits/stdc++.h>
using namespace std;

int where[1001000];
int factor[1001000];
int sieve[1001000];
int a[100100];
int tree[400100];
int val[400100];
int n;

void build(int i = 1, int s = 1, int e = n) {
    if (s == e) {
        tree[i] = factor[a[s]];
        val[i] = a[s];
    }
    else {
        int mid = (s + e) / 2;
        build(2*i, s, mid);
        build(2*i+1, mid + 1, e);
        tree[i] = max(tree[2*i], tree[2*i+1]);
        val[i] = 0;
    }
}

void update(int l, int r, int i = 1, int s = 1, int e = n) {
    if (s > r || e < l)
        return;
    else if (tree[i] == 1)
        return;
    else if (s == e && l <= s && s <= r) {
        val[i] /= factor[val[i]];
        tree[i] = factor[val[i]];
    }
    else {
        int mid = (s + e) / 2;
        update(l, r, 2*i, s, mid);
        update(l, r, 2*i+1, mid + 1, e);
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }
}

int get(int l, int r, int i = 1, int s = 1, int e = n) {
    if (s > r || e < l)
        return -1;
    else if (s >= l && e <= r)
        return tree[i];
    else {
        int mid = (s + e) / 2;
        int left = get(l, r, 2*i, s, mid);
        int right = get(l, r, 2*i+1, mid + 1, e);
        return max(left, right);
    }
}

int main(void) {

    factor[1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j <= 1e6; j += i) {
                sieve[j] = 1;
                if (factor[j] == 0)
                    factor[j] = i;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        int m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        build();
        while (m--) {
            int type, l, r;
            scanf("%d %d %d", &type, &l, &r);
            if (type == 0)
                update(l, r);
            else
                printf("%d ", get(l, r));
        }
        printf("\n");
    }
    return 0;
}
