#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 1e9 + 8;
const ll infll = 1e18;


int n;
ll a[500100];

int main(void) {
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += abs(a[i]);
    }
    if (n == 1) {
        printf("%lld\n", a[1]);
        return 0;
    }
    if (n == 2) {
        printf("%lld\n", max(a[1] - a[2], a[2] - a[1]));
        return 0;
    }
    ll mn = infll;
    int id;
    for (int i = 1; i < n; i++) {
        ll small = min(a[i], a[i + 1]);
        ll big = max(a[i], a[i + 1]);
        ll loss = abs(small) + abs(big) - abs(small - big);
        if (mn > loss) {
            id = i;
            mn = loss;
        }
    }
    printf("%lld\n", sum - mn);
    return 0;
}

