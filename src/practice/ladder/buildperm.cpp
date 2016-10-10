#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[400100];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(i + 1 - a[i]);
    printf("%lld\n", ans);
    return 0;
}
