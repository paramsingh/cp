#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int a[1001000];
ll tree[4001000];
int dp[4001000];
vector<pii> order;
int n;

void update(int id, int val, int i = 1, int cl = 1, int cr = n) {
    if (cl == cr && id == cl)
        tree[i] = val;
    else {
        int mid = (cl + cr) / 2;
        if (id <= mid)
            update(id, val, 2*i, cl, mid);
        else
            update(id, val, 2*i+1, mid+1, cr);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

ll get(int l, int r, int i = 1, int cl = 1, int cr = n) {
    if (cl > r || cr < l || l > r)
        return 0;
    else if (l <= cl && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        return get(l, r, 2*i, cl, mid) + get(l, r, 2*i+1, mid+1, cr);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        order.push_back(make_pair(a[i], i));
    }
    sort(order.begin(), order.end());
    for (int i = 0; i < n; i++) {
        int x = order[i].first, id = order[i].second;
        ll cnt = get(id + 1, n);
        update(id, 1);
        dp[id] = cnt;
    }
    ll ans = 0;
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < n; i++) {
        int x = order[i].first, id = order[i].second;
        ll cnt = get(id + 1, n);
        ans += cnt;
        update(id, dp[id]);
    }
    printf("%lld\n", ans);
}
