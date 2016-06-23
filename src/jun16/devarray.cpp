#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(void) {
    int n, q, t;
    scanf("%d %d", &n, &q);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        mn = min(a[i], mn);
        mx = max(a[i], mx);
    }

    while (q--) {
        scanf("%d", &t);
        if (mn <= t && t <= mx)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
