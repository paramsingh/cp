// Author: Param Singh <paramsingh258@gmail.com>
// New Distinct Substrings: http://www.spoj.com/problems/SUBST1/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[50001];
int suf[50001];

int cmp(const void* a, const void* b) {
    int* x = (int *) a;
    int* y = (int *) b;
    return strcmp(str+(*x), str+(*y));
}

void sufarr(long long int n) {
    // Creates a suffix array
    // Complexity is O(n^2 * log n) because each comparison is O(n)
    // and number of comparisons is O(n log n)
    int i;
    for (i = 0; i < n; i++)
        suf[i] = i;
    qsort(suf, n, 4, cmp);
}

long long int lcp(long long int n) {
    long long int count = 0;
    int i;
    char* z;
    char* y;
    for (i = 1; i < n; i++) {
        z = str + suf[i];
        y = str + suf[i-1];
        while (*z == *y) {
            count++;
            z++;
            y++;
        }
    }
    return count;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        long long int l = strlen(str);
        sufarr(l);
        long long int c = lcp(l);
        printf("%lld\n", (l*(l+1) / 2) - c);
    }
    return 0;
}

