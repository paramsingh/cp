// 1:21
#include <bits/stdc++.h>

int bit[100100] = {0};

void update(int pos, int val) {
    while (pos <= 100001) {
        bit[pos] += val;
        pos += pos & -pos;
    }
}

int get(int pos) {
    int ans = 0;
    while (pos > 0) {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

int a[100100];
int pos[100100];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    long long int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i - 1 - get(a[i]);
        update(a[i], 1);
    }
    long long int mn = ans;
    for (int i = 1; i <= n; i++) {
        ans -= pos[i] - 1;
        ans += n - pos[i];
        if (ans < mn)
            mn = ans;
    }
    printf("%lld\n", mn);
    return 0;
}
