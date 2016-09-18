#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];
        int i;
        for (i = 0; i < n; i++) {
            scanf("%d", a+i);
        }
        int flag = 0;
        for (i = 1; i < n; i++) {
            int d = i;
            int c = 0;
            while (d > 0 && a[d] < a[d-1]) {
                int t = a[d];
                a[d] = a[d-1];
                a[d-1] = t;
                d--;
                c++;
                if (c > 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
