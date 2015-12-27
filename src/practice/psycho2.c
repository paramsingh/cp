#include <stdio.h>
#define SIZE 10000000

int seive[SIZE] = {0};

int digit(int x, long long int p) {
    if (p == 0) return 1;
    else if (p == 1) return x % 10;
    else if (p % 2 == 0) return digit(((x % 10) * (x % 10)) % 10, p/2) % 10;
    else return ((x % 10) * digit(((x%10) * (x%10))%10, (p-1)/2) % 10) % 10;
}

int main(void) {
    int i, j;
    for (i = 2; i < SIZE; i++) {
        if (seive[i] == 0) {
            for (j = i; j < SIZE; j+=i)
                seive[j] = i;
        }
    }
    int t;
    scanf("%d", &t);
    int k, b;
    long long int p;
    while (t--) {
        scanf("%d %d %lld", &k, &b, &p);
        int zeros = 0;
        while (k > 0) {
            k /= 5;
            zeros += k;
        }
        int d = digit(b, p);
        int n = zeros * d;
        if (n == 0 || n == 1) {
            printf("Ordinary Number\n");
            continue;
        }
        int prev = seive[n];
        int ce = 0, co = 0;
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
