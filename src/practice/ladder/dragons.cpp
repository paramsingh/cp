#include <bits/stdc++.h>
using namespace std;

struct dragon {
    int x, y;
} dragons[100100];

bool cmp(const dragon& a, const dragon& b) {
    if (a.x == b.x)
        return a.y > b.y;
    return a.x < b.x;
}

int main(void) {
    int s, n;
    scanf("%d %d", &s, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &dragons[i].x, &dragons[i].y);
    sort(dragons + 1, dragons + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        if (s <= dragons[i].x) {
            printf("NO\n");
            return 0;
        }
        s += dragons[i].y;
    }
    printf("YES\n");
    return 0;
}
