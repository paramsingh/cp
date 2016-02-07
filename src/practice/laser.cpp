// http://www.spoj.com/problems/LASER/

#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
typedef pair<int, int> pii;

int done[5][110][110];
bool cant[110][110][5];
int dist[5][110][110];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

class state {
    public:
        int i, j;
        int s, level;
        state(int a, int b, int c, int d) {
            i = a; j = b; s = c; level = d;
        }
};

class pri {
    public:
        bool operator() (const state& a, const state& b) {
            return a.level > b.level;
        }
};

char maze[200][200];
int m, n;

int main(void) {
    int t;
    scanf("%d", &t);
    int cs = 0;
    while (t--) {
        memset(cant, false, sizeof(cant));
        memset(done, 0, sizeof(done));
        int bi, bj, ei, ej;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            getchar_unlocked();
            for (int j = 0; j < n; j++) {
                maze[i][j] = getchar_unlocked();
                char c = maze[i][j];
                if (c == 'S') {
                    bi = i;
                    bj = j;
                    maze[i][j] = '.';
                }
                else if (c == 'G') {
                    ei = i;
                    ej = j;
                    maze[i][j] = '.';
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = maze[i][j];
                int k;
                if (c == 'v') {
                    for (k = i+1; k < m && maze[k][j] == '.'; k++)
                        cant[k][j][0] = true;
                    for (k = j-1; k >= 0 && maze[i][k] == '.'; k--)
                        cant[i][k][1] = true;
                    for (k = i-1; k >= 0 && maze[k][j] == '.'; k--)
                        cant[k][j][2] = true;
                    for (k = j+1; k < n && maze[i][k] == '.'; k++)
                        cant[i][k][3] = true;
                }
                else if (c == '<') {
                    for (k = j-1; k >= 0 && maze[i][k] == '.'; k--)
                        cant[i][k][0] = true;
                    for (k = i-1; k >= 0 && maze[k][j] == '.'; k--)
                        cant[k][j][1] = true;
                    for (k = j+1; k < n && maze[i][k] == '.'; k++)
                        cant[i][k][2] = true;
                    for (k = i+1; k < m && maze[k][j] == '.'; k++)
                        cant[k][j][3] = true;
                }
                else if (c == '^') {
                    for (k = i-1; k >= 0 && maze[k][j] == '.'; k--)
                        cant[k][j][0] = true;
                    for (k = j+1; k < n && maze[i][k] == '.'; k++)
                        cant[i][k][1] = true;
                    for (k = i+1; k < m && maze[k][j] == '.'; k++) {
                        cant[k][j][2] = true;
                    }
                    for (k = j-1; k >= 0 && maze[i][k] == '.'; k--)
                        cant[i][k][3] = true;
                }
                else if (c == '>') {
                    for (k = j+1; k < n && maze[i][k] == '.'; k++)
                        cant[i][k][0] = true;
                    for (k = i+1; k < m && maze[k][j] == '.'; k++)
                        cant[k][j][1] = true;
                    for (k = j-1; k >= 0 && maze[i][k] == '.'; k--)
                        cant[i][k][2] = true;
                    for (k = i-1; k >= 0 && maze[k][j] == '.'; k--)
                        cant[k][j][3] = true;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <= 100; j++) {
                for (int k = 0; k <= 100; k++)
                    dist[i][j][k] = INF;
            }
        }
        priority_queue<state, vector<state>, pri> pq;
        pq.push(state(bi, bj, 0, 0));
        dist[0][bi][bj] = 0;
        int ans = -1;
        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            if (cur.i == ei && cur.j == ej) {
                ans = cur.level;
                break;
            }
            for (int d = 0; d < 4; d++) {
                int nx = cur.i + dx[d];
                int ny = cur.j + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                    state next = state(nx, ny, (cur.s + 1) % 4, cur.level + 1);
                    if (!cant[nx][ny][next.s] && !done[next.s][nx][ny]) {
                        if (dist[next.s][nx][ny] > dist[cur.s][cur.i][cur.j] + 1)
                        {
                            dist[next.s][nx][ny] = dist[cur.s][cur.i][cur.j] + 1;
                            pq.push(next);
                        }
                    }
                }
            }
            done[cur.s][cur.i][cur.j] = 1;
        }
        if (ans == -1)
            printf("Case #%d: impossible\n", ++cs);
        else
            printf("Case #%d: %d\n", ++cs, ans);
    }
    return 0;
}
