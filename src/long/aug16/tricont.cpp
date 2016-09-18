#include <bits/stdc++.h>
using namespace std;

struct point {
    long long x, y;
} p[100100];


inline int sign(point& a, point& b) {
    long long abx = b.x - a.x;
    long long aby = b.y - a.y;
    if ((abx * (-a.y)) > (aby * (-a.x)))
        return 1;
    else if ((abx * (-a.y)) == (aby * (-a.x)))
        return 0;
    else
        return -1;
}

inline bool check(point& a, point& b, point& c) {
    int sign1 = sign(a, b);
    int sign2 = sign(b, c);
    int sign3 = sign(c, a);

    return sign1 != 0 && sign1 == sign2 && sign2 == sign3;
}

int main(void) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i].x = x, p[i].y = y;
        if (i == 0 || i == 1) {
            printf("0\n");
            fflush(stdout);
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (check(p[i], p[j], p[k]))
                    ans++;
            }
        }
        printf("%lld\n", ans);
        fflush(stdout);
    }
    return 0;
}
