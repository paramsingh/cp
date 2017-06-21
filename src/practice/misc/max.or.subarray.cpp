#include <bits/stdc++.h>
using namespace std;

int cnt[40];
int n, max_or;
int a[101000];

void change(int x, int sign) {
    for (int i = 0; i < 30; i++)
        cnt[i] += sign * ((x >> i) & 1);
}

int get() {
    int val = 0;
    for (int i = 0; i < 30; i++)
        if (cnt[i] > 0)
            val |= (1 << i);
    return val;
}


int check(int l) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= l; i++)
        change(a[i], +1);
    if (get() == max_or) return 1;
    for (int remove = 1, add = l + 1; add <= n; add++, remove++) {
        change(a[remove], -1);
        change(a[add], +1);
        if (get() == max_or) return 1;
    }
    return 0;
}


int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        max_or |= a[i];
    }
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%d\n", lo);
}
