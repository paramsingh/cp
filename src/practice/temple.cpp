#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int scan() {
    register int c = getchar_unlocked();
    int x = 0;
    while (c < '0' || c > '9')
        c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar_unlocked();
    }
    return x;
}

pii p[100100];
int bit[100100] = {0};
int n, max1;

void update(int idx, int val) {
    while (idx <= max1) {
        bit[idx] += val;
        idx += (idx) & (-idx);
    }
}

void update_r(int l, int r, int val) {
    update(l, val);
    update(r+1, -val);
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int ids[100100];
int pos[100100];

int lb(int val) {
    int lo = 1, hi = n;
    if (query(hi) < val)
        return n+1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (query(mid) >= val)
            hi = mid;
        else
            lo = mid+1;
    }
    return lo;
}

int main(void) {
    n = scan();
    int q = scan();
    for (int i = 1; i <= n; i++) {
        p[i].first = scan();
        p[i].second = i;
    }
    max1 = n;
    sort(p+1, p+n+1);
    for (int i = 1; i <= n; i++) {
        ids[p[i].second] = i;
        pos[i] = p[i].second;
    }
    p[0].first = 0;
    for (int i = 1; i <= n; i++)
        update(i, p[i].first - p[i-1].first);
    while (q--) {
        int type = scan(), x = scan();
        switch(type) {
            case 1: {
                int y = query(ids[x]);
                int z = pos[lb(y+1) -1];
                swap(ids[x], ids[z]);
                pos[ids[x]] = x;
                pos[ids[z]] = z;
                update_r(ids[x], ids[x], 1);
                break;
            }
            case 2: {
                printf("%d\n", n+1-lb(x));
                break;
            }
            case 3: {
                update(lb(x), -1);
                break;
            }
        }
    }
    return 0;
}
