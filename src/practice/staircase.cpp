#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> graph[30];
int dist[40];
int done[40];

class cmp {
    public:
        bool operator() (const pii& a, const pii& b) {
            return a.second > b.second;
        }
};

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            dist[i] = 10000000;
            done[i] = 0;
            graph[i].clear();
        }
        for (int i = 0; i < n; i++) {
            int nxt;
            scanf("%d", &nxt);
            graph[i].push_back(i+1);
            if (i + nxt > n || i + nxt < 0 || nxt == 1)
                continue;
            graph[i].push_back(i+nxt);
        }
        priority_queue<pii, vector<pii>, cmp> pq;
        dist[0] = 0;
        pq.push(mp(0, 0));
        int ans = -1;
        while (!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            if (cur.first == n) {
                ans = cur.second;
                break;
            }
            int u = cur.first, d = cur.second;
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (!done[v] && dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    pq.push(mp(v, dist[v]));
                }
            }
            done[u] = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
