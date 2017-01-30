#include <bits/stdc++.h>
using namespace std;

int a[100100];
int one[100100];
int two[100100];
int p[100100];
int q[100100];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i > 1 && a[i] > a[i - 1])
            p[i]++;
        if (i > 1 && a[i] < a[i - 1])
            q[i]++;
    }
    for (int i = 1; i <= n; i++) {
        one[i] = p[i] + one[i - 1];
        two[i] = q[i] + two[i - 1];
    }
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int s = one[r] - one[l]; // sum from l + 1 to r
        if (s == 0) { // if only zeros in array
            printf("Yes\n");
            continue;
        }
        // need to find the first index where sum = s
        int lo = l + 1, hi = r;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (one[mid] >= one[r])
                hi = mid;
            else
                lo = mid + 1;
        }
        if (two[lo] - two[l] > 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
