#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> graph[200100];
set<int> edges[200100];
int parent[200100];
int bfs[200100];
int done[200100];
int leaf[200100];

int depth[200100];


void process() {
    //printf("starting processing...\n");
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    parent[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        //printf("%d\n", u);
        int cnt = 0;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (depth[v]) continue;
            depth[v] = depth[u] + 1;
            parent[v] = u;
            q.push(v);
            cnt++;
        }
        if (cnt == 0) leaf[u] = 1;
    }
    //printf("prcessing done!\n");
}

int check() {
    //printf("checking...\n");
    queue<int> parents;
    //printf("push %d\n", parent[1]);
    parents.push(parent[1]);
    int highest_level = 0;
    for (int i = 1; i <= n; ) {
        // check that nodes aren't being repeated
        if (done[bfs[i]]) {
            //printf("rep\n");
            return 0;
        }
        done[bfs[i]] = 1;

        // check that levels are done in order
        if (depth[bfs[i]] < highest_level) {
            //printf("depth not in order\n");
            return 0;
        }
        highest_level = depth[bfs[i]];

        // make sure that parent is done before child
        int cur = parent[bfs[i]];
        int v = parents.front();
        //printf("pop %d\n", v);
        if (v != cur) {
            //printf("parent not done\n");
            return 0;
        }
        parents.pop();

        while (i <= n && parent[bfs[i]] == cur) {
            edges[cur].erase(bfs[i]);
            if (not leaf[bfs[i]]) {
                parents.push(bfs[i]);
                //printf("push %d\n", bfs[i]);
            }
            i++;
        }
        if (edges[cur].size() > 1)
            return 0;
        if (*edges[cur].begin() != parent[cur])
            return 0;
    }
    //printf("yeayy!\n");
    return 1;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        edges[u].insert(v);
        graph[v].push_back(u);
        edges[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &bfs[i]);
    process();
    printf("%s\n", check() ? "Yes" : "No");
    return 0;
}

