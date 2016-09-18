// Author: Param Singh <paramsingh258@gmail.com>

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int v[n], d[n], p[n], dup[n];
    int* run = (int *) calloc(n, 4);
    int* mark = (int *) calloc(n, 4);
    int i, count = 0, j;
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", v+i, d+i, p+i);
        dup[i] = p[i];
    }
    for (i = 0; i < n; i++) {
        if (mark[i] == 0) {
            run[count++] = i + 1;
            int x = v[i];
            int flag = 0; 
            for (j = i + 1; j < n; j++) {
                if (x + flag > p[j] && mark[j] == 0) {
                    flag += d[j];
                    mark[j] = 1;
                    if (x > 0)
                        x--;
                    else
                        x = 0;
                }
                if (mark[j] == 0) {   
                    p[j] -= x + flag;
                    if (x > 0)
                        x--;
                    else
                        x = 0;
                }
            }
        }
    }
    printf("%d\n", count);
    for (i = 0; i < count; i++) 
        printf("%d ", run[i]);
    return 0;
}
                
