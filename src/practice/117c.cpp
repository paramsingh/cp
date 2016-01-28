// http://codeforces.com/problemset/problem/117/C

#include <bits/stdc++.h>
#define MAX 5010
using namespace std;

int adj[MAX][MAX];
int visited[MAX] = {0};
int n;

int dfs(int cur, int prev) {
    visited[cur] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[cur][i] == 1) {
            if (adj[i][prev] == 1) {
                printf("%d %d %d\n", prev+1, cur+1, i+1);
                return 1;
            }
            if (visited[i] == 0)
                if (dfs(i, cur) == 1)
                    return 1;
        }
    }
    return 0;
}

int main(void) {
    scanf("%d", &n);
    int m = n;
    int i, j;
    for (i = 0; i < n; i++) {
        getchar();
        for (j = 0; j < n; j++) {
            int c = getchar();
            adj[i][j] = c - '0';
        }
    }
    int flag = 0;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, i) == 1) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
        printf("-1\n");
    return 0;
}

