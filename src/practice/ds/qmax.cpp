#include <bits/stdc++.h>
using namespace std;

struct node {
    int val, pr;
    int ans;
    int l, r;
    int size;
} tree[500100];

inline int scanint() {
    register int x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar_unlocked();
    }
    return x;
}

int root = 0, nxt = 1;

void update(int id) {
    if (id == 0) return;
    int lc = tree[id].l, rc = tree[id].r;
    tree[id].size = 1 + tree[lc].size + tree[rc].size;
    tree[id].ans = max(tree[id].val, max(tree[lc].ans, tree[rc].ans));
}

void split(int pos, int id, int& l, int& r, int add = 0) {
    if (id == 0)
        l = r = 0;
    else {
        int lc = tree[id].l, rc = tree[id].r;
        int cur_pos = add + tree[lc].size + 1;
        if (cur_pos <= pos) {
            split(pos, tree[id].r, tree[id].r, r, cur_pos);
            l = id;
        }
        else {
            split(pos, tree[id].l, l, tree[id].l, add);
            r = id;
        }
    }
    update(id);
}

void merge(int& root, int l, int r) {
    if (l == 0 || r == 0)
        root = l == 0 ? r : l;
    else {
        if (tree[l].pr > tree[r].pr) {
            merge(tree[l].r, tree[l].r, r);
            root = l;
        }
        else {
            merge(tree[r].l, l, tree[r].l);
            root = r;
        }
    }
    update(root);
}

int k = 0;
void insert(int x, int y) {
    k++;
    int id = nxt++;
    tree[id].val = y;
    tree[id].pr = rand();
    if (x == 1) {
        merge(root, id, root);
        return;
    }
    if (x == k) {
        merge(root, root, id);
        return;
    }
    int a, b, c;
    split(x - 1, root, a, c);
    merge(a, a, id);
    merge(root, a, c);
}

int get(int x, int y) {
    int a, b, c;
    if (x == 1 && y == k)
        return tree[root].ans;
    else if (x == 1) {
        split(y, root, a, b);
        int ans = tree[a].ans;
        merge(root, a, b);
        return ans;
    }
    else if (y == k) {
        split(x - 1, root, a, b);
        int ans = tree[b].ans;
        merge(root, a, b);
        return ans;
    }
    else {
        split(x - 1, root, a, b);
        split(y - x + 1, b, b, c);
        int ans = tree[b].ans;
        merge(b, b, c);
        merge(root, a, b);
        return ans;
    }
}

int main(void) {
    srand(time(NULL));
    tree[0].ans = INT_MIN;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char type = getchar_unlocked();
        while (type != 'A' && type != 'Q')
            type = getchar_unlocked();
        int x = scanint(), y = scanint();
        if (type == 'A') {
            insert(y, x);
        }
        else {
            printf("%d\n", get(x, y));
        }
    }
    return 0;
}
