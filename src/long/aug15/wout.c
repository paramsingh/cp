#include <stdio.h>
#include <stdlib.h>
/**
 * * Increment elements within range [i, j] with value value
 * */
void update_tree(int* tree, int* lazy, int node, int a, int b, int i, int j, int value) {
    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] += lazy[node]; // Update it
        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;
    if(a >= i && b <= j) { // Segment is fully within range
        tree[node] += value;
        if(a != b) { // Not leaf node
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return;
    }
    update_tree(tree, lazy, node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(tree, lazy, 1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}
/**
 * * Query tree to get max element value within range [i, j]
 * */
int query_tree(int* tree, int* lazy, int node, int a, int b, int i, int j) {
    if(a > b || a > j || b < i) return 0; // Out of range
    if(lazy[node] != 0) { // This node needs to be updated
        tree[node] += lazy[node]; // Update it
        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];
    int q1 = query_tree(tree, lazy, node*2, a, (a+b)/2, i, j); // Query left child
    int q2 = query_tree(tree, lazy, 1+node*2, 1+(a+b)/2, b, i, j); // Query right child
    int res = q1 + q2; 
    return res;
}
int main(void) {
    int t, li, hi;
    scanf("%d", &t);
    int a;
    for (a = 0; a < t; a++) {
        int g, h;
        scanf("%d %d", &g, &h);
        int i;
        int* tree = (int *) calloc(10000000, 8);
        int* lazy = (int *) calloc(10000000, 8);
        int* arr = (int *) calloc(g, 8);

        
        for (i = 0; i < g; i++) {
            scanf("%d%d", &li, &hi);
            update_tree(tree, lazy, 1, 0, g-1, li, hi, 1);
        }

        int min = g*h - query_tree(tree, lazy, 1, 0, g-1, 0, h-1);

        for (i = 1; i < g - h + 1; i++) {
            int y = g*h - query_tree(tree, lazy, 1, 0, g - 1, i, i + h - 1);
            if (y < min)
                min = y;
        }
        printf("%d\n", min);
        free(tree);
        free(lazy);
        free(arr);
    } }
