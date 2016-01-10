/** http://www.spoj.com/problems/WINDVANE/ */
#include <bits/stdc++.h>
using namespace std;
int m, n;
int **bit;
char mat[2000][2000];
int eq[2000][2000];

void update(int x, int y, int val) {
    while (x <= m) {
        int y1 = y;
        while (y1 <= n) {
            bit[x][y1] += val;
            y1 += y1 & (-y1);
        }
        x += x & (-x);
    }
}

int query(int x, int y) {
    int ans = 0;
    int val = eq[x][y];
    while (x > 0) {
        int y1 = y;
        while (y1 > 0) {
            ans += bit[x][y1];
            y1 -= y1 & (-y1);
        }
        x -= x & (-x);
    }
    return ans + val;
}

void update_r(int x1, int y1, int x2, int y2, int val) {
    update(x1, y1, val);
    update(x1, y2+1, -val);
    update(x2+1, y1, -val);
    update(x2+1, y2+1, val);
}

int main(void) {
    scanf("%d %d", &m, &n);
    bit = (int**) calloc(m+10, sizeof(int*));
    for (int i = 0; i < m+10; i++)
        bit[i] = (int*) calloc(n+10, sizeof(int));
    for (int i = 1; i <= m; i++) {
        scanf("%s", mat[i]+1);
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] == 'N')
                eq[i][j] = 1;
            else if (mat[i][j] == 'E')
                eq[i][j] = 2;
            else if (mat[i][j] == 'S')
                eq[i][j] = 3;
            else if (mat[i][j] == 'W')
                eq[i][j] = 4;
        }
    }
    int q;
    scanf("%d", &q);
    char type[10];
    int x1, y1, x2, y2, val;
    while (q--) {
        scanf("%s", type);
        if (type[0] == 'C') {
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &val);
            int update;
            if (val == 0)
                update = 1;
            else
                update = -1;
            update_r(x1, y1, x2, y2, update);
        }
        else {
            scanf("%d %d", &x1, &y1);
            int val = query(x1, y1);
            int mod = val % 4;
            if (mod < 0)
                mod += 4;
            if (mod == 1)
                printf("N\n");
            else if (mod == 2)
                printf("E\n");
            else if (mod == 3)
                printf("S\n");
            else if (mod == 0)
                printf("W\n");
        }
    }
    return 0;
}
