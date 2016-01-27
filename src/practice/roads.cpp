// http://www.spoj.com/problems/ROADS

#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class node {
    public:
        int pos, len, cost;

        node(int a, int b, int c) {
            pos = a;
            len = b;
            cost = c;
        }

        bool operator < (node a) const {
            if (len == a.len)
                return cost > a.cost;
            else
                return len > a.len;
        }
};

class node1 {
    public:
        vector<int> adj;
        vector<int> len;
        vector<int> cost;
};

bool visited[100][10010];
node1* graph;

int main(void) {
    int t;
    scanf("%d", &t);
    graph = (node1*) calloc(200, sizeof(node1));
    while (t--) {
        int k, n, r;
        scanf("%d %d %d", &k, &n, &r);
        for (int i = 0; i <= n; i++) {
            graph[i].adj.clear();
            graph[i].len.clear();
            graph[i].cost.clear();
        }
        int u, v, l, p;
        for (int i = 0; i < r; i++) {
            scanf("%d %d %d %d", &u, &v, &l, &p);
            graph[u].adj.push_back(v);
            graph[u].len.push_back(l);
            graph[u].cost.push_back(p);
        }
        priority_queue<node> Q;
        Q.push(node(1, 0, 0));
        memset(visited, false, sizeof(visited));
        int ans = -1;
        while (!Q.empty()) {
            node cur = Q.top();
            Q.pop();
            if (visited[cur.pos][cur.cost]) continue;
            visited[cur.pos][cur.cost] = true;

            if (cur.pos == n) {
                ans = cur.len;
                break;
            }

            for (int i = 0; i < graph[cur.pos].adj.size(); i++) {
                int v = graph[cur.pos].adj[i];
                int wt = graph[cur.pos].len[i];
                int cost = graph[cur.pos].cost[i];

                if (cost + cur.cost <= k)
                    Q.push(node(v, wt + cur.len, cost + cur.cost));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
