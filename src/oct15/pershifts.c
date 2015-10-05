#include <stdio.h>
#include <stdlib.h>
#define BIG 1000000007

long long int msort(int* a, int lo, int hi);
long long int merge(int* a, int lo, int hi, int mid);

int main(void) {
    int *fact = (int *) calloc(100001, 4);
    int a;
    fact[0] = 1;
    for (a = 1; a < 100001; a++) fact[a] = (a * fact[a-1]) % BIG;
    int t;
    scanf("%d", &t);
    for (a = 0; a < t; a++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int *p   = (int *) calloc(n, 4);
        int *q   = (int *) calloc(n, 4);
        int *dup = (int *) calloc(n, 4);
        int *nextp = (int *) calloc(n, 4);
        int *nextq = (int *) calloc(n, 4);
        int i;
        int prev, first;
        scanf("%d", &prev);
        first = p[0] = prev;
        for (i = 1; i < n; i++) {
            scanf("%d", p+i);
            nextp[prev-1] = p[i];
            prev = p[i];
        }
        nextp[prev-1] = first;
        scanf("%d", &prev);
        first = dup[0] = q[0] = prev;
        for (i = 1; i < n; i++) {
            scanf("%d", q+i);
            dup[i] = q[i];
            nextq[prev-1] = q[i];
            prev = q[i];
        }
        nextq[prev-1] = first;
        if (k == n) {
            int flag = 1;
            for (i = 0; i < n; i++) {
                if (nextp[i] != nextq[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                printf("%d\n", q[0]);
            else
                printf("-1\n");
        }
        else if (k % 2 == 0) {
            int ans = 0;
            for (i = 0; i < n; i++) {
            }
            printf("%d\n", ans);
        }
    }
}

// function returns the number of inversions in between a[lo] to a[hi]
long long int msort(int *a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    // base case
    if (hi - lo == 0) return 0;

    long long int left_inv = msort(a, lo, mid);
    long long int right_inv = msort(a, mid+1, hi);
    long long int split = merge(a, lo, hi, mid);

    return (left_inv + right_inv + split);
}

long long int merge(int* a, int lo, int hi, int mid) {
    // a[lo] to a[mid] has first sorted array
    // a[mid+1] to a[hi] has second sorted array

    // merge makes a[lo] to a[hi] sorted and returns
    // the number of split inversions in a

    int size = hi-lo+1;
    int i, j;

    // begin merge
    int* aux = (int *) calloc(size, sizeof(int));   // auxiliary array
    int left = lo, right = mid+1, left_overflow = 0, right_overflow = 0;
    long long int count = 0, rem_left = mid - lo + 1;
    for (i = 0; i < size; i++) {
        if (right_overflow || (a[left] <= a[right] && !left_overflow)) {
            aux[i] = a[left++];
            rem_left--;
            if (left > mid)
                left_overflow = 1;
        }
        else if (left_overflow || (a[right] < a[left] && !right_overflow)) {
            aux[i] = a[right++];
            if (right > hi)
                right_overflow = 1;

            if (!left_overflow)
                count += rem_left;
        }
    }

    // copy auxiliary array over to a
    for (i = 0, j = lo; i < size; i++, j++)
        a[j] = aux[i];

    free(aux);
    return count;
}
