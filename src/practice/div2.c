/** http://www.spoj.com/problems/DIV2/ */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000010


int seive[MAX] = {0};
int dn[MAX] = {0};
int p[100], mul[100];
int l;

int num, flag;
void factors(int c, int a) {
    if (c == l) {
        if (a == 1)
            return;
        //printf("dn[%d] = %d, dn[%d] = %d\n", num, dn[num], a, dn[a]);
        if (dn[num] % dn[a] != 0)
            flag = 0;
    }
    else {
        int i;
        for (i = 0; i <= mul[c]; i++) {
            factors(c+1, a);
            a *= p[c];
        }
    }
}


int main(void) {
    int i, j;
    seive[1] = 1;
    for (i = 2; i < MAX; i++) {
        if (seive[i] == 0) {
            for (j = i; j < MAX; j+=i)
                seive[j] = i;
        }
    }
    int c = 0;
    for (num = 1; num <= 1000000; num++) {
        l = 0;
        mul[l] = 1;
        int dup = num;
        int prev = seive[dup];
        p[l++] = prev;
        int d = 1;
        int count = 1;
        while (dup != 1) {
            dup /= seive[dup];
            if (prev == seive[dup]) {
                mul[l-1]++;
                count++;
            }
            else {
                d *= count + 1;
                mul[l] = 1;
                p[l++] = seive[dup];
            }
            prev = seive[dup];
        }
        dn[num] = d;
        flag = 1;
        if (d > 3) {
            factors(0, 1);
            if (flag == 1) {
                c++;
                if (c % 108 == 0)
                    printf("%d\n", num);
            }
        }
    }
    return 0;
}
