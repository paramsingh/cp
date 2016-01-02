#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)

int ca, cb, cc;

int bfs() {
    queue<pii> q;
    set<pii> visited;
    map<pii, int> levels;
    int a = 0, b = 0;
    q.push(mp(a, b));
    levels[mp(a, b)] = 0;
    while (!q.empty()) {
        pii cur = q.front();
        a = cur.first, b = cur.second;
        int l = levels[cur];
        if (a == cc || b == cc)
            return l;
        int na, nb;
        q.pop();
        if (a != 0) {
            na = 0, nb = b;
            if (visited.find(mp(na, nb)) == visited.end()) {
                q.push(mp(na, nb));
                levels[mp(na, nb)] = l+1;
                visited.insert(mp(na, nb));
            }
        }
        if (b != 0) {
            na = a, nb = 0;
            if (visited.find(mp(na, nb)) == visited.end()) {
                q.push(mp(na, nb));
                levels[mp(na, nb)] = l+1;
                visited.insert(mp(na, nb));
            }
        }
        if (a != ca) {
            na = ca, nb = b;
            if (visited.find(mp(na, nb)) == visited.end()) {
                q.push(mp(na, nb));
                levels[mp(na, nb)] = l+1;
                visited.insert(mp(na, nb));
            }
        }
        if (b != cb) {
            na = a, nb = cb;
             if (visited.find(mp(na, nb)) == visited.end()) {
                q.push(mp(na, nb));
                levels[mp(na, nb)] = l+1;
                visited.insert(mp(na, nb));
            }
        }
        if (a != 0 && b != cb) {
            if (a + b > cb)
                nb = cb, na = a + b - cb;
            else
                nb = a + b, na = 0;
             if (visited.find(mp(na, nb)) == visited.end()) {
                q.push(mp(na, nb));
                levels[mp(na, nb)] = l+1;
                visited.insert(mp(na, nb));
            }
        }
        if (b != 0 && a != ca) {
            if (a + b > ca)
                na = ca, nb = a + b - ca;
            else
                na = a + b, nb = 0;
             if (visited.find(mp(na, nb)) == visited.end()) {
                q.push(mp(na, nb));
                levels[mp(na, nb)] = l+1;
                visited.insert(mp(na, nb));
            }
        }
    }
    return -1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &ca, &cb, &cc);
        printf("%d\n", bfs());
    }
    return 0;
}
