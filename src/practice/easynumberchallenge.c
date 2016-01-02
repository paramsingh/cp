/** http://codeforces.com/problemset/problem/236/B */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
#define MOD 1073741824

int dn[1000100];
int seive[1000100] = {0};

int main(void) {
    int i, j, k;
    seive[1] = 1;
    dn[1] = 1;
    for (i = 2; i <= MAX; i++) {
        dn[i] = -1;
        if (seive[i] == 0) {
            dn[i] = 2;
            for (j = i; j <= MAX; j+=i)
                seive[j] = i;
        }
    }
    int a, b, c;
    int sum = 0;
    scanf("%d %d %d", &a, &b, &c);
    for (i = 1; i <= a; i++) {
        for (j = 1; j <= b; j++) {
            for (k = 1; k <= c; k++) {
                int num = i*j*k;
                if (dn[num] != -1)
                    sum = (sum + (dn[num]) % MOD) % MOD;
                else {
                    int prev = seive[num], dup = num;
                    int count = 1;
                    int a = 1;
                    while (dup != 1) {
                        dup /= seive[dup];
                        if (seive[dup] == prev)
                            count++;
                        else {
                            a *= count + 1;
                            count = 1;
                        }
                        prev = seive[dup];
                    }
                    dn[num] = a;
                    sum = (sum + (dn[num]) % MOD) % MOD;
                }
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
