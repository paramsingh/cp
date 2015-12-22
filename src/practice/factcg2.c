#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000100

int main(void) {
    int* seive = (int *) calloc(SIZE, sizeof(int));
    int i, j;
    for (i = 2; i < SIZE; i++) {
        if (seive[i] == 0) {
            for (j = i; j < SIZE; j+=i)
                seive[j] = i;
        }
    }
    int n;
    int primes[1000];
    while (scanf("%d", &n) != EOF) {
        int x = n;
        if (x == 1) {
            printf("1\n");
            continue;
        }
        int count = 0;
        while (x != 1) {
            primes[count++] = seive[x];
            x /= seive[x];
        }
        printf("1 x ");
        for (i = count-1; i > 0; i--)
            printf("%d x ", primes[i]);
        printf("%d\n", primes[0]);
    }
    return 0;
}
