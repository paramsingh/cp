#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

lli h[20], m[20];

inline void print(lli s, lli e) {
    printf("%lld ", s);
    if (e == 1e18)
        printf("Inf\n");
    else
        printf("%lld\n", e);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld %lld", h+i, m+i);
        if (n == 1) {
            printf("1\n0 Inf\n");
            continue;
        }
        lli s = 0, e = 1e18;
        int flag = 1;
        // < > < >
        for (int i = 0; (i < n - 1) && (flag == 1); i++) {
            if (i % 2 == 0) {
                if (m[i] == m[i + 1]) {
                    if (h[i] >= h[i + 1])
                        flag = 0;
                }
                else {
                    double w = ((double) (h[i + 1] - h[i])) / (m[i] - m[i + 1]);
                    if (m[i] > m[i + 1]) {
                        lli x = ceil(w) - 1;
                        if (x < 0)
                            flag = 0;
                        else
                            e = min(e, x);
                    }
                    else {
                        lli x = floor(w) + 1;
                        s = max(s, x);
                    }
                }
            }
            else {
                if (m[i] == m[i + 1]) {
                    if (h[i] <= h[i + 1])
                        flag = 0;
                }
                else {
                    double w = ((double)h[i + 1] - h[i]) / (m[i] - m[i + 1]);
                    if (m[i] > m[i + 1]) {
                        lli x = floor(w) + 1;
                        s = max(s, x);
                    }
                    else {
                        lli x = ceil(w) - 1;
                        if (x < 0)
                            flag = 0;
                        else
                            e = min(e, x);
                    }
                }
            }
            if (e < s)
                flag = 0;
        }

        lli s1 = 0, e1 = 1e18;
        int flag1 = 1;
        for (int i = 0; (i < n - 1) && (flag1 == 1); i++) {
            if (i % 2 != 0) {
                if (m[i] == m[i + 1]) {
                    if (h[i] >= h[i + 1])
                        flag1 = 0;
                }
                else {
                    double w = ((double)h[i + 1] - h[i]) / (m[i] - m[i + 1]);
                    if (m[i] > m[i + 1]) {
                        lli x = ceil(w) - 1;
                        if (x < 0)
                            flag1 = 0;
                        else
                            e1 = min(e1, x);
                    }
                    else {
                        lli x = floor(w) + 1;
                        s1 = max(s1, x);
                    }
                }
            }
            else {
                if (m[i] == m[i + 1]) {
                    if (h[i] <= h[i + 1])
                        flag1 = 0;
                }
                else {
                    double w = ((double)h[i + 1] - h[i]) / (m[i] - m[i + 1]);
                    if (m[i] > m[i + 1]) {
                        lli x = floor(w) + 1;
                        s1 = max(s1, x);
                    }
                    else {
                        lli x = ceil(w) - 1;
                        if (x < 0)
                            flag1 = 0;
                        else
                            e1 = min(e1, x);
                    }
                }
            }
            if (e1 < s1)
                flag1 = 0;
        }

        if (flag && flag1) {
            if (s1 < s) {
                if (e1 == s - 1) {
                    printf("1\n");
                    print(s1, e);
                }
                else {
                    printf("2\n");
                    print(s1, e1);
                    print(s, e);
                }
            }
            else {
                if (e == s1 - 1) {
                    printf("1\n");
                    print(s, e1);
                }
                else {
                    printf("2\n");
                    print(s, e);
                    print(s1, e1);
                }
            }
        }
        else if (flag) {
            printf("1\n");
            print(s, e);
        }
        else if (flag1) {
            printf("1\n");
            print(s1, e1);
        }
        else
            printf("0\n");
    }
    return 0;
}
