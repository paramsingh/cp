#include <bits/stdc++.h>
using namespace std;

int tree[5000000];
int k, n;

int query(int val, int i = 1, int cl = 1, int cr = n) {
    if (cl == cr)
        return cl;
    else {
        int mid = (cl + cr) / 2;
        if (tree[2*i] + val <= k)
            query(val, 2*i, cl, mid);
        else
            query(val, 2*i + 1, mid + 1, cr);
    }
}

void update(int val, int l, int i = 1, int cl = 1, int cr = n) {
    if (cl == cr && cr == l)
        tree[i] += val;
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update(val, l, 2*i, cl, mid);
        else
            update(val, l, 2*i+1, mid + 1, cr);
        tree[i] = min(tree[2*i], tree[2*i+1]);
    }
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(tree, 0, sizeof(tree));
        scanf("%d", &k);
        scanf("%d", &n);
        int used = 0;
        int total = 0;
        for (int i = 0; i < n;) {
            char c = getchar_unlocked();
            while ((c < '0' || c > '9') && c != 'b')
                c = getchar_unlocked();
            int v = 0;
            int cnt = 0;
            if (c == 'b') {
                while (c < '0' || c > '9')
                    c = getchar_unlocked();
                while (c >= '0' && c <= '9') {
                    cnt = cnt * 10 + c - '0';
                    c = getchar_unlocked();
                }
                c = getchar_unlocked();
                while (c < '0' || c > '9')
                    c = getchar_unlocked();
                while (c >= '0' && c <= '9') {
                    v = v * 10 + c - '0';
                    c = getchar_unlocked();
                }
            }
            else {
                cnt = 1;
                while (c >= '0' && c <= '9') {
                    v = v * 10 + c - '0';
                    c = getchar_unlocked();
                }
            }
            i += cnt;
            total += cnt * v;
            while (cnt--) {
                int pos = query(v);
                used = max(pos, used);
                update(v, pos);
            }
        }
        printf("%d %d\n", used, k * used - total);
    }
    return 0;
}

