/** http://codeforces.com/problemset/problem/217/A */
#include <bits/stdc++.h>
using namespace std;

class node {
    public: int x, y;
            vector<int> adj;
            int visited;
};

node* graph;

void dfs(int cur) {
    graph[cur].visited = 1;
    for (int i = 0; i < graph[cur].adj.size(); i++) {
        if (graph[graph[cur].adj[i]].visited == 0)
            dfs(graph[cur].adj[i]);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    graph = (node*) calloc(n+10, sizeof(node));
    for (int i = 0; i < n; i++)
        scanf("%d %d", &graph[i].x, &graph[i].y);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i].x == graph[j].x || graph[i].y == graph[j].y)
                graph[i].adj.push_back(j);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (graph[i].visited == 0) {
            count++;
            dfs(i);
        }
    }
    printf("%d\n", count-1);
    return 0;
}
