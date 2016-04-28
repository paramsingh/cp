#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int arr[1000100];
lli sums[1000100];

int main(void) {
    int n;
    lli m;
    scanf("%d %lld", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+n);
    sums[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
        sums[i] = arr[i] + sums[i+1];
    lli lo = 1, hi = 3000000000;
    // find the first instance of wood cut being less than m
    while (lo < hi) {
        lli mid = (lo + hi) / 2;
        int id = lower_bound(arr, arr+n, mid) - arr;
        lli wood = sums[id] - (mid * (n - id));
        if (wood < m)
            hi = mid;
        else
            lo = mid + 1;
    }
    // last instance of wood being greater than or equal to m = lo - 1
    printf("%lld\n", lo - 1);
    return 0;
}
