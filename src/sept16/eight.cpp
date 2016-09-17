#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265359;
typedef pair<int, int> pii;

// area between intersection of circle and rectangle taken from http://stackoverflow.com/a/32698993
double section(double h, double r = 1)
{
    assert(r >= 0);
    return (h < r)? sqrt(r * r - h * h) : 0;
}

double g(double x, double h, double r = 1)
{
    return .5f * (sqrt(1 - x * x / (r * r)) * x * r + r * r * asin(x / r) - 2 * h * x);
}

double area(double x0, double x1, double h, double r)
{
    if(x0 > x1)
        std::swap(x0, x1);
    double s = section(h, r);
    return g(max(-s, min(s, x1)), h, r) - g(max(-s, min(s, x0)), h, r);
}

double area(double x0, double x1, double y0, double y1, double r)
{
    if(y0 > y1)
        std::swap(y0, y1);
    if(y0 < 0) {
        if(y1 < 0)
            return area(x0, x1, -y0, -y1, r);
        else
            return area(x0, x1, 0, -y0, r) + area(x0, x1, 0, y1, r);
    } else {
        assert(y1 >= 0);
        return area(x0, x1, y0, r) - area(x0, x1, y1, r);
    }
}

double area(double x0, double x1, double y0, double y1, double cx, double cy, double r)
{
    x0 -= cx; x1 -= cx;
    y0 -= cy; y1 -= cy;

    return area(x0, x1, y0, y1, r);
}

struct c {
    int x, y, r;
    bool operator< (const c& a) const {
        if (x == a.x)
            return y < a.y;
        return x < a.x;
    }
} circle[100100];

bool cmp(const c& a, const c& b) {
    return a.y < b.y;
}

vector<c> blocks[300];
vector<c> byx[50010];
vector<c> byy[50010];
set<pii> mp;

void print(vector<c> a) {
    for (int i = 0; i < a.size(); i++) {
        printf("%d %d\n", a[i].x, a[i].y);
    }
}

int find(vector<c>& a, int l, int r) {
    if (a.empty())
        return 0;
    // finding first value greater than l
    int lo = 0, hi = a.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid].y <= l)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (a[lo].y <= l)
        return 0;
    int left = lo;

    // find last value smaller than r
    lo = 0, hi = a.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (a[mid].y >= r)
            hi = mid - 1;
        else
            lo = mid;
    }
    if (a[lo].y >= r)
        return 0;
    else
        return lo - left + 1;
}

int find1(vector<c>& a, int l, int r) {
    if (a.empty())
        return 0;
    // finding first value greater than l
    int lo = 0, hi = a.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid].x <= l)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (a[lo].x <= l)
        return 0;
    int left = lo;

    // find last value smaller than r
    lo = 0, hi = a.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (a[mid].x >= r)
            hi = mid - 1;
        else
            lo = mid;
    }
    if (a[lo].x >= r)
        return 0;
    else
        return lo - left + 1;
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);
    int special = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &circle[i].x, &circle[i].y, &circle[i].r);
        if (circle[i].r != 1)
            special = 0;
    }
    if (!special) {
        while (q--) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            double ans = 0;
            for (int i = 0; i < n; i++)
                ans += area(x1, x2, y1, y2, circle[i].x, circle[i].y, circle[i].r);
            printf("%0.15lf\n", ans);
        }
    }
    else {
        int sq = 224; // sqrt of 50000
        sort(circle, circle + n);
        for (int i = 0; i < n; i++) {
            int x = circle[i].x, y = circle[i].y;
            byx[x].push_back(circle[i]);
            byy[y].push_back(circle[i]);
            blocks[x / sq].push_back(circle[i]);
            mp.insert(make_pair(x, y));
        }
        for (int i = 0; i < 300; i++)
            if (!blocks[i].empty())
                sort(blocks[i].begin(), blocks[i].end(), cmp);
        for (int i = 0; i <= 50000; i++)
            if (!byy[i].empty())
                sort(byy[i].begin(), byy[i].end());
        while (q--) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            int fb = x1 / sq;
            int lb = x2 / sq;
            double ans = 0;
            for (int i = fb + 1; i <= lb - 1; i++)
                ans += find(blocks[i], y1, y2) * pi;
            if (fb < lb) {
                for (int x = x1 + 1; x < (fb + 1) * sq; x++)
                    ans += find(byx[x], y1, y2) * pi;
                for (int x = lb * sq; x < x2; x++)
                    ans += find(byx[x], y1, y2) * pi;
            }
            else {
                for (int x = x1 + 1; x < x2; x++)
                    ans += find(byx[x], y1, y2) * pi;
            }
            ans += find(byx[x1], y1, y2) * pi / 2.0;
            ans += find(byx[x2], y1, y2) * pi / 2.0;
            ans += find1(byy[y1], x1, x2) * pi / 2.0;
            ans += find1(byy[y2], x1, x2) * pi / 2.0;
            if (mp.count(make_pair(x1, y1)))
                ans += pi / 4.0;
            if (mp.count(make_pair(x1, y2)))
                ans += pi / 4.0;
            if (mp.count(make_pair(x2, y2)))
                ans += pi / 4.0;
            if (mp.count(make_pair(x2, y1)))
                ans += pi / 4.0;
            printf("%.15lf\n", ans);
        }
    }
    return 0;
}
