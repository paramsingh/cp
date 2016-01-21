// http://codeforces.com/problemset/problem/24/A

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 10000000

struct node {
    vector<int> adj;
    vector<int> wt;
    vector<bool> rev;
} graph[200];


int* visited;

int find(int cur, int prev, bool val, int ans) {
    if (visited[cur] == 1) {
        return ans;
    }
    visited[cur] = 1;
    for (int i = 0; i < graph[cur].adj.size(); i++) {
        int v = graph[cur].adj[i];
        int wt = graph[cur].wt[i];
        bool reversed = graph[cur].rev[i];
        if (v != prev) {
            if (reversed == val)
                return find(v, cur, val, ans+wt);
            else
                return find(v, cur, val, ans);
        }
    }
}


int main(void) {
    int n;
    scanf("%d", &n);
    int e = n;
    int u, v, w;
    int total = 0;
    while (e--) {
        scanf("%d %d %d", &u, &v, &w);
        total += w;
        graph[u].adj.pb(v);
        graph[u].wt.pb(w);
        graph[u].rev.pb(false);
        graph[v].adj.pb(u);
        graph[v].wt.pb(w);
        graph[v].rev.pb(true);
    }
    visited = (int*) calloc(n+10, sizeof(int));
    int oneway = find(1, -1, true, 0);
    int other = total - oneway;
    printf("%d\n", min(oneway, other));
    return 0;
}



