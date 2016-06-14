#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii current[200][200];
int orig[200][200];
int n, m;

void swaprow(int i) {
    pii temp = current[i][0];
    for (int j = 0; j < m-1; j++) {
        current[i][j] = current[i][j+1];
    }
    current[i][m-1] = temp;
}

void swapcolumn(int i) {
    pii temp = current[0][i];
    for (int j = 0; j < n - 1; j++)
        current[j][i] = current[j+1][i];
    current[n-1][i] = temp;
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("(%d, %d) ", current[i][j].first, current[i][j].second);
        }
        printf("\n");
    }
}


int main(void) {
    int q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            current[i][j] = make_pair(i, j);
        }
    }
 //   print();
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 3) {
            int x, y, val;
            scanf("%d %d %d", &x, &y, &val);
            x--; y--;
            int ox = current[x][y].first, oy = current[x][y].second;
            orig[ox][oy] = val;
        }
        else if (t == 1) {
            int r;
            scanf("%d", &r);
            r--;
            swaprow(r);
//            print();
        }
        else if (t == 2) {
            int c;
            scanf("%d", &c);
            c--;
            swapcolumn(c);
//            print();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", orig[i][j]);
        printf("\n");
    }
    return 0;
}


