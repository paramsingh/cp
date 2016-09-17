#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 9;
const double eps = 1e-9;

ll f[100100];
ll s[100100];
struct point {
    double x, y;
    point(double a, double b) {
        x = a, y = b;
    }
};

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        vector<point> polygon;
        int n, a, b, c, d;
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
        scanf("%lld %lld %lld %lld", f, f + 1, f + 2, f + 3);
        s[0] = f[0];
        for (int i = 1; i < 4; i++)
            s[i] = (s[i - 1] + f[i]) % mod;
        for (int i = 4; i <= 500; i++) {
            f[i] = ((ll)a * f[i -1]) % mod;
            f[i] = (f[i] + ((ll)b * f[i - 2]) % mod) % mod;
            f[i] = (f[i] + ((ll)c * f[i - 3]) % mod) % mod;
            f[i] = (f[i] + ((ll)d * f[i - 4]) % mod) % mod;
            s[i] = (s[i - 1] + f[i]) % mod;
        }
        int miny = 1e8, maxy = -1;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            miny = min(miny, y);
            maxy = max(maxy, y);
            polygon.push_back(point(x, y));
        }
        polygon.push_back(polygon[0]);
        ll ans = 0;
        for (int x = 0; x <= 100; x++) {
            for (int y = 0; y <= 100; y++) {
                int inside = 0;
                for (int i = 0; i < n; i++) {
                    int x1 = polygon[i].x, y1 = polygon[i].y;
                    int x2 = polygon[i+1].x, y2 = polygon[i+1].y;
                    int lhs = (y1 - y2) * x + (x2 - x1) * y;
                    int rhs = (y1 * x2 - x1 * y2);
                    if (lhs == rhs)
                        if (min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2))
                            inside = 1;
                }
                if (inside) {
                    //printf("hello, %d %d\n", x, y);
                    ans = (ans + f[x + y]) % mod;
                    continue;
                }
                int i, j; inside = 0;
                // point inside polygon: http://stackoverflow.com/a/2922778
                for (i = 0, j = n - 1; i < n; j = i++) {
                    if ( ((polygon[i].y>y) != (polygon[j].y>y)) &&
                    (x < (polygon[j].x-polygon[i].x) * (y-polygon[i].y) / (polygon[j].y-polygon[i].y) + polygon[i].x) )
                        inside = !inside;
                }
                if (inside) {
                    //printf("%d %d\n", x, y);
                    ans = (ans + f[x + y]) % mod;
                }
            }
        }
        printf("%lld\n", ans);
    }
}
