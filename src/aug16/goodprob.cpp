#include <bits/stdc++.h>
using namespace std;


int a[100100];
long long ans = 0;

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        int mx = a[i];
        for (int j = i + 1; j < n; j++) {
            mx = max(mx, a[j]);
            if ((a[i] & a[j]) == a[i])
                ans += mx;
            else if ((a[i] & a[j]) == a[j])
                ans += mx;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
