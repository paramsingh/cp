#include <bits/stdc++.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n;
        scanf("%d %d", &m, &n);
        if (m % 2 == 0 || n % 2 == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
