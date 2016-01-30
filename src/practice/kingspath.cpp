// http://codeforces.com/problemset/problem/242/C

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

set<pii> allowed;
map<pii, int> depth;

int main(void) {
    int x, y, u, v;
    scanf("%d %d %d %d", &x, &y, &u, &v);
    int n;
    scanf("%d", &n);
    while (n--) {
        int r, a, b;
        scanf("%d %d %d", &r, &a, &b);
        for (int i = a; i <= b; i++)
            allowed.insert(mp(r, i));
    }
    queue<pii> q;
    q.push(mp(x, y));
    depth[mp(x, y)] = 0;
    while (!q.empty()) {
        pii cur = q.front();
        int a = cur.first, b = cur.second;
        q.pop();
        int d = depth[cur];
        if (cur.first == u && cur.second == v) {
            printf("%d\n", d);
            return 0;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (!allowed.count(mp(a+i, b+j)) || depth.count(mp(a+i, b+j)))
                    continue;
                else {
                    depth[mp(a+i, b+j)] = d + 1;
                    q.push(mp(a+i, b+j));
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
