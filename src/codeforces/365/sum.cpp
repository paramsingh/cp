#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> pos;


struct query {
    int l, r;
    int i;
    query(int a, int b, int c) {
        l = a, r = b, i = c;
    }
    bool operator<(const query& a) const {
        return r < a.r;
    }
};

vector<query> q;

int a[1000100];
int ans[1000100];
int cnt[1000100];
int x[1000100];
int n, k;

struct node {
    int take;
    int val;
} tree[4001000];

void update(int val, int l, int i = 1, int cl = 0, int cr = n - 1) {
    if (l == cl && cl == cr) {
        tree[i].take = val;
        tree[i].val = (val == 1) ? a[l] : 0;
    }
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update(val, l, 2*i, cl, mid);
        else
            update(val, l, 2*i+1, mid + 1, cr);
        tree[i].val = tree[2*i].val ^ tree[2*i+1].val;
    }
}

int get(int l, int r, int i = 1, int cl = 0, int cr = n - 1) {
    if (l > cr || r < cl)
        return 0;
    else if (cl >= l && cr <= r)
        return tree[i].val;
    else {
        int mid = (cl + cr) / 2;
        int left = get(l, r, 2*i, cl, mid);
        int right = get(l, r, 2*i + 1, mid + 1, cr);
        return left ^ right;
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    x[0] = a[0];
    for (int i = 1; i < n; i++)
        x[i] = a[i] ^ x[i - 1];
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        q.push_back(query(l, r, i));
    }
    sort(q.begin(), q.end());
    int qi = 0;
    for (int i = 0; i < n; i++) {
        if (pos.count(a[i]) > 0)
            update(0, pos[a[i]]);
        pos[a[i]] = i;
        update(1, i);
        int sol;
        while (qi < k && q[qi].r == i) {
            int l = q[qi].l, r = q[qi].r;
            sol = get(q[qi].l, q[qi].r);
            sol ^= x[l - 1] ^ x[r];
            ans[q[qi].i] = sol;
            qi++;
        }
    }
    for (int i = 0; i < k; i++)
        printf("%d\n", ans[i]);
    return 0;
}


