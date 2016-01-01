/** http://www.spoj.com/problems/DIV/ */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000100

int seive[MAX] = {0};

int main(void) {
    int i, j;
    for (i = 2; i < MAX; i++) {
        if (seive[i] == 0) {
            for (j = i; j < MAX; j+=i)
                seive[j] = i;
        }
    }
    int c = 0;
    int num;
    for (num = 2; num <= 1000000; num++) {
        int dn = 1;
        int dup = num;
        int prev = seive[dup], count = 1;
        while (dup != 1) {
            dup /= seive[dup];
            if (seive[dup] == prev)
                count++;
            else {
                dn *= count+1;
                count = 1;
            }
            prev = seive[dup];
        }
        int flag = 0;
        prev = seive[dn];
        dn /= seive[dn];
        if (dn != 1) {
            if (seive[dn] != prev && seive[dn] == dn)
                flag = 1;
        }
        if (flag == 1 ) {
            c++;
            if (c % 9 == 0)
                printf("%d\n", num);
        }
    }
    return 0;
}
