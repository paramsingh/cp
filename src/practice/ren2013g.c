// Author: Param Singh <paramsingh258@gmail.com>
// The Escape: https://www.codechef.com/problems/REN2013G

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct point {
    int x, y;
};

int dist(int x, int y, int a, int b) {
    return ((x - a) * (x - a)) + ((y - b) * (y - b));
}

int main(void) {
    int n;
    scanf("%d", &n);
    int v = n+2;
    int graph[v][v];
    struct point p[v];
    int i, j;
    for (i = 1; i < v; i++)
        scanf("%d %d", &(p[i].x), &(p[i].y));
    for (j = 0; j < v; j++) {
        graph[0][j] = dist(0, 0, p[j].x, p[j].y);
        graph[j][0] = graph[0][j];
    }
    for (i = 1; i < v; i++) {
        for (j = 1; j < v; j++)
            graph[i][j] = dist(p[i].x, p[i].y, p[j].x, p[j].y);
    }
    int done[v];
    int priority[v];
    priority[0] = done[0] = 0;
    for (i = 1; i < v; i++) {
        done[i] = 0;
        priority[i] = INT_MAX;
    }
    int dup = v, count = 0;
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
            if (done[j] == 0 && priority[j] > priority[mini] + graph[mini][j])
                priority[j] = priority[mini] + graph[mini][j];
        }
    }
    printf("%d\n", priority[v-1]);
    return 0;
}
