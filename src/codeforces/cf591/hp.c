#include <stdio.h>

int main(void) {
    int l, p, q;
    scanf("%d", &l);
    scanf("%d", &p);
    scanf("%d", &q);
    float ans = ((float)(p) * l) / (float)(p+q);
    printf("%f\n", ans);
    return 0;
}
