#include <stdio.h>
#include <stdlib.h>

struct discount {
    int a[15];
    int size;
} discounts[50000];


int cmpd(const void *a, const void *b) {
    struct discount* p = (struct discount*) a;
    struct discount* q = (struct discount*) b;
    return p->size - q->size;
}

int cmp(const void *a, const void *b) {
    int* p = (int *) a;
    int* q = (int *) b;
    return *q - *p;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n], dup[n], done[n], freq[n];
        int i, j;
        long long int sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", a+i);
            sum += a[i];
            dup[i] = a[i];
            done[i] = freq[i] = 0;
        }
        qsort(a, n, sizeof(int), cmp);
        int m;
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%d", &(discounts[i].size));
            int c = discounts[i].size;
            for (j = 0; j < c; j++) {
                scanf("%d", &(discounts[i].a[j]));
                discounts[i].a[j]--;
            }
        }
        qsort(discounts, m, sizeof(struct discount), cmpd);
        int cur = -1;
        for (i = 0; i < m ; i++) {
            if (discounts[i].size + cur >= n)
                break;
            else {
                int flag = 1;
                for (j = 0; j < discounts[i].size; j++) {
                    if (done[discounts[i].a[j]] == 1) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    cur += discounts[i].size;
                    sum -= a[cur];
                    for (j = 0; j < discounts[i].size; j++)
                        done[discounts[i].a[j]] = 1;
                }
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}

