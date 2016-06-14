#include <bits/stdc++.h>

int a[10010];
int b[10010];
int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", a+i);
        for (int i = 1; i <= n; i++) {
            scanf("%d", b+i);
            if (a[i] - a[i-1] >= b[i])
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
