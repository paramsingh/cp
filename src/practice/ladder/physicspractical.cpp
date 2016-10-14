#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int a[100100];

int main(void) {
    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    int n;
    fscanf(in, "%d", &n);
    for (int i = 1; i <= n; i++)
        fscanf(in, "%d", a+i);
    sort(a + 1, a + n + 1);
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        int mn = a[i];
        int lo = 1, hi = n;
        int rem = i - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] > 2 * mn)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (a[lo] > 2 * mn)
            rem += n - lo + 1;
        ans = min(ans, rem);
    }
    fprintf(out, "%d\n", ans);
    fclose(in);
    fclose(out);
}
