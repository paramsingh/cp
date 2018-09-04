// 22:40

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int a[201000];

int main(void) {
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (a[i] > s)
            ans += abs(a[i] - s);
    }
    if (a[n/2] != s)
        ans += abs(a[n/2] - s);
    for (int i = n / 2 + 1; i < n; i++) {
        if (a[i] < s)
            ans += abs(a[i] - s);
    }
    printf("%lld\n", ans);
    return 0;
}

