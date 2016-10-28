#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
int a[1001000];
unordered_map<int, int> freq;
pii l[1001000], r[1001000];

int tree[5001000];

void update(int l, int i = 1, int cl = 1, int cr = n) {
    if (cl == cr && l == cl)
        tree[i] = 1;
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update(l, 2*i, cl, mid);
        else
            update(l, 2*i+1, mid + 1, cr);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

int get(int l, int r, int i = 1, int cl = 1, int cr = n) {
    if (cl > r || cr < l || l > r)
        return 0;
    else if (l <= cl && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        return get(l, r, 2*i, cl, mid) + get(l, r, 2*i+1, mid + 1, cr);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        freq[a[i]]++;
        l[i].first = freq[a[i]];
        l[i].second = i;
    }
    freq.clear();
    for (int i = n; i >= 1; i--) {
        freq[a[i]]++;
        r[i].first = freq[a[i]];
        r[i].second = i;
    }
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    int here = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        while (here <= n && r[here].first < l[i].first) {
            update(r[here].second, 1);
            here++;
        }
        ans += get(l[i].second + 1, n);
    }
    printf("%lld\n", ans);
}
