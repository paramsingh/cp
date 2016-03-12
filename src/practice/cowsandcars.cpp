#include <bits/stdc++.h>

double ans(double m, double n, double s) {
    return (n * (m + n - 1)) / ((m + n) * (m + n - s - 1));
}

int main(void) {
    int m, n, s;
    while (scanf("%d %d %d", &m, &n, &s) != EOF) {
        printf("%.5lf\n", ans(m, n, s));
    }
    return 0;
}
