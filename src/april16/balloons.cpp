#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long int r, g, b, k;
        scanf("%lld %lld %lld", &r, &g, &b);
        scanf("%lld", &k);
        long long int ans = 0;
        ans += min(r, k-1) + min(g, k-1) + min(b, k-1);
        ans++;
        printf("%lld\n", ans);
    }
    return 0;
}
