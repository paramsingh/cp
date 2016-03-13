#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int parent[30000];
int dist[30000];

pii root(int x) {
    if (parent[x] == x)
        return mp(x, 0);
    else {
        pii a = root(parent[x]);
        parent[x] = a.first;
        dist[x] = dist[x] + a.second;
        return mp(a.first, dist[x]);
    }
}

void un(int a, int b) {
    parent[a] = b;
    if (a > b)
        dist[a] = (a - b) % 1000;
    else
        dist[a] = (b - a) % 1000;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            dist[i] = 0;
        }
        char type[5];
        scanf("%s", type);
        int x, y;
        while (type[0] != 'O') {
            if (type[0] == 'E') {
                scanf("%d", &x);
                printf("%d\n", root(x).second);
            }
            else {
                scanf("%d %d", &x, &y);
                un(x, y);
            }
            scanf("%s", type);
        }
    }
    return 0;
}
