// Author: Param Singh <paramsingh258@gmail.com>
// Permutations: https://www.codechef.com/OCT15/problems/PERSHFTS
#include <stdio.h>
#include <stdlib.h>
#define BIG 1000000007

int k;
int msort(int* a, int lo, int hi);
int merge(int* a, int lo, int hi, int mid);
void populate(int* count, int* a, int n) {
    int i;
    for (i = 0; i < n; i++)
        count[a[i]]++;
    for (i = 1; i < n; i++)
        count[i] += count[i-1];
}

void update(int* count, int a, int n) {
    int i;
    for (i = a; i < n; i++)
        count[i]--;
}

int findrank(int* a, int n, int mul) {
    int len = n;
    int rank = 1, i;
    int *count = (int *) calloc(n, 4);
    populate(count, a, n);
    for (i = 0; i < n; i++) {
        mul /= len - i;
        rank += count[a[i] - 1] * mul;
        update(count, a[i], n);
    }
    return rank;
}


int main(void) {
    int a;
    int *fact = (int *) calloc(100001, 4);
    fact[0] = 1;
    for (k = 1; k < 100001; k++)
        fact[k] = (k * fact[k-1]) % BIG;
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
            printf("%d\n", findrank(q, n, fact[n]));
        }
        else if (k % 2 != 0) {
            int r = findrank(q, n, fact[n]);
            int x = msort(p, 0, n-1);
            int y = msort(q, 0, n-1);
            if (x % 2 != y % 2)
                printf("-1\n");
            else {
                if (r % 2 == 0)
                    printf("%d\n", r/2);
                else
                    printf("%d\n", (r+1)/2);
            }
        }
    }
}

// function returns the number of inversions in between a[lo] to a[hi]
int msort(int *a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    // base case
    if (hi - lo == 0) return 0;

    int left_inv = msort(a, lo, mid);
    int right_inv = msort(a, mid+1, hi);
    int split = merge(a, lo, hi, mid);

    return (left_inv + right_inv + split) % BIG;
}

int merge(int* a, int lo, int hi, int mid) {
    // a[lo] to a[mid] has first sorted array
    // a[mid+1] to a[hi] has second sorted array

    // merge makes a[lo] to a[hi] sorted and returns
    // the number of split inversions in a

    int size = hi-lo+1;
    int i, j;

    // begin merge
    int* aux = (int *) calloc(size, sizeof(int));   // auxiliary array
    int left = lo, right = mid+1, left_overflow = 0, right_overflow = 0;
    int count = 0, rem_left = mid - lo + 1;
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
                count = (count + rem_left);
        }
    }

    // copy auxiliary array over to a
    for (i = 0, j = lo; i < size; i++, j++)
        a[j] = aux[i];

    free(aux);
    return count;
}

