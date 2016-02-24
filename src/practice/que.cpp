// Problem: Given the height of n people and the number of people who are taller
// and ahead of them, find the position of each person.

// Strategy: We know the position of the shortest person always. Similarly we can find
// the position of every person if we go in sorted order of heights. In order to find
// the position, we use a segment tree which stores 1 at a position if there's no one
// at that position yet. We find the kth free position by using binary search on this
// tree.

#include <bits/stdc++.h>
using namespace std;

int n;

struct person {
    int ht, bef;
} arr[10010];
int pos[10010];

bool cmp(const person a, const person b) {
    return a.ht < b.ht;
}

int tree[40040];

void build(int i = 1, int l = 1, int r = n) {
    if (l == r)
        tree[i] = 1;
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void update(int pos, int i = 1, int cl = 1, int cr = n) {
    if (cl == cr && cl == pos) {
        tree[i] = 0;
    }
    else {
        int mid = (cl + cr) / 2;
        if (pos <= mid)
            update(pos, 2*i, cl, mid);
        else
            update(pos, 2*i+1, mid+1, cr);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

int findkth(int x, int kth, int s, int e) {
    if (s == e)
        return s;
    int mid = (s + e) / 2;
    if (tree[2*x] >= kth)
        return findkth(2*x, kth, s, mid);
    else
        return findkth(2*x+1, kth - tree[2*x], mid+1, e);
}
int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i].ht);
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i].bef);
        build();
        sort(arr+1, arr+n+1, cmp);
        for (int i = 1; i <= n; i++) {
            int p = findkth(1, arr[i].bef+1, 1, n);
            update(p);
            pos[p] = arr[i].ht;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", pos[i]);
        printf("\n");
    }
    return 0;
}
