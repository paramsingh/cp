#include <stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    while (n != -1) {
        int a[n];
        int i;
        int sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", a+i);
            sum += a[i];
        }
        if (sum % n != 0)
            printf("-1\n");
        else {
            int av = sum / n, ans = 0;
            for (i = 0; i < n; i++) {
                if (a[i] > av)
                    ans += a[i] - av;
            }
            printf("%d\n", ans);
        }
        scanf("%d", &n);
    }
    return 0;
}
