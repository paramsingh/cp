#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 10;
const ll infll = 1e18 + 500;
const int unit = (1 << 30) - 1;
struct query {
    int l, r, q;
} questions[100100];

int n, m;
int s[40][100100];
int pref[40][100100];
int a[100100];
int tree[400100];


void build(int i = 1, int cl = 1, int cr = n) {
    if (cl == cr) {
        tree[i] = a[cl];
    }
    else {
        int mid = (cl + cr) / 2;
        build(2*i, cl, mid);
        build(2*i+1, mid+1, cr);
        tree[i] = tree[2*i] & tree[2*i+1];
    }
}

int get(int l, int r, int i = 1, int cl = 1, int cr = n) {
    if (cl > r || cr < l)
        return unit;
    else if (l <= cl && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        return get(l, r, 2*i, cl, mid) & get(l, r, 2*i+1, mid+1, cr);
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &questions[i].l, &questions[i].r, &questions[i].q);
        for (int j = 0; j < 31; j++) {
            if (questions[i].q & (1 << j)) {
                s[j][questions[i].l]++;
                s[j][questions[i].r + 1]--;
            }
        }
    }

    for (int bit = 0; bit < 31; bit++) {
        for (int i = 1; i <= n; i++)
            pref[bit][i] = pref[bit][i - 1] + s[bit][i];
    }

    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit < 31; bit++)
            a[i] |= (pref[bit][i] > 0) << bit;
    }

    build();
    for (int i = 1; i <= m; i++) {
        int l = questions[i].l, r = questions[i].r, q = questions[i].q;
        if (get(l, r) != q) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
