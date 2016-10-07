#include <bits/stdc++.h>
using namespace std;

struct node {
    int val, pr;
    int l, r;
    int size;
    int lazy;
} tree[1000100];

int root = 0, nxt = 1;

void update_size(int id) {
    if (id != 0) {
        int lc = tree[id].l, rc = tree[id].r;
        tree[id].size = tree[lc].size + 1 + tree[rc].size;
    }
}

void propagate(int id) {
    if (id != 0 && tree[id].lazy == 1) {
        int lc = tree[id].l, rc = tree[id].r;
        if (lc != 0) {
            tree[lc].lazy ^= 1;
        }
        if (rc != 0) {
            tree[rc].lazy ^= 1;
        }
        swap(tree[id].l, tree[id].r);
        tree[id].lazy = 0;
    }
}

void split(int root, int val, int &l, int &r, int add = 0) {
    propagate(root);
    if (root == 0) {
        l = r = 0;
        return;
    }
    int lc = tree[root].l, rc = tree[root].r;
    if (add + tree[lc].size + 1 <= val) {
        split(rc, val, tree[root].r, r, add + tree[lc].size + 1);
        l = root;
    }
    else {
        split(lc, val, l, tree[root].l, add);
        r = root;
    }
    update_size(root);
}

void merge(int &root, int l, int r) {
    propagate(l);
    propagate(r);
    if (l == 0 || r == 0)
        root = (l == 0) ? r : l;
    else if (tree[l].pr > tree[r].pr) {
        merge(tree[l].r, tree[l].r, r);
        root = l;
    }
    else {
        merge(tree[r].l, l, tree[r].l);
        root = r;
    }
    update_size(root);
}

int get(int pos, int root, int add = 0) {
    propagate(root);
    if (root == 0)
        return -1;

    int lc = tree[root].l, rc = tree[root].r;
    int cur_pos = add + tree[lc].size + 1;
    if (cur_pos == pos)
        return tree[root].val;
    else if (cur_pos < pos)
        return get(pos, tree[root].r, cur_pos);
    else
        return get(pos, tree[root].l, add);
}

void inorder(int id) {
    propagate(id);
    if (id == 0) return;
    inorder(tree[id].l);
    printf("%d ", tree[id].val);
    inorder(tree[id].r);
}

void shuffle(int a, int b, int c) {
    int topa, topb, topc;
    topa = topb = topc = 0;
    split(root, a, topa, root);
    split(root, b, topb, root);
    merge(root, topa, root);
    split(root, c, topc, root);
    if (topb != 0)
        tree[topb].lazy ^= 1;
    merge(root, topb, root);
    merge(root, topc, root);
}

int main(void) {
    srand(time(NULL));
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        tree[nxt].val = i;
        tree[nxt].pr = rand();
        merge(root, root, nxt);
        nxt++;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        shuffle(a, b, c);
    }
    inorder(root);
}
