#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *((int *) a) - *((int *) b);
}

int main(void) {
    int n, k, i;
    scanf("%d %d", &n, &k);
    int* arr = (int*) calloc(n, 4);
    while (k--) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a-1]++;
        arr[b]--;
    }
    for (i = 1; i < n; i++) {
        arr[i] = arr[i] + arr[i-1];
    }
    qsort(arr, n, 4, cmp);
    printf("%d\n", arr[n/2]);
    return 0;
}
