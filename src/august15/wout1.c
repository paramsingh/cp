#include <stdio.h>
#include <stdlib.h>

void update_tree(int* tree, int* lazy, int node, int a, int b, int i, int j)
{
    if(lazy[node] != 0) {
        tree[node] += lazy[node] * (b-a+1);
        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(a > b || a > j || b < i)
        return;
    if(a >= i && b <= j) {
        tree[node] += (b-a+1);
        if(a != b) {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
    update_tree(tree, lazy, node*2, a, (a+b)/2, i, j);
    update_tree(tree, lazy, 1+node*2, 1+(a+b)/2, b, i, j);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long int query_tree(int* tree, int* lazy, int node, int a, int b, int i, int j) {
    if(a > b || a > j || b < i) return 0;
    if(lazy[node] != 0) {
        tree[node] += lazy[node] * (b-a+1);
        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(a >= i && b <= j)
        return tree[node];
    long long int q1 = query_tree(tree, lazy, node*2, a, (a+b)/2, i, j);
    long long int q2 = query_tree(tree, lazy, 1+node*2, 1+(a+b)/2, b, i, j);
    return q1 + q2;
}

int main(void) {
    int t, li, hi;
    unsigned long long int g, h, y, min;
    scanf("%d", &t);
    int a;
    for (a = 0; a < t; a++) {
        scanf("%llu %llu", &g, &h);
        int i;
        int* tree = (int *) calloc(2097152, sizeof(int));
        int* lazy = (int *) calloc(2097152, sizeof(int));
        for (i = 0; i < g; i++) {
            scanf("%d%d", &li, &hi);
            update_tree(tree, lazy, 1, 0, g-1, li, hi);
        }
        min = g*h - query_tree(tree, lazy, 1, 0, g-1, 0, h-1);
        for (i = 1; i < g - h + 1; i++) {
            y = g*h - query_tree(tree, lazy, 1, 0, g - 1, i, i + h - 1);
            if (y < min)
                min = y;
        }
        printf("%llu\n", min);
        free(tree);
        free(lazy);
    }
}
