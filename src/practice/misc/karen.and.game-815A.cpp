// The idea is that you have n + m variables each representing the
// number of times you apply the op on each row and column.
// If we know the value of one of these variables, we can calculate
// the values of the rest of them. So a simple linear search on
// these values gives us the answer.

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int a[110][110];
int r[110];
int c[110];
int finr[110];
int finc[110];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    int min_steps = inf;
    for (int val = 0; val <= a[1][1]; val++) {
        r[1] = val;
        int flag = 1;
        int cnt = r[1];
        // calculate c[i] first
        for (int i = 1; i <= m; i++) {
            c[i] = a[1][i] - r[1];
            if (c[i] < 0) {
                flag = 0;
                break;
            }
            cnt += c[i];
        }
        if (flag == 0) continue;
        for (int i = 2; i <= n; i++) {
            r[i] = a[i][1] - c[1];
            if (r[i] < 0)  {
                flag = 0;
                break;
            }
            for (int j = 2; j <= m; j++) {
                if (r[i] != a[i][j] - c[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) break;
            cnt += r[i];
        }
        if (flag == 1 && min_steps > cnt) {
            min_steps = cnt;
            for (int i = 1; i <= n; i++)
                finr[i] = r[i];
            for (int i = 1; i <= m; i++)
                finc[i] = c[i];
        }
    }
    printf("%d\n", min_steps == inf ? -1: min_steps);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < finr[i]; j++)
            printf("row %d\n", i);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < finc[i]; j++)
            printf("col %d\n", i);
    }
}
