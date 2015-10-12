#include <stdio.h>
#include <stdlib.h>

// Implementation of merge sort for algorithms class on coursera
long long int msort(int* a, int lo, int hi);
long long int merge(int* a, int lo, int hi, int mid);

int main() {
    int t;
    scanf("%d", &t);
    int a;
    for (a = 1; a <= t; a++) {  
        int n;
        scanf("%d", &n);
        int *a = (int *) calloc(n, 4);
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", a+i);
        printf("%lld\n", msort(a, 0, n-1));
    }
    return 0;
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
