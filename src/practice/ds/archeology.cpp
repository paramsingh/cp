#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
int n, c;

vector<int> strings[500100];

int tree[5001000];
int lazy[5001000];

void propagate(int i, int cl, int cr) {
    if (lazy[i]) {
        if (cl == cr)
            tree[i] = 1;
        else
            lazy[2*i] = lazy[2*i+1] = 1;
        lazy[i] = 0;
    }
}

void update(int l, int r, int i = 1, int cl = 0, int cr = c - 1) {
    propagate(i, cl, cr);
    if (cl > r || cr < l || l > r)
        return;
    else if (l <= cl && cr <= r) {
        if (cl == cr)
            tree[i] = 1;
        else {
            lazy[2*i] = lazy[2*i+1] = 1;
        }
    }
    else {
        int mid = (cl + cr) / 2;
        update(l, r, 2*i, cl, mid);
        update(l, r, 2*i+1, mid+1, cr);
    }
}

int get(int l, int i = 1, int cl = 0, int cr = c - 1) {
    propagate(i, cl, cr);
    if (cl == cr)
        return tree[i];
    int mid = (cl + cr) / 2;
    return (l <= mid) ? get(l, 2*i, cl, mid) : get(l, 2*i+1, mid + 1, cr);
}

int main(void) {
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++) {
        int l;
        scanf("%d", &l);
        strings[i].resize(l);
        for (int j = 0; j < l; j++) {
            scanf("%d", &strings[i][j]);
            strings[i][j]--;
        }
    }
    for (int i = 1; i < n; i++) {
        int here = 0;
        while (here < strings[i].size() && here < strings[i+1].size() && strings[i][here] == strings[i+1][here])
            here++;
        if (here == strings[i].size())
            continue;
        else if (here == strings[i + 1].size()) {
            printf("-1\n");
            return 0;
        }
        else {
            int x = strings[i][here], y = strings[i + 1][here];
            if (strings[i][here] > strings[i+1][here]) {
                update(0, c - x - 1);
                update(c - y, c - 1);
            }
            else
                update(c - y, c - x - 1);
        }
    }
    for (int i = 0; i < c; i++) {
        if (get(i) == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
