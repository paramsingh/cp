#include <bits/stdc++.h>
using namespace std;

class cow {
    public: int milk, time;
} cows[10010];

bool cmp(const cow& a, const cow& b) {
    return a.time > b.time;
}

int end[10010] = {0};

class node {
    public: int m, id;
            node(int a, int b) {
                m = a, id = b;
            }
};

node* tree;

void build(int i, int l, int r) {
    if (l == r) {
        tree[i].m = cows[l].milk;
        tree[i].id = l;
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        if (tree[2*i].m > tree[2*i+1].m) {
            tree[i].m = tree[2*i].m;
            tree[i].id = tree[2*i].id;
        }
        else {
            tree[i].m = tree[2*i+1].m;
            tree[i].id = tree[2*i+1].id;
        }
    }
}

node query(int l, int r, int i, int cl, int cr) {
    if (cl > r || cr < l)
        return node(-1, -1);
    else if (cl >= l && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        node a = query(l, r, 2*i, cl, mid);
        node b = query(l, r, 2*i+1, mid+1, cr);
        return a.m > b.m ? a : b;
    }
}

void rm(int pos, int i, int cl, int cr) {
    if (cl == cr) {
        tree[i].m = -1;
    }
    else {
        int mid = (cl + cr) / 2;
        if (pos <= mid)
            rm(pos, 2*i, cl, mid);
        else
            rm(pos, 2*i+1, mid+1, cr);
        if (tree[2*i].m > tree[2*i+1].m) {
            tree[i].m = tree[2*i].m;
            tree[i].id = tree[2*i].id;
        }
        else {
            tree[i].m = tree[2*i+1].m;
            tree[i].id = tree[2*i+1].id;
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    tree = (node*) calloc(4*n, sizeof(node));
    int m = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &cows[i].milk, &cows[i].time);
        m = max(cows[i].time, m);
    }
    sort(cows+1, cows+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        if (i == n || cows[i].time != cows[i+1].time)
            end[cows[i].time] = i;
    }
    for (int i = m; i >= 1; i--) {
        if (end[i] == 0) {
            end[i] = end[i+1];
        }
    }
    build(1, 1, n);
    int ans = 0;
    for (int i = m; i >= 1; i--) {
        node to = query(1, end[i], 1, 1, n);
        if (to.m != -1) {
            ans += to.m;
            rm(to.id, 1, 1, n);
        }
    }
    printf("%d\n", ans);
    return 0;
}
