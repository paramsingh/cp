// 14:27
#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

class state {
    public:
        int x, y;
        int d;
        state(int a, int b, int c) {
            x = a, y = b, d = c;
        }
};

class cmp {
    public:
        bool operator() (const state& a, const state& b) {
            return a.d > b.d;
        }
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;

bool valid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

char maze[300][300];
int tme[300][300];
int dist[300][300];
int done[300][300];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++)
            scanf("%s", maze[i]);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = INF;
                done[i][j] = 0;
                scanf("%d", &tme[i][j]);
            }
        }
        int bx, by;
        scanf("%d %d", &bx, &by);
        int ex, ey;
        scanf("%d %d", &ex, &ey);
        priority_queue<state, vector<state>, cmp> pq;
        dist[bx][by] = 0;
        pq.push(state(bx, by, 0));
        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            int cx = cur.x, cy = cur.y, d = cur.d;
            if (cx == ex && cy == ey) {
                printf("%d\n", cur.d);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (!valid(nx, ny))
                    continue;
                if (maze[nx][ny] == '#') {
                    int ft;
                    if (d >= tme[nx][ny])
                        ft = d + 1;
                    else
                        ft = tme[nx][ny];
                    if (!done[nx][ny] && dist[nx][ny] > ft) {
                        dist[nx][ny] = ft;
                        pq.push(state(nx, ny, ft));
                    }
                }
                else {
                    if (!done[nx][ny] && dist[nx][ny] > dist[cx][cy] + 1) {
                        dist[nx][ny] = dist[cx][cy] + 1;
                        pq.push(state(nx, ny, dist[nx][ny]));
                    }
                }
            }
            done[cx][cy] = 1;
        }
    }
    return 0;
}
