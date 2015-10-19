#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int t;
    scanf("%d", &t);
    int *a = (int *) calloc(1000001, 4);
    int i;
    for (i = 0; i < t; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for (i = 0; i < 1000001; i++) {
        while (a[i] > 0) {
            printf("%d\n", i);
            a[i]--;
        }
    }
    return 0;
}
