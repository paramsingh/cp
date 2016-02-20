#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;

int dist[(1<<16) + 10][16][16];
bool done[(1<<16) + 10][16][16];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int add[4] = {1, 0, 3, 2};
char maze[20][20];
int n, m;

class state {
    public:
        int mask;
        int x, y, d;
        state(int a, int b, int c, int di) {
            mask = a, x = b, y = c;
            d = di;
        }
};

class cmp {
    public:
        bool operator() (const state& a, const state& b) {
            return a.d > b.d;
        }
};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(void) {
    scanf("%d %d", &n, &m);
    int bx, by;
    int sl = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '1')
                bx = i, by = j;
            if ('0' <= maze[i][j] && maze[i][j] <= '9')
                sl = max(sl, maze[i][j] - '0');
        }
    }
    int mask = 0;
    int cx = bx, cy = by;
    int i = 0;
    while (maze[cx][cy] != sl + '0') {
        for (int j = 0; j < 4; j++) {
            int nx = cx + dx[j];
            int ny = cy + dy[j];
            if (maze[nx][ny] == maze[cx][cy] + 1) {
                int b1 = (j >> 0) & 1;
                mask = mask | (b1 << i);
                i++;
                b1 = (j >> 1) & 1;
                mask = mask | (b1 << i);
                i++;
                cx = nx, cy = ny;
                break;
            }
        }
    }
    int last = i-1;
    for (int i = 0; i < (1<<16) + 10; i++) {
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) {
                dist[i][j][k] = INF;
                done[i][j][k] = false;
            }
        }
    }
    priority_queue<state, vector<state>, cmp> pq;
    dist[mask][bx][by] = 0;
    pq.push(state(mask, bx, by, 0));
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        if (maze[cur.x][cur.y] == '@') {
            printf("%d\n", cur.d);
            return 0;
        }
        int cx = cur.x, cy = cur.y, mask = cur.mask, cm = cur.mask;
        set<pii> nope;
        nope.insert(make_pair(cx, cy));
        int j = 0;
        while (j <= last-2) {
            int next = 0;
            int b = (mask >> j) & 1;
            next = next | b;
            j++;
            b = (mask >> j) & 1;
            next = next | (b << 1);
            j++;
            cx = cx + dx[next];
            cy = cy + dy[next];
            nope.insert(make_pair(cx, cy));
        }
        cx = cur.x, cy = cur.y;
        for (int i = 0; i < 4; i++) {
            mask = cm;
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (valid(nx, ny)) {
                if (!nope.count(make_pair(nx, ny))) {
                     if (maze[nx][ny] != '#') {
                        mask = mask << 2;
                        mask = mask | ((add[i] & 1));
                        mask = mask | (((add[i] >> 1) & 1) << 1);
                        for (int j = 31; j > last; j--)
                            mask = mask & ((1 << j) - 1);
                        if (!done[mask][nx][ny] && dist[mask][nx][ny] > dist[cm][cx][cy] + 1) {
                            dist[mask][nx][ny] = dist[cm][cx][cy] + 1;
                            pq.push(state(mask, nx, ny, dist[mask][nx][ny]));
                        }
                    }
                }
            }
        }
        done[cm][cx][cy] = true;
    }
    printf("-1\n");
    return 0;
}
