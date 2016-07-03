#include <stdio.h>

int main(void) {
    int a, b, c;
    for (a = 1; a < 1000; a++) {
        for (b = 1; b < 1000; b++) {
            c = 1000 - a - b;
            if (c < 0)
                break;
            else if (a*a + b*b == c*c)
                printf("%d %d %d %d\n", a, b, c, a*b*c);
        }
    }
    return 0;
}
