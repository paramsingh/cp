#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sq;

struct query {
    int l, r, id;
} q[200001];

int count[2000001];

void fastread( int *a){
    char c=0;
    while(c<33){
        c=getchar_unlocked();
    }
    *a=0;
    while(c>33){
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

int cmp(const void* a, const void* b) {
    struct query* x = (struct query*) a;
    struct query* y = (struct query*) b;
    if (x->l / sq != y->l / sq) {
        if (((x->l)/sq) < ((y->l)/sq))
            return -1;
        else if (((x->l)/sq) > ((y->l)/sq))
            return 1;
        else
            return 0;
    }
    if ((x->r) < (y->r)) {
        return -1;
    }
    else if ( (x->r) > (y->r) ) {
        return 1;
    }
    else
        return 0;
}


int main(void) {
    int n;
    fastread(&n);
    sq = sqrt(n);
    int a[n];
    int t, i;
    for (i = 0; i < 2000001; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        fastread(a+i);
    fastread(&t);
    int ans[t];
    for (i = 0; i < t; i++) {
        fastread(&(q[i].l));
        fastread(&(q[i].r));
        q[i].l = q[i].l - 1;
        q[i].r = q[i].r - 1;
        q[i].id = i;
    }
    qsort(q, t, sizeof(struct query), cmp);
    int cl = 0, cr = 0, x = 0;
    for (i = 0; i < t; i++) {
        while (cl > q[i].l) {
            count[a[cl-1]]++;
            if (count[a[cl-1]] == 1)
                x++;
            cl--;
        }
        while (cl < q[i].l) {
            count[a[cl]]--;
            if (count[a[cl]] == 0)
                x--;
            cl++;
        }
        while (cr <= q[i].r) {
            count[a[cr]]++;
            if (count[a[cr]] == 1)
                x++;
            cr++;
        }
        while (cr > q[i].r + 1) {
            count[a[cr-1]]--;
            if (count[a[cr-1]] == 0)
                x--;
            cr--;
        }
        ans[q[i].id] = x;
    }
    for (i = 0; i < t; i++)
        printf("%d\n", ans[i]);
    return 0;
}
