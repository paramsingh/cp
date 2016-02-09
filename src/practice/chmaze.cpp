// http://www.spoj.com/problems/CHMAZE/

#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

char maze[20][30][30];

class state {
    public:
        int x, y;
        int s, l;
        state(int a, int b, int c, int d) {
            x = a, y = b, s = c, l = d;
        }
};

class pri {
    public:
        bool operator() (const state& a, const state& b) {
            return a.l > b.l;
        }
};

int dist[20][30][30];
int visited[20][30][30];

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

int main(void) {
    int m, n, st;
    int cs = 0;
    scanf("%d %d %d", &m, &n, &st);
    while (m != 0 && n != 0 && st != 0) {
        for (int k = 0; k < st; k++) {
            for (int i = 0; i < m; i++) {
                scanf("%s", maze[k][i]);
                for (int j = 0; j < n; j++) {
                    visited[k][i][j] = 0;
                    dist[k][i][j] = INF;
                }
            }
        }
        dist[0][0][0] = 0;
        priority_queue<state, vector<state>, pri> pq;
        pq.push(state(0, 0, 0, dist[0][0][0]));
        int ans = -1;
        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            int x = cur.x, y = cur.y, s = cur.s, l = cur.l;
            if (x == m-1 && y == n-1) {
                ans = l;
                break;
            }
            for (int d = 0; d < 5; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int ns = (s + 1) % st;
                int nl = l + 1;
                if (maze[ns][nx][ny] == '0' && visited[ns][nx][ny] == 0) {
                    if (dist[ns][nx][ny] > nl) {
                        dist[ns][nx][ny] = nl;
                        pq.push(state(nx, ny, ns, nl));
                    }
                }
            }
            visited[s][x][y] = 1;
        }
        printf("Case %d: ", ++cs);
        if (ans == -1)
            printf("Luke and Leia cannot escape.\n");
        else
            printf("Luke and Leia can escape in %d steps.\n", ans);
        scanf("%d %d %d", &m, &n, &st);
    }
    return 0;
}
