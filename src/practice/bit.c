#include <stdio.h>
#include <stdlib.h>

int* bit;
int max;

long long int query(int i) {
    long long int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= (i & (-i));
    }
    return sum;
}

void update(int i, int val) {
    while (i <= max) {
        bit[i] += val;
        i += (i & (-i));
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        bit = (int *) calloc(10000001, 4);
        int n;
        scanf("%d", &n);
        int arr[n];
        int i;
        max = -1;
        for (i = 0; i < n; i++) {
            scanf("%d", arr+i);
            max = (max > arr[i]) ? max : arr[i];
        }
        long long int ans = 0;
        for (i = n-1; i >= 0; i--) {
            ans += query(arr[i]-1);
            update(arr[i], 1);
        }
        printf("%lld\n", ans);
        free(bit);
    }
    return 0;
}
