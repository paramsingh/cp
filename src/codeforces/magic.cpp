#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;


lli n, k;
lli need[100100];
lli have[100100];
lli a[100100];

int valid(lli val) {
    for (int i = 0; i < n; i++) {
        a[i] = need[i] * val;
    }
    lli total = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > have[i]) {
            total += a[i] - have[i];
            if (total > k)
                return 1;
        }
    if (total > k)
        return 1;
    else
        return 0;
}

int main(void) {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> need[i];
    for (int i = 0; i < n; i++)
        cin >> have[i];
    lli lo = 0, hi = 1e10;
    while (lo < hi) {
        lli mid = lo + (hi - lo) / 2;
        if (valid(mid)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << (lo - 1) << endl;
    return 0;
}

