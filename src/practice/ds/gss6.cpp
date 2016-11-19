#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = INT_MIN;

struct node {
    int val, pr;
    int lsum, rsum, ans, sum;
    int l, r;
    int size;
} tree[500100];

int root = 0, nxt = 1;
int a[100100];

inline void operate(int id) {
    if (id == 0)
        return;
    tree[id].lsum = tree[id].rsum = tree[id].sum = tree[id].ans = tree[id].val;
    int lc = tree[id].l, rc = tree[id].r;
    tree[id].size = 1 + tree[lc].size + tree[rc].size;
    tree[id].sum = tree[lc].sum + tree[id].val + tree[rc].sum;
    tree[id].ans = max(max(tree[lc].ans, tree[rc].ans), max(0, tree[lc].rsum) + tree[id].val + max(0, tree[rc].lsum));
    tree[id].lsum = max(tree[lc].lsum, tree[lc].sum + tree[id].val + max(0, tree[rc].lsum));
    tree[id].rsum = max(tree[rc].rsum, max(0, tree[lc].rsum) + tree[id].val + tree[rc].sum);
}

void split(int pos, int root, int& l, int& r, int add = 0) {
    if (root == 0)
        l = r = 0;
    else {
        int lc = tree[root].l, rc = tree[root].r;
        int cur_pos = add + tree[lc].size + 1;
        if (cur_pos <= pos) {
            split(pos, tree[root].r, tree[root].r, r, cur_pos);
            l = root;
        }
        else {
            split(pos, tree[root].l, l, tree[root].l, add);
            r = root;
        }
    }
    operate(root);
}

void merge(int& root, int l, int r) {
    if (l == 0 || r == 0)
        root = (l == 0) ? r : l;
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
    operate(root);
}

void inorder(int id) {
    if (id == 0)
        return;
    inorder(tree[id].l);
    printf("%d ", tree[id].val);
    inorder(tree[id].r);
}

int n;

void insert(int x, int y) {
    int id = nxt++;
    tree[id].val = y;
    tree[id].pr = rand();
    tree[id].lsum = tree[id].rsum = tree[id].sum = tree[id].ans = y;
    int a, b;
    if (x == 1) {
        merge(root, id, root);
        return;
    }
    if (x == n) {
        merge(root, root, id);
        return;
    }
    split(x - 1, root, a, b);
    merge(a, a, id);
    merge(root, a, b);
}

void erase(int x) {
    int a, b, c;
    if (x == n) {
        split(x - 1, root, root, b);
        return;
    }
    if (x == 1) {
        split(1, root, a, root);
        return;
    }
    split(x, root, a, c);
    split(x - 1, a, a, b);
    merge(root, a, c);
}

void replace(int x, int y) {
    int a, b, c;
    if (x == 1) {
        split(1, root, a, root);
        tree[a].val = tree[a].lsum = tree[a].rsum = tree[a].ans = tree[a].sum = y;
        merge(root, a, root);
        return;
    }
    if (x == n) {
        split(x - 1, root, root, a);
        tree[a].val = tree[a].lsum = tree[a].rsum = tree[a].ans = tree[a].sum = y;
        merge(root, root, a);
        return;
    }
    split(x, root, a, c);
    split(x - 1, a, a, b);
    tree[b].val = tree[b].lsum = tree[b].rsum = tree[b].ans = tree[b].sum = y;
    merge(a, a, b);
    merge(root, a, c);
}

int get(int x, int y) {
    int a, b, c;
    if (x == 1 && y == n) {
        return tree[root].ans;
    }
    else if (x == 1) {
        split(y, root, a, b);
        int ans = tree[a].ans;
        merge(root, a, b);
        return ans;
    }
    else if (y == n) {
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
    scanf("%d", &n);
    tree[0].ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        tree[nxt].val = a[i];
        tree[nxt].pr = rand();
        tree[nxt].lsum = tree[nxt].rsum = tree[nxt].sum = tree[nxt].ans = a[i];
        merge(root, root, nxt);
        nxt++;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        char s[10];
        int x, y;
        scanf("%s", s);
        if (s[0] == 'I') {
            scanf("%d %d", &x, &y);
            insert(x, y);
            n++;
        }
        else if (s[0] == 'D') {
            scanf("%d", &x);
            erase(x);
            n--;
        }
        else if (s[0] == 'R') {
            scanf("%d %d", &x, &y);
            replace(x, y);
        }
        else if (s[0] == 'Q') {
            scanf("%d %d", &x, &y);
            printf("%d\n", get(x, y));
        }
    }
    return 0;
}
