#include <bits/stdc++.h>
using namespace std;

const int MAX_BIT = 28;

struct node {
    int zero, one;       // the children if you follow zero or one
    int wt_zero, wt_one; // the number of children in this subtree
} tree[10000000];


int nxt = 1;

void insert(int val, int bit = MAX_BIT, int u = 1) {
    if (bit < 0)
        return;
    else {
        int b = (val >> bit) & 1;
        if (b) {
            if (!tree[u].one)
                tree[u].one = ++nxt;
            tree[u].wt_one++;
            insert(val, bit - 1, tree[u].one);
        }
        else {
            if (!tree[u].zero)
                tree[u].zero = ++nxt;
            tree[u].wt_zero++;
            insert(val, bit - 1, tree[u].zero);
        }
    }
}

void rm(int val, int bit = MAX_BIT, int u = 1) {
    if (bit < 0)
        return;
    else {
        if ((val >> bit) & 1) {
            tree[u].wt_one--;
            rm(val, bit - 1, tree[u].one);
        }
        else {
            tree[u].wt_zero--;
            rm(val, bit - 1, tree[u].zero);
        }
    }
}

int get(int x, int y, int bit = MAX_BIT, int u = 1) {
    if (u == 0)
        return 0;
    if (bit < 0)
        return 0;
    else {
        int b  = (x >> bit) & 1;
        int yb = (y >> bit) & 1;
        int ans = 0;
        if (b == 0) {
            if (yb == 0)
                ans += get(x, y, bit - 1, tree[u].zero);
            else
                ans += get(x, y, bit - 1, tree[u].one) + tree[u].wt_zero;
        }
        else {
            if (yb == 0) {
                ans += get(x, y, bit - 1, tree[u].one);
            }
            else {
                ans += tree[u].wt_one + get(x, y, bit - 1, tree[u].zero);
            }
        }
        return ans;
    }
}


int main(void) {
    int q;
    scanf("%d", &q);
    while (q--) {
        int type, x, y;
        scanf("%d %d", &type, &x);
        if (type == 1) {
            insert(x);
        }
        else if (type == 2) {
            rm(x);
        }
        else {
            scanf("%d", &y);
            printf("%d\n", get(x, y));
        }
    }
}
