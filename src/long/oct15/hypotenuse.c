// Author: Param Singh <paramsingh258@gmail.com>
// Equilateral Triangles: https://www.codechef.com/OCT15/problems/ADTRI

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int* arr   = (int *) calloc(5000001, 4);
    int i;
    int count = 0;
    int flag;
    for (i = 1; i < 5000001; i++) {
        if (arr[i] == 0) {
            if ((i+1) % 4 == 1) {
                flag = 2;
            }
            else
                flag = 1;
            int num = i+1;
            int x = 1;
            while (num < 5000001) {
                if (arr[num-1] != 2)
                    arr[num-1] = flag;
                num = num + i + 1;
            }
        }
    }
    int t;
    scanf("%d", &t);
    int a;
    count = 0;
    for (a = 1; a <= t; a++) {
        int n;
        scanf("%d", &n);
        if (arr[n-1] == 2)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
