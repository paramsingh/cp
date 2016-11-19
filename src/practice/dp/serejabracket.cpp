#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const int mod = 1e9 + 7;

struct node {
    int ans, open, closed;
    node() {
        ans = open = closed = 0;
    }
    node(int a, int b, int c) {
        ans = a, open = b, closed = c;
    }
} tree[4001000];

char s[1001000];
int n;

void build(int i = 1, int cl = 1, int cr = n) {
    if (cl == cr) {
        if (s[cl] == '(')
            tree[i].open++;
        else
            tree[i].closed++;
    }
    else {
        int mid = (cl + cr) / 2;
        build(2*i, cl, mid);
        build(2*i+1, mid + 1, cr);
        int temp = min(tree[2*i].open, tree[2*i+1].closed);
        tree[i].ans = tree[2*i].ans + tree[2*i+1].ans + temp * 2;
        tree[i].open = tree[2*i].open + tree[2*i+1].open - temp;
        tree[i].closed = tree[2*i].closed + tree[2*i + 1].closed - temp;
    }
}

node get(int l, int r, int i = 1, int cl = 1, int cr = n) {
    if (cl > r || cr < l)
        return node();
    else if (l <= cl && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        node left = get(l, r, 2*i, cl, mid);
        node right = get(l, r, 2*i+1, mid + 1, cr);
        int ans, open, closed;
        int temp = min(left.open, right.closed);
        ans = left.ans + right.ans + temp * 2;
        open = left.open + right.open - temp;
        closed = left.closed + right.closed - temp;
        return node(ans, open, closed);
    }
}
int main(void) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    build();

    int t;
    scanf("%d", &t);
    while (t--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", get(l, r).ans);
    }
    return 0;
}
