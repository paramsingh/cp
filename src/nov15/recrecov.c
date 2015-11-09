#include <stdio.h>
#include <stdlib.h>

int bpm(int u, int** graph, int* seen, int* match, int n) {
    int v;
    for (v = 0; v < n; v++) {
        if (graph[u][v] == 1) {
            if (seen[v] == 1)
                continue;
            seen[v] = 1;
            if (match[v] == -1 || bpm(match[v], graph, seen, match, n)) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int **graph = (int **) calloc(n, sizeof(int*));
        int *seen = (int *) calloc(n, sizeof(int));
        int *match = (int *) calloc(n, sizeof(int));
        int i, j;
        for (i = 0; i < n; i++) {
            graph[i] = (int *) calloc(n, sizeof(int));
            match[i] = -1;
        }

        while (m--) {
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x-1][y-1] = 1;
        }
        int cnt = 0;
        for (i = 0; i < n; i++) {
            seen = (int *) calloc(n, sizeof(int));
            if (bpm(i, graph, seen, match, n))
                cnt++;
        }
        if (n == cnt)
            printf("1\n");
        else
            printf("%d\n", n-cnt);
    }
    return 0;
}
