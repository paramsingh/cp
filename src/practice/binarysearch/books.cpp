#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int a[600];
int n;
int k;

bool valid(lli mx) {
    lli cur = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cur + a[i] > mx) {
            cnt++;
            cur = 0;
        }
        cur += a[i];
    }
    return (cnt+1) <= k;
}

void print(lli mx) {
    vector<lli> p;
    int rem = k-1;
    int toprint = n;
    lli cur = 0;
    int x = n-1;
    while (rem < toprint) {
        if (cur + a[x] > mx) {
            p.push_back(-1);
            rem--;
            cur = 0;
        }
        else {
            p.push_back(a[x]);
            toprint--;
            cur += a[x];
            x--;
        }
    }
    int v = p[p.size()-1];
    if (v == -1) {
        for (int i = x; i >= 0; i--) {
            p.push_back(a[i]);
            p.push_back(-1);
        }
    }
    else {
        for (int i = x; i >= 0; i--) {
            p.push_back(-1);
            p.push_back(a[i]);
        }
    }


    for (int i = p.size() - 1; i >= 0; i--) {
        if (p[i] == -1) {
            if (i != 0 && i != p.size() - 1) printf("/ ");
        }
        else
            printf("%lld ", p[i]);
    }
    printf("\n");
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
            mx = max(mx, a[i]);
        }
        lli lo = mx, hi = 5000000000;
        while (lo < hi) {
            lli mid = (lo + hi) / 2;
            int x = valid(mid);
            if (x)
                hi = mid;
            else
                lo = mid + 1;
        }
        print(lo);
    }
    return 0;
}
