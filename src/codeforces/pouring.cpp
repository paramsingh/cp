#include <bits/stdc++.h>
#define pi 3.14159265358979323846

int main(void) {
    int d, h, v, e;
    scanf("%d %d %d %d", &d, &h, &v, &e);
    double s = (4 * v) / (pi * d * d);
    double ans = (double) (h) / (s - e);
    if (ans < 0)
        printf("NO\n");
    else
        printf("YES\n%lf\n", ans);
    return 0;
}
