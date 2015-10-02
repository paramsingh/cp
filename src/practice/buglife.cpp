#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

class Solver {
    public:
        int v;
        int **adj;
        int *color;
        Solver(int n) {
            v = n;
            adj = new int*[n];
            color = new int[n];
            for (int i = 0; i < n; i++){
                adj[i] = new int[n];
                color[i] = -1;
                for (int j = 0; j < n; j++)
                    adj[i][j] = 0;
            }
        }

        void add(int i, int j) {
            adj[i][j] = 1;
            adj[j][i] = 1;
        }

        bool check(int src) {
            color[src] = 1;
            queue<int> q;
            q.push(src);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int i = 0; i < v; i++) {
                    if (adj[u][i] && color[i] == -1) {
                        color[i] = 1 - color[u];
                        q.push(i);
                    }
                    else if (adj[u][i] && color[i] == color[u])
                        return false;
                }
            }
            return true;
        }
};

int main(void) {
    int t;
    scanf("%d", &t);
    for (int a = 1; a <= t; a++) {
        printf("Scenario #%d:\n", a);
        int v, e;
        scanf("%d %d", &v, &e);
        Solver* s = new Solver(v);
        int x, y;
        for (int i = 0; i < e; i++) {
            scanf("%d %d", &x, &y);
            s->add(x-1, y-1);
        }
        bool ans = true;
        for (int i = 0; i < v; i++) {
            if (s->color[i] == -1) {
               ans = s->check(i);
               if (!ans) break;
            }
        }
        if (!ans)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        delete s;
    }
}



