#include <bits/stdc++.h>
using namespace std;
typedef set<string>::iterator it;

set<string> dp[100][100];
int len[100][100];
char a[100], b[100];

int ans(int x, int y) {
    if (x == -1 || y == -1)
        return 0;
    if (len[x][y] != -1)
        return len[x][y];

    int l1 = ans(x - 1, y);
    int l2 = ans(x, y - 1);
    int l3 = -1;
    if (a[x] == b[y]) {
        l3 = ans(x - 1, y - 1) + 1;
    }
    int l = max(l1, max(l2, l3));
    if (l == l1) {
        if (ans(x - 1, y) > 0) {
            for (it i = dp[x-1][y].begin(); i != dp[x - 1][y].end(); i++)
                dp[x][y].insert(*i);
        }
    }
    if (l == l2) {
        if (ans(x, y - 1) > 0) {
            for (it i = dp[x][y - 1].begin(); i != dp[x][y - 1].end(); i++)
                dp[x][y].insert(*i);
        }
    }
    if (l == l3) {
        if (ans(x-1, y-1) == 0) {
            string s;
            s.push_back(a[x]);
            dp[x][y].insert(s);
        }
        else {
            for (it i = dp[x-1][y-1].begin(); i != dp[x-1][y-1].end(); i++)
                dp[x][y].insert((*i) + a[x]);
        }
    }
    return len[x][y] = l;
}


int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(len, -1, sizeof(len));
        scanf("%s", a);
        scanf("%s", b);
        int l1 = strlen(a);
        int l2 = strlen(b);
        ans(l1 - 1, l2 - 1);
        if (len[l1 -1][l2 - 1] == 0)
            continue;
        for (it i = dp[l1-1][l2-1].begin(); i != dp[l1-1][l2-1].end(); i++)
            cout << (*i) << endl;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                dp[i][j].clear();
    }
    return 0;
}
