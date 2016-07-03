#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* seive = (int *) calloc(2000001, 4);
    int i;
    long long int sum = 0;
    for (i = 2; i < 2000001; i++) {
        if (seive[i] == 0) {
            sum += i;
            int j;
            for (j = i; j < 2000001; j+=i)
                seive[j] = 1;
        }
    }
    printf("%lld\n", sum);
    return 0;
}

