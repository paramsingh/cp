// Author: Param Singh <paramsingh258@gmail.com>
// Spheres: https://www.codechef.com/OCT15/problems/KSPHERES

#include <stdio.h>
#include <stdlib.h>
#define BIG 1000000007

int main(void) {
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    long long int* spheres = (long long int *) calloc(c, 8);
    long long int* dup = (long long int *) calloc(c, 8);
    long long int *u = (long long int *) calloc(c, 8);
    long long int *l = (long long int *) calloc(c, 8);
    int i, j;
    long long int x;
    for (i = 0; i < n; i++) {
        scanf("%lld", &x);
        u[x-1]++;
    }
    for (i = 0; i < m; i++) {
        scanf("%lld", &x);
        l[x-1]++;
        dup[x-1] = spheres[x-1] = l[x-1] * u[x-1];
    }
    long long int sum;
    long long int aux;
    for (j = 0; j < c; j++) {
        sum = 0;
        aux = 0;
        for (i = 0; i < c; i++) {
            // dup[i] contains number of j-spheres possible
            // multiplying sum with dup[i] gives number of (j+1)-spheres
            // possible with radius i+1;
            long long int y = dup[i];
            dup[i] = ((spheres[i] % BIG) * (sum % BIG)) % BIG;
            aux += (dup[i] % BIG);
            sum += y;
        }
        printf("%lld ", (aux % 1000000007));
    }
    return 0;
}


