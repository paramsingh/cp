#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void) {
    int n, a, b, p, q;
    scanf("%d %d %d %d %d", &n, &a, &b, &p, &q);
    long long x = (a * (long long) b) / gcd(a, b);
    long long ca = n / a;
    long long cb = n / b;
    long long cc = n / x;
    long long ans = (ca - cc) * p + cb * q;
    if (p > q)
        ans += ((p - q) * cc);
    printf("%lld\n", ans);
    return 0;
}
