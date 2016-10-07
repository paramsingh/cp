#include <bits/stdc++.h>
using namespace std;

set<int> freq;
int nodes = 1;
int root = 0;

struct node {
    int val, pr;
    int size;
    int l, r;
} tree[200100];

void update_size(int id) {
    if (id == 0)
        return;
    int lc = tree[id].l, rc = tree[id].r;
    tree[id].size = tree[lc].size + tree[rc].size + 1;
}

void split(int val, int id, int& l, int& r) {
    if (id == 0)
        l = r = 0;
    else if (tree[id].val < val) {
        split(val, tree[id].r, tree[id].r, r);
        l = id;
    }
    else {
        split(val, tree[id].l, l, tree[id].l);
        r = id;
    }
    update_size(id);
}

void merge(int& t, int l, int r) {
    if (l == 0 || r == 0)
        t = (l == 0) ? r : l;
    else if (tree[l].pr > tree[r].pr) {
        merge(tree[l].r, tree[l].r, r);
        t = l;
    }
    else {
        merge(tree[r].l, l, tree[r].l);
        t = r;
    }
    update_size(t);
}

void insert(int id, int& root) {
    if (root == 0)
        root = id;
    else if (tree[root].pr < tree[id].pr) {
        split(tree[id].val, root, tree[id].l, tree[id].r);
        root = id;
    }
    else
        insert(id, tree[id].val < tree[root].val ? tree[root].l : tree[root].r);
    update_size(root);
}

void erase(int& root, int val) {
    if (root == 0)
        return;
    else if (tree[root].val == val) {
        merge(root, tree[root].l, tree[root].r);
    }
    else {
        erase(val < tree[root].val ? tree[root].l : tree[root].r, val);
    }
    update_size(root);
}

int smaller(int val, int root) {
    if (root == 0)
        return 0;
    if (tree[root].val >= val)
        return smaller(val, tree[root].l);
    else
        return 1 + tree[tree[root].l].size + smaller(val, tree[root].r);
}

int kth(int k, int root) {
    int lc = tree[root].l, rc = tree[root].r;
    if (tree[lc].size + 1 == k)
        return tree[root].val;
    if (tree[lc].size + 1 < k) {
        return kth(k - tree[lc].size - 1, rc);
    }
    else {
        return kth(k, lc);
    }
}

int main(void) {
    srand(time(NULL));
    int q;
    scanf("%d", &q);
    while (q--) {
        char s[10];
        int val;
        scanf("%s %d", s, &val);
        char type = s[0];
        if (type == 'I') {
            if (freq.count(val))
                continue;
            tree[nodes].val = val;
            tree[nodes].pr = rand();
            insert(nodes, root);
            nodes++;
            freq.insert(val);
        }
        else if (type == 'D') {
            if (freq.count(val)) {
                erase(root, val);
                freq.erase(val);
            }
        }
        else if (type == 'K') {
            if (val > tree[root].size)
                printf("invalid\n");
            else
                printf("%d\n", kth(val, root));
        }
        else if (type == 'C') {
            printf("%d\n", smaller(val, root));
        }
    }
    return 0;
}
