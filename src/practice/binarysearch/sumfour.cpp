#include <bits/stdc++.h>
using namespace std;

int x[5][4001];
vector<int> a;
vector<int> b;
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &x[0][i], &x[1][i], &x[2][i], &x[3][i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a.push_back(x[0][i] + x[1][j]);
            b.push_back(x[2][i] + x[3][j]);
        }
    }
    sort(b.begin(), b.end());
    int l, r;
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int val = a[i];

        // finding first index for which b[i] >= -val
        int lo = 0, hi = b.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (b[mid] < -val)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (b[lo] != -val)
            continue;
        else
            l = lo;

        // last index for which b[i] <= -val
        lo = 0; hi = b.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (b[mid] <= -val)
                lo = mid;
            else
                hi = mid - 1;
        }
        ans += lo - l + 1;
    }
    printf("%d\n", ans);
    return 0;
}
