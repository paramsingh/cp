// 14:58
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int dist[(1<<10) + 20][100][100];
int done[(1 << 10) + 20][100][100];
int maze[100][100];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n;

int valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

class state {
    public:
        int x, y, d;
        int mask;
        state(int a, int b, int c, int m) {
            x = a, y = b, d = c;
            mask = m;
        }
};

class cmp {
    public:
        bool operator() (const state &a, const state &b) {
            return a.d > b.d;
        }
};

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int mask = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &maze[i][j]);
            }
        }
        for (int i = 0; i < (1 << 10) + 20; i++) {
            for (int j = 0; j < 100; j++)
                for (int k = 0; k < 100; k++) {
                    dist[i][j][k] = 1000000000;
                    done[i][j][k] = 0;
                }
        }

        int bx, by;
        scanf("%d %d", &bx, &by);
        int ex, ey;
        scanf("%d %d", &ex, &ey);
        priority_queue<state, vector<state>, cmp> pq;
        mask = mask | (1 << maze[bx][by]);
        dist[mask][bx][by] = 1;
        pq.push(state(bx, by, 1, mask));
        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            int cx = cur.x, cy = cur.y, d = cur.d, m = cur.mask;
            if (cx == ex && cy == ey) {
                printf("%d\n", d);
                break;
            }
            for (int i = 0; i < 4; i++) {
                m = cur.mask;
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (!valid(nx, ny))
                    continue;
                int boss = maze[nx][ny];
                if ((m >> boss) & 1) {
                    if (!done[m][nx][ny] && dist[m][nx][ny] > d) {
                        dist[m][nx][ny] = d;
                        pq.push(state(nx, ny, d, m));
                    }
                }
                else {
                    m = m | (1 << boss);
                    if (!done[m][nx][ny] && dist[m][nx][ny] > d + 1) {
                        dist[m][nx][ny] = d + 1;
                        pq.push(state(nx, ny, d + 1, m));
                    }
                }
            }
            m = cur.mask;
            done[m][cx][cy] = 1;
        }
    }
    return 0;
}
