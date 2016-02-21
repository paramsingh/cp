#include <bits/stdc++.h>
#define INF 1000000000
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

class state {
    public:
        int x, y, d;
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

char maze[400][400];
int dist[4][400][400];
int done[4][400][400];

int m, n;
int valid(int x, int y) {
    return x >= 0 && x <= m+1 && y >= 0 && y <= n+1;
}

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &n);
        pii origins[4];
        for (int i = 1; i <= m; i++) {
            maze[i][0] = '.';
            scanf("%s", &maze[i][1]);
            for (int j = 1; j <= n; j++) {
                if ('0' <= maze[i][j] && maze[i][j] <= '9')
                    origins[maze[i][j] - '0'] = mp(i, j);
            }
            maze[i][n+1] = '.';
        }
        for (int i = 0; i <= n+1; i++) {
            maze[0][i] = '.';
            maze[m+1][i] = '.';
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= m+1; j++) {
                for (int k = 0; k <= n+1; k++) {
                    dist[i][j][k] = INF;
                    done[i][j][k] = 0;
                }
            }
        }
        for (int i = 1; i <= 3; i++) {
            int bx = origins[i].first, by = origins[i].second;
            priority_queue<state, vector<state>, cmp> pq;
            dist[i][bx][by] = 0;
            pq.push(state(bx, by, 0));
            while (!pq.empty()) {
                state cur = pq.top();
                pq.pop();
                int cx = cur.x, cy = cur.y, d = cur.d;
                for (int j = 0; j < 4; j++) {
                    int nx = cx + dx[j];
                    int ny = cy + dy[j];
                    if (!valid(nx, ny))
                        continue;
                    if (maze[nx][ny] == '#')
                        continue;
                    if (!done[i][nx][ny] && dist[i][nx][ny] > dist[i][cx][cy] + 1) {
                        dist[i][nx][ny] = dist[i][cx][cy] + 1;
                        pq.push(state(nx, ny, dist[i][nx][ny]));
                    }
                }
                done[i][cx][cy] = 1;
            }
        }
        int ans = INF;
        for (int i = 0; i <= m+1; i++) {
            for (int j = 0; j <= n+1; j++) {
                if (dist[1][i][j] != INF && dist[2][i][j] != INF && dist[3][i][j] != INF) {
                    int val = max(dist[1][i][j], dist[2][i][j]);
                    val = max(val, dist[3][i][j]);
                    if (val < ans)
                        ans = val;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
