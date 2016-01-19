// http://codeforces.com/problemset/problem/246/D
#include <bits/stdc++.h>
using namespace std;

set<int> added[100010];
int n, m;
int u, v;
int card[100100];
int color[100100];

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= 100000; i++)
        card[i] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", color+i);
        card[color[i]] = 0;
    }
    while (m--) {
        scanf("%d %d", &u, &v);
        if (color[u] != color[v]) {
            if (added[color[u]].find(color[v]) == added[color[u]].end()) {
                added[color[u]].insert(color[v]);
                card[color[u]]++;
            }
            if (added[color[v]].find(color[u]) == added[color[v]].end()) {
                added[color[v]].insert(color[u]);
                card[color[v]]++;
            }
        }
    }
    int id = -1;
    for (int i = 1; i <= 100000; i++) {
        if (card[i] != -1) {
            if (id == -1 || card[i] > card[id])
                id = i;
        }
    }
    printf("%d\n", id);
    return 0;
}

