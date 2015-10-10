#include <stdio.h>
#include <stdlib.h>
#define BIG 1000000007

int merge(int *a, int lo, int hi, int mid, int* count);
int msort(int* a, int lo, int hi, int* count) {
    if (lo == hi)
        return 0;
    else {
        int mid = (lo + hi) / 2;
        int x = msort(a, lo, mid, count);
        int y = msort(a, mid+1, hi, count);
        int z = merge(a, lo, hi, mid, count);
        return (x + y + z) % 2;
    }
}

int merge(int *a, int lo, int hi, int mid, int* count) {
    int size = hi - lo + 1;
    int i, j;
    int aux[size];
    int left = lo, right = mid + 1;
    int left_overflow = 0, right_overflow = 0;
    int rem_left = mid - lo + 1;
    int parity = 0;
    for (i = 0; i < size; i++) {
        if (right_overflow || (a[left] <= a[right] && !left_overflow)) {
            aux[i] = a[left++];
            rem_left--;
            if (left > mid)
                left_overflow = 1;
        }
        else if (left_overflow || (a[right] < a[left] && !right_overflow)) {
            aux[i] = a[right];
            int temp = right;
            right++;
            if (right > hi)
                right_overflow = 1;

            if (!left_overflow) {
                count[ a[temp]-1 ] += rem_left;
                parity = (parity + rem_left) % 2;
            }
        }
    }
    for (i = 0, j = lo; i < size; i++, j++)
        a[j] = aux[i];
    return parity;
}

long long int rank(int* a, int* count, int* fact, int n) {
    long long int r = 1;
    int i;
    for (i = 0; i < n; i++) {
        // bigger than a[i] on the left of a[i] = count[a[i]-1]
        // smaller than a[i] on the left of a[i] = i - count[a[i]-1]
        // smaller than a[i] on the right of a[i] = a[i] - 1 - i + count[a[i]]
        int x = a[i] - 1 - i + count[a[i]-1];
        r = (r + ((long long)(x)*(fact[n-i-1]))%BIG)%BIG;
    }
    return r;
}

long long int rank2(int* a, int* count, int* fact, int n) {
    long long int r = 0;
    int i;
    for (i = 0; i < n-2; i++) {
        int x = a[i] - 1 - i + count[a[i]-1];
        r = (r + ((((long long)(x) * 500000004) % BIG) * (long long)(fact[n-i-1])) % BIG) % BIG;
    }
    r = (r + 1) % BIG;
    return r;
}

int main(void) {
    int t;
    scanf("%d", &t);
    int a;
    int *fact = (int *) calloc(100001, 4);
    fact[0] = 1;
    for (a = 1; a < 100001; a++)
        fact[a] = (fact[a-1] * (long long)a) % BIG;
    for (a = 0; a < t; a++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int p[n], q[n], dup[n];
        int countp[n], countq[n];
        int nextp[n], nextq[n];
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
        countp[0] = countq[0] = 0;
        scanf("%d", &prev);
        first = q[0] = dup[0] = prev;
        for (i = 1; i < n; i++) {
            scanf("%d", q+i);
            nextq[prev-1] = dup[i] = q[i];
            countp[i] = countq[i] = 0;
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
        else {
            int parityq = msort(dup, 0, n-1, countq);
            if (k % 2 == 0) {
                long long int r = rank(q, countq, fact, n);
                printf("%lld\n", r);
            }
            else {
                int parityp = msort(p, 0, n-1, countp);
                if (parityp == parityq) {
                    long long int m = rank2(q, countq, fact, n);
                    printf("%lld\n", m);
                }
                else
                    printf("-1\n");
            }
        }
    }
    return 0;
}

