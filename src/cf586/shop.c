// Author: Param Singh <paramsingh258@gmail.com>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int fr[n], av[n], sr[n];
    int i;
    int sum = 0;
    fr[0] = 0;
    int x;
    for (i = 1; i < n; i++) {
        scanf("%d", &x);
        fr[i] = fr[i-1] + x;
    }
    sr[0] = 0;
    for (i = 1; i < n; i++) {
        scanf("%d", &x);
        sr[i] = sr[i-1] + x;
    }
    for (i = 0; i < n; i++) {
        sr[i] = sr[n-1] - sr[i];
        scanf("%d", av+i);
    }
    /*for (i = 0; i < n; i++)
        printf("%d ", fr[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d ", av[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%d ", sr[i]);
    printf("\n");*/

    int max, secondmax;
    x = fr[0] + sr[0] + av[0];
    int y = fr[1] + sr[1] + av[1];
    if (x > y) {
        secondmax = x;
        max = y;
    }
    else {
        secondmax = y;
        max = x;
    }
    for (i = 2; i < n; i++) {
        int elem = fr[i] + sr[i] + av[i];
        if (elem <= max) {
            secondmax = max;
            max = elem;
        }
        else if (elem < secondmax) {
            secondmax = elem;
        }
    }
    printf("%d", max+secondmax);
    return 0;
}
