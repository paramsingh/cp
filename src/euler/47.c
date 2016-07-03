#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000

int* seive;

int distinct(int n) {
    int x = seive[n], prev = 1;
    int count = 0;
    while (n != 1) {
        if (x != prev) {
            count++;
        }
        prev = x;
        n /= x;
        x = seive[n];
    }
    return count;
}
int main(void) {
    seive = (int *) calloc(MAX, sizeof(int));
    int i, j;
    for (i = 2; i < MAX; i++) {
        if (seive[i] == 0) {
            for (j = i; j < MAX; j+=i)
                seive[j] = i;
        }
    }
    int c = 0;
    int x = 1;
    int n = 4;
    while (c != n) {
        if (distinct(x) == n)
            c++;
        else
            c = 0;
        x++;
    }
    printf("%d\n", x-n);
    return 0;
}

