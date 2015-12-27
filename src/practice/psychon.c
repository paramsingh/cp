#include <stdio.h>
#define SIZE 10000100

int seive[SIZE] = {0};

int main(void) {
    int i, j;
    for (i = 2; i < SIZE; i++) {
        if (seive[i] == 0) {
            for (j = i; j < SIZE; j+=i)
                seive[j] = i;
        }
    }
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ce = 0, co = 0;
        int prev = seive[n];
        int count = 1;
        while (n != 1) {
            n /= seive[n];
            if (seive[n] == prev)
                count++;
            else {
                count % 2 == 0 ? ce++ : co++;
                count = 1;
            }
            prev = seive[n];
        }
        if (ce > co)
            printf("Psycho Number\n");
        else
            printf("Ordinary Number\n");
    }
    return 0;
}
