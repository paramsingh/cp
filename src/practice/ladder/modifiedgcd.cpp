#include <bits/stdc++.h>
using namespace std;

set<int> fa, fb;
vector<int> common;


int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int sa = sqrt(a), sb = sqrt(b);
    for (int i = 1; i <= sa; i++) {
        if (a % i == 0) {
            fa.insert(i);
            fa.insert(a / i);
        }
    }

    for (int i = 1; i <= sb; i++) {
        if (b % i == 0) {
            fb.insert(i);
            fb.insert(b / i);
        }
    }

    for (auto x: fa) {
        if (fb.count(x))
            common.push_back(x);
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int lo = 0, hi = common.size() - 1;
        while (lo  < hi) {
            int mid = (lo + hi) / 2;
            if (common[mid] >= l)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (common[lo] < l) {
            printf("-1\n");
            continue;
        }
        hi = common.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (common[mid] <= r)
                lo = mid;
            else
                hi = mid - 1;
        }
        if (common[lo] > r)
            printf("-1\n");
        else
            printf("%d\n", common[lo]);
    }
}
