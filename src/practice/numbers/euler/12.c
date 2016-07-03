#include <stdio.h>
#include <stdlib.h>
#define MAX 80000000

int main(void) {
    int* seive = (int *) calloc(MAX, sizeof(int));
    int i, j;
    for (i = 2; i < MAX; i++) {
        if (seive[i] == 0) {
            for (j = i; j < MAX; j+=i)
                seive[j] = i;
        }
    }
    long long int sum = 1;
    long long int factors = 1;
    for (i = 2; i < MAX; i++) {
        sum += i;
        long long int x = sum;
        int prev = seive[x], count = 1;
        int val = 1;
        while (x != 1) {
            x /= seive[x];
            if (seive[x] == prev)
                count++;
            else {
                val *= count + 1;
                count = 1;
            }
            prev = seive[x];
        }
        if (val > 500) {
            printf("%lld\n", sum);
            break;
        }
    }
}
