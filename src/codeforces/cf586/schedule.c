// Author: Param Singh <paramsingh258@gmail.com>

#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    int uni = 0;
    int free = 0;
    int first = 1;
    int i;
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (first && x == 1) {
                uni++;
                first = 0;
        }
        else if (!first) {
            if (x == 1) {
                uni++;
                if (free <= 1)
                    uni += free;
                free = 0;
            }
            else  {
                free++;
            }
        }
    }
    printf("%d\n", uni);
    return 0;
}
