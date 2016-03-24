// Each row needs to be matched with a column according to the poisonous tile
// The answer will be the minimum vertex cover of that graph which is equal to
// the maximum matching of the graph by Konig's theorem
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200];
int match[200];
int seen[200];

int find(int u) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (seen[v] == 0) {
            seen[v] = 1;
            if (match[v] == -1 || find(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int matching() {
    memset(match, -1, sizeof(match));
    int result = 0;
    for (int i = 0; i < 120; i++) {
        memset(seen, 0, sizeof(seen));
        if (find(i))
            result++;
    }
    return result;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
        }
        printf("%d\n", matching());
        for (int i = 0; i < 120; i++)
            graph[i].clear();
    }
    return 0;
}
