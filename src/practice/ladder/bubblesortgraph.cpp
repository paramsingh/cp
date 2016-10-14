#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;

int tree[500100];
int n;

int update(int l, int val, int i = 1, int cl = 1, int cr = n) {
    if (cl == cr) {
        tree[i] = max(val, tree[i]);
    }
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update(l, val, 2*i, cl, mid);
        else
            update(l, val, 2*i+1, mid + 1, cr);
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }
}

int get(int l, int r, int i = 1, int cl = 1, int cr = n) {
    if (cl > r || cr < l)
        return 0;
    else if (l <= cl && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        return max(get(l, r, 2*i, cl, mid), get(l, r, 2*i+1, mid + 1, cr));
    }
}

int a[100100];
int dp[100100];

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    for (int i = 1; i <= n; i++) {
        int x = get(1, a[i] - 1);
        dp[i] = x + 1;
        update(a[i], dp[i]);
    }
    printf("%d\n", get(1, n));
    return 0;
}
