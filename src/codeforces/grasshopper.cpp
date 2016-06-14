#include <bits/stdc++.h>

int visited[100100];
char strip[100100];
int jump[100100];
int n;

int dfs(int u) {
    visited[u] = 1;
    int nxt;
    if (strip[u] == '<')
        nxt = u - jump[u];
    else
        nxt = u + jump[u];
    if (nxt < 0 || nxt >= n)
        return 1;
    else {
        if (visited[nxt] == 1)
            return 0;
        else
            return dfs(nxt);
    }
}

int main(void) {
    scanf("%d", &n);
    scanf("%s", strip);
    for (int i = 0; i < n; i++)
        scanf("%d", jump+i);
    int flag = dfs(0);
    if (flag == 0)
        printf("INFINITE\n");
    else
        printf("FINITE\n");
    return 0;
}
