// Author: Param Singh <paramsingh258@gmail.com>
// Number Steps: http://www.spoj.com/problems/NSTEPS/

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y) {
            if (x % 2 == 0)
                printf("%d\n", x+y);
            else
                printf("%d\n", x+y-1);
        }
        else if (x == y+2) {
            if (x % 2 == 0)
                printf("%d\n", x+y);
            else
                printf("%d\n", x+y-1);
        }
        else
            printf("No Number\n");
    }
    return 0;
}

