#include <bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int l[100100];
int r[100100];

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    if (n == 1) {
        printf("1\n");
        return 0;
    }

    l[1] = 1;
    for (int i = 2; i <= n; i++)
        l[i] = a[i] > a[i - 1] ? l[i - 1] + 1 : 1;

    r[n] = 1;
    for (int i = n - 1; i >= 1; i--)
        r[i] = a[i + 1] > a[i] ? r[i + 1] + 1 : 1;

    int ans = 2;
    for (int i = 1; i <= n; i++) {
        if (2 <= i && i <= n - 1 && a[i - 1] < a[i + 1] - 1)
            ans = max(ans, l[i - 1] + 1 + r[i + 1]);
        else
            ans = max(ans, 1 + max(l[i - 1], r[i + 1]));
    }
    printf("%d\n", ans);
    return 0;
}
