#include <bits/stdc++.h>
#define valid(i, j) (i >= 0 && i < n && j >= 0 && j < m)
using namespace std;
typedef pair<int, int> pii;

int maze[101][101];
int cx[4] = {-1, 1, 1, -1};
int cy[4] = {1, -1, 1, -1};
int dist1[101][101];
int dist2[101][101];
int temp[101][101];
int n, m;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k1, k2;
        scanf("%d %d %d %d", &n, &m, &k1, &k2);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &maze[i][j]);

        memset(dist1, -1, sizeof(dist1));
        queue<pii> q;
        q.push(make_pair(0, 0));
        dist1[0][0] = 0;
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int dx = 0; dx <= k1; dx++) {
                for (int dy = 0; dy <= k1 - dx; dy++) {
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx * cx[i];
                        int ny = y + dy * cy[i];
                        if (valid(nx, ny) && dist1[nx][ny] == -1 && maze[nx][ny] != 1) {
                            dist1[nx][ny] = dist1[x][y] + 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }

        memset(dist2, -1, sizeof(dist2));
        dist2[0][m - 1] = 0;
        q.push(make_pair(0, m - 1));
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int dx = 0; dx <= k2; dx++) {
                for (int dy = 0; dy <= k2 - dx; dy++) {
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx * cx[i];
                        int ny = y + dy * cy[i];
                        if (valid(nx, ny) && dist2[nx][ny] == -1 && maze[nx][ny] != 1) {
                            dist2[nx][ny] = dist2[x][y] + 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }

        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist1[i][j] != -1 && dist2[i][j] != -1)
                    mn = min(mn, max(dist1[i][j], dist2[i][j]));
            }
        }
        printf("%d\n", mn == INT_MAX ? -1 : mn);
    }
    return 0;
}

