#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
typedef pair<int, int> pii;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dist[30][30][30][30];
int done[30][30];
vector<pii> dirt;
char maze[30][30];
int n, m;
int dc;
int dp[21][21][1050];

inline int valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int ans(int x, int y, int mask) {
    if (dp[x][y][mask] != -1)
        return dp[x][y][mask];

    if (mask == (1 << dc) - 1)
        return 0;

    int sol = INF;
    for (int i = 0; i < dc; i++) {
        if ((mask >> i) & 1)
            continue;
        else {
            int nx = dirt[i].first, ny = dirt[i].second;
            if (dist[x][y][nx][ny] != -1)
                sol = min(sol, ans(nx, ny, mask | (1 << i)) + dist[x][y][nx][ny]);
        }
    }
    return dp[x][y][mask] = sol;
}

int main(void) {
    scanf("%d %d", &m, &n);
    while (n != 0 && m != 0) {
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]);
        int sx, sy;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'o')
                    sx = i, sy = j;
                else if (maze[i][j] == '*') {
                    dirt.push_back(make_pair(i, j));
                    dc++;
                }
            }
        }
        dirt.push_back(make_pair(sx, sy));
        for (int i = 0; i < dirt.size(); i++) {
            memset(done, 0, sizeof(done));
            int a = dirt[i].first, b = dirt[i].second;
            dist[a][b][a][b] = 0;
            done[a][b] = 1;
            queue<pii> q;
            q.push(make_pair(a, b));
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (valid(nx, ny) && done[nx][ny] == 0 && maze[nx][ny] != 'x') {
                        dist[a][b][nx][ny] = dist[a][b][x][y] + 1;
                        done[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        dirt.pop_back();
        memset(dp, -1, sizeof(dp));
        printf("%d\n", ans(sx, sy, 0) == INF ? -1 : ans(sx, sy, 0));
        dirt.clear();
        dc = 0;
        scanf("%d %d", &m, &n);
    }
    return 0;
}
