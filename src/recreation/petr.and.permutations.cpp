#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001000];
int pos[1001000];
int tree[5001000];

int update(int l, int i = 1, int cl=1, int cr=n) {
    if (cl == cr && cr == l)
        tree[i] = 1;
    else {
        int mid = (cl + cr) / 2;
        if (l <= mid)
            update(l, 2*i,  cl, mid);
        else
            update(l, 2*i+1, mid+1, cr);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

int sum(int l, int r, int i = 1, int cl=1, int cr=n) {
    if (cl > r || cr < l || cl > cr)
        return 0;
    else if (l <= cl && cr <= r)
        return tree[i];
    else {
        int mid = (cl + cr) / 2;
        return sum(l, r, 2*i, cl, mid) + sum(l, r, 2*i+1, mid+1, cr);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int inv = 0;
    for (int i = n; i >= 1; i--) {
        inv = (inv + sum(1, a[i])) % 2;
        update(a[i]);
    }
    if (inv == ((3 * n) % 2))
        printf("Petr\n");
    else
        printf("Um_nik\n");
    return 0;
}

