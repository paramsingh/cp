#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    scanf("%d", &t);
    long long int a, d, l, beg, terms;
    long long int n, q, r, ans, dup, z, count, sum, x;
    int i;
    while (t--) {
        ans = 0;
        scanf("%lld %lld %lld %lld", &a, &d, &l, &r);
        beg = a + (l-1) * d;
        dup = beg;
        terms = r - l + 1;
        int *flag = (int *) calloc(10, sizeof(int));
        count = 0;
        sum = 0;
        while (1) {
            x = 1 + ((beg - 1) % 9);
            if (flag[x] == 1)
                break;
            else {
                sum += x;
                count++;
                flag[x] = 1;
                beg += d;
            }
        }
        q = terms / count;
        z = terms % count;
        ans += (q * sum);
        while (z--) {
            x = 1 + ((dup - 1) % 9);
            ans += x;
            dup += d;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
