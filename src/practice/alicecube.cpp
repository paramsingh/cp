// Start a bfs from the destination state to save all the answers in a precomputation
// and then answer all the queries in O(1)
#include <bits/stdc++.h>
using namespace std;

vector<int> G[20];
void pushall()
{
    G[0].push_back(1);
    G[0].push_back(2);
    G[0].push_back(8);
    G[0].push_back(4);

    G[1].push_back(0);
    G[1].push_back(3);
    G[1].push_back(5);
    G[1].push_back(9);

    G[2].push_back(0);
    G[2].push_back(3);
    G[2].push_back(6);
    G[2].push_back(10);

    G[3].push_back(1);
    G[3].push_back(2);
    G[3].push_back(11);
    G[3].push_back(7);

    G[4].push_back(0);
    G[4].push_back(6);
    G[4].push_back(5);
    G[4].push_back(12);

    G[5].push_back(4);
    G[5].push_back(7);
    G[5].push_back(13);
    G[5].push_back(1);

    G[6].push_back(2);
    G[6].push_back(4);
    G[6].push_back(7);
    G[6].push_back(14);

    G[7].push_back(15);
    G[7].push_back(3);
    G[7].push_back(6);
    G[7].push_back(5);

    G[8].push_back(0);
    G[8].push_back(12);
    G[8].push_back(10);
    G[8].push_back(9);

    G[9].push_back(8);
    G[9].push_back(1);
    G[9].push_back(11);
    G[9].push_back(13);

    G[10].push_back(2);
    G[10].push_back(14);
    G[10].push_back(8);
    G[10].push_back(11);

    G[11].push_back(10);
    G[11].push_back(15);
    G[11].push_back(3);
    G[11].push_back(9);

    G[12].push_back(8);
    G[12].push_back(4);
    G[12].push_back(13);
    G[12].push_back(14);

    G[13].push_back(5);
    G[13].push_back(12);
    G[13].push_back(9);
    G[13].push_back(15);

    G[14].push_back(12);
    G[14].push_back(15);
    G[14].push_back(10);
    G[14].push_back(6);

    G[15].push_back(7);
    G[15].push_back(14);
    G[15].push_back(13);
    G[15].push_back(11);
}

int level[1 << 18];

int main(void) {
    pushall();
    memset(level, -1, sizeof(level));
    int start = 0;
    for (int i = 0; i <= 7; i++)
        start |= (1 << i);
    level[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (level[cur] >= 4)
            break;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                int v = G[i][j];
                int ith = (cur >> i) & 1;
                int vth = (cur >> v) & 1;
                if (ith != vth) {
                    int nxt = cur ^ (1 << i);
                    nxt = nxt ^ (1 << v);
                    if (level[nxt] == -1) {
                        level[nxt] = level[cur] + 1;
                        q.push(nxt);
                    }
                }
            }
        }
    }
    int t, cnt = 1;
    scanf("%d", &t);
    while (t--) {
        int state = 0;
        for (int i = 15; i >= 0; i--) {
            int bit;
            scanf("%d", &bit);
            state |= (bit << i);
        }
        printf("Case #%d: ", cnt++);
        if (level[state] >= 4 || level[state] == -1)
            printf("more\n");
        else
            printf("%d\n", level[state]);
    }
    return 0;
}
