#include <stdio.h>

int main(void) {
    int t, s, q;
    scanf("%d%d%d", &t, &s, &q);
    int ans = 1;
    while (s*q < t) {
        ans++;
        s *= q;
    }
    printf("%d\n", ans);
    return 0;
}
