#include <bits/stdc++.h>
using namespace std;

vector<int> pos[100010];

int main(void) {
    int n;
    scanf("%d", &n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pos[x].push_back(i);
        mx = max(x, mx);
    }
    int mn = 10000;
    for (int i = 0; i <= mx; i++) {
        if (!pos[i].empty()) {
            sort(pos[i].begin(), pos[i].end());
            for (int j = 0; j < pos[i].size() - 1; j++)
                mn = min(pos[i][j + 1] - pos[i][j], mn);
        }
    }
    printf("%d\n", mn == 10000 ? -1 : mn);
    return 0;
}
