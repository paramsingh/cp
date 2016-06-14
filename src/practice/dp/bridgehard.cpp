#include <bits/stdc++.h>
using namespace std;

int tree[1000000];

int un;
vector<pair<int, int> > bridges;

int query(int l, int r, int i = 1, int cl = 0, int cr = un) {
    if (r < cl || l > cr)
        return -1;
    else if (cl >= l && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        int left = query(l, r, 2*i, cl, mid);
        int right = query(l, r, 2*i + 1, mid + 1, cr);
        return max(left, right);
    }
}

int update(int id, int val, int i = 1, int cl = 0, int cr = un) {
    if (id == cl && cl == cr)
        tree[i] = val;
    else {
        int mid = (cl + cr) / 2;
        if (id <= mid)
            update(id, val, 2*i, cl, mid);
        else
            update(id, val, 2*i+1, mid+1, cr);
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }
}

int a[100100];
int b[100100];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        bridges.clear();
        vector<int> num;
        vector<int> h;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
            num.push_back(a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", b+i);
            num.push_back(b[i]);
        }
        for (int i = 0; i < n; i++)
            bridges.push_back(make_pair(a[i], b[i]));
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ) {
            int x = num[i];
            h.push_back(x);
            while (num[i] == x)
                i++;
        }
        un = h.size();
        sort(bridges.begin(), bridges.end());
        int sol = 0;
        for (int i = 0; i < bridges.size(); i++) {
            int val = bridges[i].second;
            int lo = 0, hi = h.size() - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (h[mid] >= val)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            int x = lo;
            int mx = query(0, x);
            sol = max(sol, mx + 1);
            if (mx + 1 > query(x, x))
                update(x, mx + 1);
        }
        printf("%d\n", sol);
        memset(tree, 0, sizeof(tree));
    }
    return 0;
}
