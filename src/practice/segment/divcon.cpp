#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point(int a, int b) {
        x = a, y = b;
    }
    bool operator<(const point& a) const {
        return x < a.x;
    }
};

bool cmp(const point& a, const point& b) {
    return a.y > b.y;
}

int n;
vector<int> a;

int tree[5000];
int lazy[5000];

inline void propagate(int i, int l, int r) {
    if (lazy[i] != 0) {
        tree[i] += lazy[i];
        if (l != r) {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
}

void update(int val, int l, int r, int i = 1, int cl = 1, int cr = 1001) {
    propagate(i, cl, cr);
    if (l > cr || r < cl)
        return;
    else if (cl >= l && cr <= r) {
        tree[i] += val;
        if (l != r) {
            lazy[2*i] += val;
            lazy[2*i+1] += val;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(val, l, r, 2*i, cl, mid);
        update(val, l, r, 2*i+1, mid + 1, cr);
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<point> byx;
        vector<point> byy;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            byx.push_back(point(x, y));
            byy.push_back(point(x, y));
        }
        sort(byx.begin(), byx.end());
        sort(byy.begin(), byy.end(), cmp);
        int c = 0;
        int y = byy[0].y, my = y;
        int i = 0;
        while (i < byy.size()) {
            int y = byy[i].y;
            int s = 0;
            int start = i;
            while (i < byy.size() && byy[i].y == y) {
                s++;
                i++;
            }
            c += s;
            if (i < byy.size()) {
                update(c, byy[i].y + 1, byy[i-1].y);
            }
            else {
                update(c, 1, byy[i-1].y);
            }
        }
        int ans = 0;
        for (int i = 0; i < byx.size();) {
            int x= byx[i].x;
            while (i < byx.size() && x == byx[i].x) {
                int y = byx[i].y;
                update(1, y + 1, 1001);
                update(-1, 1, y);
                i++;
            }
            ans = max(ans, tree[1]);
        }
        printf("%d\n", ans);
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
    }
    return 0;
}

