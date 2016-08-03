#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main(void) {
    lli t;
    scanf("%lld", &t);
    int lo = 1, hi = 50;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        lli t1 = 3 * ((1LL << mid) - 1);
        if (t1 < t)
            lo = mid + 1;
        else
            hi = mid;
    }

    lli t1 = 3 * ((1LL << lo) - 1);
    printf("%lld\n", t1 - t + 1);
    return 0;
}
