#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 1e9;
int n, k;

int p[100100], a[100100];
pii tree[500100];
pii dp[150010];
int amx;
vector<int> pr, un;

inline int id(int val) {
    int lo = 0, hi = un.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (un[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (un[lo] < val) return un.size();
    return lo;
}

void update(int l, int mn, int mx, int i = 1, int cl = 0, int cr = un.size() - 1) {
    if (cl == cr) {
        tree[i].first = min(mn, tree[i].first);
        tree[i].second = max(mx, tree[i].second);
    }
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update(l, mn, mx, 2*i, cl, mid);
        else
            update(l, mn, mx, 2*i+1, mid+1, cr);
        tree[i].first = min(tree[2*i].first, tree[2*i+1].first);
        tree[i].second = max(tree[2*i].second, tree[2*i+1].second);
    }
}

pii get(int l, int r, int i = 1, int cl = 0, int cr = un.size() - 1) {
    if (l > r)
        return make_pair(inf, -inf);
    if (l <= cl && cr <= r)
        return tree[i];
    else if (cl > r || cr < l)
        return make_pair(inf, -inf);
    else {
        int mid = (cl + cr) / 2;
        pii left = get(l, r, 2*i, cl, mid);
        pii right = get(l, r, 2*i+1, mid+1, cr);
        int mn = min(left.first, right.first);
        int mx = max(left.second, right.second);
        return make_pair(mn, mx);
    }
}

int check(int val) {
    for (int i = 0; i < (un.size() << 2); i++)
        tree[i] = make_pair(inf, -inf);
    dp[1] = make_pair(1, 1);
    update(id(p[1]), dp[1].first, dp[1].second);
    for (int i = 2; i <= n; i++) {
        pii x = get(id(p[i] - val), un.size() - 1);
        x.first += 1;
        x.second += 1;
        dp[i] = x;
        update(id(p[i]), dp[i].first, dp[i].second);
    }
    return dp[n].first <= k && k <= dp[n].second;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            p[i] = p[i - 1] + a[i];
            pr.push_back(p[i]);
        }
        sort(pr.begin(), pr.end());
        for (int i = 0; i < pr.size(); ) {
            int x = pr[i];
            un.push_back(x);
            while (i < pr.size() && x == pr[i])
                i++;
        }
        int lo = -inf, hi = +inf;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        printf("%d\n", lo);
        pr.clear(); un.clear();
    }
}
