/** http://www.spoj.com/problems/USUBQSUB/ */
#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;

lli ***bit;
int n, m;

void update(int no, int x, int y, lli val) {
    while (x <= n) {
        int y1 = y;
        while (y1 <= n) {
            bit[no][x][y1] += val;
            y1 += y1 & (-y1);
        }
        x += x & (-x);
    }
}

lli query(int no, int x, int y) {
    lli sum = 0;
    while (x > 0) {
        int y1 = y;
        while (y1 > 0) {
            sum += bit[no][x][y1];
            y1 -= y1 & (-y1);
        }
        x -= x & (-x);
    }
    return sum;
}

void update_r(int x1, int y1, int x2, int y2, int val) {
    // updating first tree
    update(0, x1, y1, val);
    update(0, x1, y2+1, -val);
    update(0, x2+1, y1, -val);
    update(0, x2+1, y2+1, val);

    // updating second tree
    update(1, x1, y1, val*(1-y1));
    update(1, x1, y2+1, val*y2);
    update(1, x2+1, y1, val*(y1-1));
    update(1, x2+1, y2+1, -val*y2);

    // updating third tree
    update(2, x1, y1, val*(1-x1));
    update(2, x1, y2+1, (x1-1)*val);
    update(2, x2+1, y1, val*x2);
    update(2, x2+1, y2+1, -x2*val);

    // updating fourth tree
    update(3, x1, y1, (x1-1)*(y1-1)*val);
    update(3, x1, y2+1, -y2*(x1-1)*val);
    update(3, x2+1, y1, -x2*(y1-1)*val);
    update(3, x2+1, y2+1, x2*y2*val);
}

lli query_n(int x, int y) {
    return query(0, x, y) * x * y + query(1, x, y) * x + query(2, x, y) * y + query(3, x, y);
}

lli query_r(int x1, int y1, int x2, int y2) {
    lli sum = 0;
    sum += query_n(x2, y2) - query_n(x1-1, y2) - query_n(x2, y1-1) + query_n(x1-1, y1-1);
    return sum;
}

int main(void) {
    scanf("%d %d", &n, &m);
    bit = (lli ***) calloc(5, sizeof(lli***));
    int i, j;
    for (i = 0; i < 4; i++) {
        bit[i] = (lli **) calloc(n+10, sizeof(lli**));
        for (j = 0; j < n+10; j++)
            bit[i][j] = (lli *) calloc(n+10, sizeof(lli));
    }
    int type, x1, x2, y1, y2, val;
    while (m--) {
        scanf("%d %d %d %d %d", &type, &x1, &y1, &x2, &y2);
        if (type == 1) {
            printf("%lld\n", query_r(x1, y1, x2, y2));
        }
        else {
            scanf("%d", &val);
            update_r(x1, y1, x2, y2, val);
        }
    }
    return 0;
}
