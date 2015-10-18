// Author: Param Singh <paramsingh258@gmail.com>
// The Last Digit: http://www.spoj.com/problems/LASTDIG/
// Exponentiation by squaring
#include <stdio.h>

int exp1(int x, long long int n) {
    if (n == 0) return 1;
    else if (n == 1) return (x % 10);
    else if (n % 2 == 0) return exp1(((x % 10) * (x%10)) % 10, n/2) % 10;
    else if (n % 2 == 1) return ((x % 10) * exp1(((x%10) * (x%10) % 10), (n-1) / 2)) % 10;
    return -1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a;
        long long int b;
        scanf("%d %lld", &a, &b);
        printf("%d\n", exp1(a, b));
    }
    return 0;
}
