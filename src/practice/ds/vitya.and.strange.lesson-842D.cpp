#include <bits/stdc++.h>
using namespace std;

struct node {
    int nxt[2]; 
    int cnt;
} tree[10010000];

int root = 1;
int track = 2;
int a[312345];

void insert(int val, int u=root, int bit=21) {
    if (bit < 0) {
        tree[u].cnt = 1;
        return;
    }
    int go = (val >> bit) & 1;
    if (!tree[u].nxt[go])
        tree[u].nxt[go] = track++;
    insert(val, tree[u].nxt[go], bit - 1);
    tree[u].cnt = tree[tree[u].nxt[0]].cnt + tree[tree[u].nxt[1]].cnt;
}


int get(int val, int x, int u=root, int bit=21) {
    if (u == 0) return 0;
    if (bit < 0) {
        return 1;
    }
    int b = (val >> bit) & 1;
    int xb = (x >> bit) & 1;
    if (b == 0) {
        if (xb == 0)
            return get(val, x, tree[u].nxt[0], bit - 1);
        else
            return get(val, x, tree[u].nxt[1], bit - 1);
    }
    else {
        if (xb == 0)
            return tree[tree[u].nxt[0]].cnt + get(val, x, tree[u].nxt[1], bit - 1);
        else
            return tree[tree[u].nxt[1]].cnt + get(val, x, tree[u].nxt[0], bit - 1);
    }
}


int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int x = 0;
    while (m--) {
        int u;
        scanf("%d", &u);
        x ^= u;
        int lo = 0, hi = 1e9;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (get(mid, x) <= mid)
                hi = mid;
            else
                lo = mid + 1;
        }
        printf("%d\n", lo);
    }
}
