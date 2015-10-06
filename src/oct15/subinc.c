// Author: Param Singh <paramsingh258@gmail.com>
// Count Subarrays: https://www.codechef.com/OCT15/problems/SUBINC

#include <stdio.h>
int main(void) {
    int t;
    scanf("%d", &t);
    int a;
    for (a = 0; a < t; a++) {
        int n;
        scanf("%d", &n);
        int i;
        long long int x, count = 1, ans = 0, prev;
        scanf("%lld", &prev);
        for (i = 1; i < n; i++) {
            scanf("%lld", &x);
            if (x >= prev) {
                count++;
            }
            else {
                ans += count * (count + 1) / 2;
                count = 1;
            }
            prev = x;
        }
        ans += count * (count + 1) / 2;
        printf("%lld\n", ans);
    }
}
