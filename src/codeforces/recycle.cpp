#include <bits/stdc++.h>
using namespace std;

struct point {
    int id, x, y;
    double dist;
};

point bottles[100100];
point dista[100100];
point distb[100100];
double distr[100100];

bool cmp(const point& a, const point& b) {
    return a.dist < b.dist;
}

int main(void) {
    int ax, ay, bx, by, tx, ty;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
    int n;
    scanf("%d", &n);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bottles[i].x, &bottles[i].y);
        double dx = tx - bottles[i].x;
        double dy = ty - bottles[i].y;
        distr[i] = sqrt(dx * dx + dy * dy);
        ans += distr[i];
    }
    ans = ans * 2;
    for (int i = 0; i < n; i++) {
        dista[i].id = i;
        double dx = ax - bottles[i].x;
        double dy = ay - bottles[i].y;
        double d = sqrt(dx * dx + dy * dy);
        dista[i].dist = d - distr[i];
        distb[i].id = i;
        dx = bx - bottles[i].x;
        dy = by - bottles[i].y;
        d = sqrt(dx * dx + dy * dy);
        distb[i].dist = d - distr[i];
    }
    sort(dista, dista+n, cmp);
    sort(distb, distb+n, cmp);
    if (n == 1) {
        if (dista[0].dist > distb[0].dist)
            ans += distb[0].dist;
        else
            ans += dista[0].dist;
        printf("%.6lf\n", ans);
    }
    else {
        if (dista[0].id == distb[0].id) {
            if (dista[0].dist + distb[1].dist < dista[1].dist + distb[0].dist) {
                ans += dista[0].dist + distb[1].dist;
            }
            else {
                ans += dista[1].dist + distb[0].dist;
            }
        }
        else {
            ans += dista[0].dist + distb[0].dist;
        }
        printf("%.6lf\n", ans);
    }
    return 0;
}

