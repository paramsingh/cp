#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;
int main(void) {
    scanf("%d", &n);
    int v = n*n;
    int **graph = (int **) calloc(v, sizeof(int*));
    int a[n][n];
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < v; i++)
        graph[i] = (int *) calloc(v, sizeof(int));
    int count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0) {
                if (j != n-1)
                    graph[count][count+1] = a[i][j+1];
                if (j != 0)
                    graph[count][count-1] = a[i][j-1];
                graph[count][count+n] = a[i+1][j];
            }
            else if (i == n-1) {
                if (j != n-1)
                    graph[count][count+1] = a[i][j+1];
                if (j != 0)
                    graph[count][count-1] = a[i][j-1];
                graph[count][count-n] = a[i-1][j];
            }
            else {
                if (j != n-1)
                    graph[count][count+1] = a[i][j+1];
                if (j != 0)
                    graph[count][count-1] = a[i][j-1];
                graph[count][count+n] = a[i+1][j];
                graph[count][count-n] = a[i-1][j];
            }
            count++;
        }
    }
    int done[v];
    int priority[v];
    int parent[v];
    priority[0] = done[0] = parent[0] = 0;
    for (i = 1; i < v; i++) {
        done[i] = 0;
        priority[i] = INT_MAX;
    }
    int dup = v;
    count = 0;
    while (count != v) {
        int min = INT_MAX, mini = -1;
        for (j = 0; j < v; j++) {
            if (done[j] == 0 && min > priority[j]) {
                min = priority[j];
                mini = j;
            }
        }
        done[mini] = 1;
        count++;
        for (j = 0; j < v; j++) {
            if (done[j] == 0 && graph[mini][j] != 0 && priority[j] > priority[mini] + graph[mini][j])
                priority[j] = priority[mini] + graph[mini][j];
                parent[j] = mini;
        }
    }
    printf("%d\n", priority[v-1] + a[0][0]);
    return 0;
}
