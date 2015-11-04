#include <stdio.h>
#include <stdlib.h>

struct node {
    int id;
    int next;
    int nxtval;
    int src;
    int x;
    int val;
};


int dfs(struct node* graph, int i, int expected, int src, int in) {
    if (graph[i].src == src && graph[i].x == in && graph[i].val != -1) {
        return graph[i].val != expected;
    }
    else {
        graph[i].src = src;
        graph[i].x = in;
        graph[i].val = expected;
        int nexp;
        if (expected == 0)
            nexp = 1 - graph[i].nxtval;
        else
            nexp = graph[i].nxtval;
        return dfs(graph, graph[i].next, nexp, src, in);
    }
}

int main(void) {
    int n;
    int x;
    char temp[10];
    scanf("%d", &n);
    while (n != 0) {
        struct node graph[n];
        int i;
        for (i = 0; i < n; i++) {
            scanf("%d %s", &x, temp);
            graph[i].next = x-1;
            if (temp[0] == 't')
                graph[i].nxtval = 1;
            else
                graph[i].nxtval = 0;
            graph[i].src = -1;
            graph[i].id = i;
            graph[i].x = -1;
            graph[i].val = -1;
        }
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (graph[i].src == -1) {
                if (dfs(graph, i, 0, i, 0) && dfs(graph, i, 1, i, 1)) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            printf("PARADOX\n");
        else
            printf("NOT PARADOX\n");
        scanf("%d", &n);
    }
}
