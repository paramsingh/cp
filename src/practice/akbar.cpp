// Do a BFS from each of the soldiers until we reach a node that is patrolled by more
// than one soldier or until all the nodes are covered. Then print the answer accordingly
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int done[1000100] = {0};
int level[1000100] = {0};
vector<int> graph[1000100];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, r, m;
        scanf("%d %d %d", &n, &r, &m);
        memset(done, 0, sizeof(done));
        memset(level, -1, sizeof(level));
        for (int i = 0; i <= n+10; i++) {
            graph[i].clear();
        }
        for (int i = 0; i < r; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<pii> soldiers;
        for (int i = 0; i < m; i++) {
            int num, s;
            scanf("%d %d", &num, &s);
            soldiers.push_back(mp(num, s));
        }
        int flag = 1;
        for (int k = 0; k < soldiers.size(); k++) {
            int src = soldiers[k].first;
            int st = soldiers[k].second;
            queue<int> q;
            if (done[src] != 0) {
                flag = 0;
                break;
            }
            q.push(src);
            done[src] = src;
            level[src] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j = 0; j < graph[u].size(); j++) {
                    int v = graph[u][j];
                    if (level[u] + 1 <= st) {
                        if (done[v] != src && done[v] != 0) {
                            flag = 0;
                            break;
                        }
                        else if (done[v] == 0){
                            q.push(v);
                            level[v] = level[u] + 1;
                            done[v] = src;
                        }
                    }
                }
            }
            if (flag == 0)
                break;
        }
        for (int i = 1; i <= n; i++) {
            if (done[i] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
