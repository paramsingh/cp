#include <bits/stdc++.h>
using namespace std;

vector<int> a, compress;
vector<int> pos[5000];

int find(int val) {
    int lo = 0, hi = compress.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (compress[mid] >= val)
            hi = mid;
        else
            lo = mid + 1;
    }
    assert(compress[lo] == val);
    return lo;
}

int get(int x, int y) {
    int i = 0, j = 0;
    int cnt = 0;
    int prev, nxt;
    if (pos[x][i] < pos[y][j]) {
        prev = pos[x][i];
        cnt++; i++;
        nxt = 1;
    }
    else {
        prev = pos[y][j];
        cnt++; j++;
        nxt = 0;
    }

    while (true) {
        if (nxt == 0) {
            while (i < pos[x].size() && pos[x][i] <= prev)
                i++;
            if (i < pos[x].size()) {
                prev = pos[x][i];
                cnt++;
            }
            else
                break;
        }
        else {
            while (j < pos[y].size() && pos[y][j] <= prev)
                j++;
            if (j < pos[y].size()) {
                prev = pos[y][j];
                cnt++;
            }
            else
                break;
        }
        nxt ^= 1;
    }
    return cnt;
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.push_back(x);
        compress.push_back(x);
    }
    sort(compress.begin(), compress.end());
    vector<int>::iterator it = unique(compress.begin(), compress.end());
    compress.resize(distance(compress.begin(), it));

    for (int i = 0; i < n; i++) {
        int x = find(a[i]);
        pos[x].push_back(i);
    }

    int ans = -1;
    for (int i = 0; i < compress.size(); i++)
        ans = max(ans, (int)pos[i].size());

    for (int i = 0; i < compress.size(); i++) {
        for (int j = i + 1; j < compress.size(); j++) {
            ans = max(ans, get(i, j));
        }
    }
    printf("%d\n", ans);
    return 0;
}
