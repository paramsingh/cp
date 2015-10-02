// Author: Param Singh <paramsingh258@gmail.com>
// Equilateral Triangles: https://www.codechef.com/OCT15/problems/ADTRI

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int* seive = (int *) calloc(5000001, 4);
    int* arr   = (int *) calloc(5000001, 4);
    int i;
    int count = 0;
    for (i = 1; i < 5000001; i++) {
        if (arr[i] == 0) {
            if ((i+1) % 4 == 1)
                seive[count++] = i+1;
            int num = i+1;
            int x = 1;
            while (num < 5000001) {
                arr[num-1] = 1;
                num = num * (x++);
            }
        }
    }
    int t;
    scanf("%d", &t);
    int a;
    for (a = 1; a <= t; a++) {
        int n;
        scanf("%d", &n);
        int c = 0, flag = 0;
        while (seive[c] <= n) {
            if (seive[c] == 0)
                break;
            if (n % seive[c] == 0) {
                flag = 1;
                break;
            }
            c++;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
