// Author: Param Singh <paramsingh258@gmail.com>
// Aggressive Cows: http://www.spoj.com/problems/AGGRCOW/

#include <stdio.h>
#include <stdlib.h>

int check(long long int n, long long int* a, int size, int cows) {
    int c = 1;
    int prev = 0;
    int i;
    for (i = 1; i < size; i++) {
        if (a[i] - a[prev] >= n) {
            c++;
            prev = i;
            if (c == cows)
                return 1;
        }
    }
    return 0;
}

long long int search(int size, long long int* a, int cows) {
    long long int max = -1;
    long long int low = 0, high = a[size-1];
    while (low < high) {
        long long int mid = (low + high) / 2;
        if (check(mid, a, size, cows)) {
            if (mid > max)
                max = mid;
            low = mid + 1;
        }
        else
            high = mid;
    }
    return max;
}


int cmp(const void* p, const void* q) {
    long long int* a = (long long int *) p;
    long long int* b = (long long int *) q;
    return (*a) - (*b);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c;
        scanf("%d %d", &n, &c);
        long long int* x = (long long int *) calloc(n, 8);
        int i;
        for (i = 0; i < n; i++)
            scanf("%lld", x+i);
        qsort(x, n, 8, cmp);
        printf("%lld\n", search(n, x, c));
    }
    return 0;
}
