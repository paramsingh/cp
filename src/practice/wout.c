#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, g;
        scanf("%d %d", &n, &g);
        int i;
        long long int* r = (long long int*) calloc(n+2, 8);
        for (i = 0; i < n; i++) {
            int h, l;
            scanf("%d %d", &l, &h);
            r[l+1]--;
            r[h+2]++;
        }
        r[0] = n;
        long long int cur = n;
        for (i = 0; i < n; i++)
            r[i+1] += r[i];
        for (i = 0; i < n; i++)
            r[i+1] += r[i];
        long long int min = r[g] - r[0];
        for (i = g+1; i <= n; i++) {
            long long int y = r[i] - r[i-g];
            if (y < min)
                min = y;
        }
        printf("%lld\n", min);
    }
    return 0;
}
