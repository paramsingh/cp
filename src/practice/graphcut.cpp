// http://www.spoj.com/problems/GRAPHCUT/

#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int cc;
        int part;
        int visited;
        vector<int> adj;
};

class edge {
    public: int u, v;
};

node* graph;
edge* cut;
int cct = 0;

void dfs(int cur) {
    graph[cur].visited = 1;
    graph[cur].cc = cct;
    for (int i = 0; i < graph[cur].adj.size(); i++) {
        int v = graph[cur].adj[i];
        if (graph[v].visited == 0)
            dfs(v);
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, e, k;
        cct = 0;
        scanf("%d %d %d", &n, &e, &k);
        graph = (node*) calloc(n+10, sizeof(node));
        cut = (edge*) calloc(k+10, sizeof(edge));
        for (int i = 0; i < k; i++)
            scanf("%d %d", &cut[i].u, &cut[i].v);
        int u, v;
        for (int i = k; i < e; i++) {
            scanf("%d %d", &u, &v);
            graph[u].adj.push_back(v);
            graph[v].adj.push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (graph[i].visited == 0) {
                cct++;
                dfs(i);
            }
        }
        int flag = 0;
        for (int i = 0; i < k; i++) {
            int x = cut[i].u;
            int y = cut[i].v;
            if (graph[x].cc == graph[y].cc) {
                flag = 1;
                break;
            }
            else if (graph[x].part == 0 && graph[y].part == 0) {
                for (int j = 1; j <= n; j++) {
                    if (graph[j].cc == graph[x].cc)
                        graph[j].part = 1;
                    if (graph[j].cc == graph[y].cc)
                        graph[j].part = 2;
                }
            }
            else if (graph[x].part == 0) {
                int color = graph[y].part == 1 ? 2 : 1;
                for (int j = 1; j <= n; j++) {
                    if (graph[j].cc == graph[x].cc)
                        graph[j].part = color;
                }
            }
            else if (graph[y].part == 0) {
                int color = graph[x].part == 1 ? 2 : 1;
                for (int j = 1; j <= n; j++) {
                    if (graph[j].cc == graph[y].cc)
                        graph[j].part = color;
                }
            }
            else {
                if (graph[x].part == graph[y].part) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            printf("NO\n");
        else
            printf("YES\n");
        free(graph);
        free(cut);
    }
    return 0;
}

