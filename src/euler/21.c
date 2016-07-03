#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int* done = (int*) calloc(10003, sizeof(int));
    int* sums = (int*) calloc(10003, sizeof(int));
    int i, sum = 0;
    for (i = 1; i < 10000; i++)
        sums[i] = -1;
    for (i = 2; i < 10000; i++) {
        if (done[i] == 1)
            continue;
        int factors = 0;
        int j;
        if (sums[i] != -1)
            factors = sums[i];
        else {
            for (j = 1; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    if (j == 1 || j == sqrt(factors))
                        factors += j;
                    else
                        factors += j + i / j;
                }
            }
            sums[i] = factors;
        }
        int v = 0;
        if (sums[factors] == -1) {
            for (j = 1; j <= sqrt(factors); j++) {
                if (factors % j == 0) {
                    if (j == 1 || j == sqrt(factors))
                        v += j;
                    else
                        v += j + factors / j;
                }
            }
            sums[factors] = v;
        }
        else {
            v = sums[factors];
        }
        if (v == i && i != factors) {
            sum += factors + i;
        }
        done[i] = 1;
        done[factors] = 1;
    }
    printf("%d\n", sum);
    return 0;
}
