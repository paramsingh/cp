#include <bits/stdc++.h>
using namespace std;
struct item {
    int p, q;
    item(int a, int b) {
        p = a, q = b;
    }
};

bool cmp(const item& a, const item& b) {
    return a.q < b.q;
}

vector<item> stuff[10];
int n, t, nt;

bool valid(int quality) {
    int cost = 0;
    for (int ty = 1; ty <= 6; ty++) {
        if (stuff[ty].size() == 0)
            continue;
        int mn = 1000000;
        for (int i = 0; i < stuff[ty].size(); i++) {
            if (stuff[ty][i].q >= quality) {
                mn = min(mn, stuff[ty][i].p);
            }
        }
        if (mn == 1000000)
            return false;
        else {
            cost += mn;
        }
    }
    return cost <= t;
}

int done[7] = {0};
int main(void) {
    scanf("%d %d", &n, &t);
    int m = -10000, mn = 100000;
    for (int i = 0; i < n; i++) {
        int tt, p, q;
        scanf("%d %d %d", &tt, &p, &q);
        m = max(m, q);
        mn = min(mn, q);
        done[tt] = 1;
        stuff[tt].push_back(item(p, q));
    }
    for (int i = 1; i <= 6; i++) {
        if (done[i] == 0) {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 1; i <= 6; i++) {
        sort(stuff[i].begin(), stuff[i].end(), cmp);
    }
    int s = mn, e = m;
    if (!valid(0)) {
        printf("0\n");
        return 0;
    }
    while (s < e) {
        int mid = (s + e + 1) / 2;
        if (valid(mid)) {
            s = mid;
        }
        else {
            e = mid - 1;
        }
    }
    printf("%d\n", s);
    return 0;
}
