// Author: Param Singh <paramsingh258@gmail.com>
// Prime Generator: http://www.spoj.com/problems/PRIME1/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
    int  *arr = (int *) calloc(320000, 4);
    int  *primes = (int *) calloc(320000, 4);
    int i;
    arr[0] = arr[1] = 1;
    int count = 0;
    for (i = 2; i < 320000; i++) {
        if (arr[i] == 0) {
            primes[count++] = i;
            int num = i * 2;
            while (num < 320000) {
                arr[num] = 1;
                num += i;
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        long long int a;
        long long int m, n;
        scanf("%lld %lld", &m, &n);
        for (a = m; a <= n; a++) {
            if (a < 320000) {
                if (arr[a] == 0)
                    printf("%lld\n", a);
            }
            else {
                int j = 0;
                int flag = 1;
                for (j = 0; j < count; j++) {
                    if (primes[j] > sqrt(a))
                        break;
                    if (a % primes[j] == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    printf("%lld\n", a);
            }
        }
        printf("\n");
    }
    return 0;
}
