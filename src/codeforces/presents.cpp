#include <bits/stdc++.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n % 3 != 0)
        printf("%d", (n / 3) * 2 + 1);
    else
        printf("%d", (n / 3) * 2);
    return 0;
}
