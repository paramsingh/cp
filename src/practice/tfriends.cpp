// http://www.spoj.com/problems/TFRIENDS
#include <bits/stdc++.h>
using namespace std;

int adj[200][200];
int tp[200][200];
int visited[200] = {0};
int n;

int fin = 0;
class node {
    public:
        int fin;
        int index;
};

node* graph;

void dfs(int cur) {
    if (visited[cur] == 1)
        return;
    visited[cur] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[cur][i] == 1)
            dfs(i);
    }
    graph[cur].fin = ++fin;
}

void dfs2(int cur) {
    if (visited[cur] == 1)
        return;
    visited[cur] = 1;
    for (int i = 0; i < n; i++) {
        if (tp[cur][i] == 1)
            dfs2(i);
    }
}

bool cmp(const node& a, const node& b) {
    return a.fin > b.fin;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        fin = 0;
        scanf("%d", &n);
        graph = (node*) calloc(n+10, sizeof(node));
        char arr[200];
        for (int i = 0; i < n; i++) {
            graph[i].index = i;
            scanf("%s", arr);
            for (int j = 0; j < n; j++) {
                if (arr[j] == 'Y') {
                    adj[i][j] = 1;
                    tp[j][i] = 1;
                }
                else {
                    adj[i][j] = 0;
                    tp[j][i] = 0;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        sort(graph, graph+n, cmp);
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (visited[graph[i].index] == 0) {
                dfs2(graph[i].index);
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
