// http://www.spoj.com/problems/SALMAN

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#define min(a, b) a<b?a:b
using namespace std;

class node {
    public: long long int sal;
            vector<int> adj;
};

node* arr;
int id;
int* beg;
int* end;
int* seg;

void create_array(int node) {
    beg[node] = id;
    seg[id++] = arr[node].sal;
    for (int i = 0; i < arr[node].adj.size(); i++) {
        create_array(arr[node].adj[i]);
    }
    end[node] = id - 1;
}

class segnode {
    public:
        long long int sum;
        long long int m;
        long long int lazy;
};

segnode* tree;

void merge(segnode* a, segnode* left, segnode* right) {
    a->sum = left->sum + right->sum;
    a->m = min(left->m, right->m);
}

void build(int i, int l, int r) {
    tree[i].lazy = 0;
    if (l == r) {
        tree[i].sum = tree[i].m = seg[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        merge(tree+i, tree+2*i, tree+2*i+1);
    }
}

void propagate(int i, int l, int r) {
    if (tree[i].lazy != 0) {
        tree[i].sum += tree[i].lazy * (long long)(r - l + 1);
        tree[i].m += tree[i].lazy;
        if (l != r) {
            int mid = (l + r) / 2;
            tree[2*i].lazy += tree[i].lazy;
            tree[2*i+1].lazy += tree[i].lazy;
        }
        tree[i].lazy = 0;
    }
}

segnode* query(int l, int r, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return NULL;
    else if (cl >= l && cr <= r)
        return tree+i;
    else {
        int mid = (cl + cr) / 2;
        segnode* a = query(l, r, 2*i, cl, mid);
        segnode* b = query(l, r, 2*i+1, mid+1, cr);
        if (a != NULL && b != NULL) {
            segnode* result = (segnode*) calloc(1, sizeof(segnode));
            merge(result, a, b);
            return result;
        }
        else if (a != NULL)
            return a;
        else if (b != NULL)
            return b;
    }
}

segnode* update(int l, int r, int val, int i, int cl, int cr) {
    propagate(i, cl, cr);
    if (cl > r || cr < l)
        return tree+i;
    else if (cl >= l && cr <= r) {
        tree[i].sum += (long long)(val) * (cr - cl + 1);
        tree[i].m += val;
        if (cl != cr) {
            int mid = (cl + cr) / 2;
            tree[2*i].lazy += val;
            tree[2*i+1].lazy += val;
        }
        return tree+i;
    }
    else {
        int mid = (cl + cr) / 2;
        segnode* a = update(l, r, val, 2*i, cl,  mid);
        segnode* b = update(l, r, val, 2*i+1, mid+1, cr);
        merge(tree+i, a, b);
        return tree+i;
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int c = 1; c <= t; c++) {
        printf("Case %d:\n", c);
        int n, q;
        scanf("%d %d", &n, &q);
        arr = (node *) calloc(n+3, sizeof(node));
        beg = (int *)  calloc(n+3, sizeof(int));
        end = (int *)  calloc(n+3, sizeof(int));
        seg = (int *)  calloc(n+3, sizeof(int));
        tree = (segnode*) calloc(400005, sizeof(segnode));
        id = 0;
        for (int i = 1; i <= n; i++) {
            int parent;
            scanf("%d %lld", &parent, &arr[i].sal);
            arr[parent].adj.push_back(i);
        }
        create_array(1);
        assert(id==n);
        build(1, 0, n-1);
        for (int i = 0; i < q; i++) {
            int type, j;
            scanf("%d %d", &type, &j);
            int x = beg[j];
            int y = end[j];
            if (type == 1)
                printf("%lld\n", query(x, y, 1, 0, n-1)->sum);
            else {
                long long int m = query(x, y, 1, 0, n-1)->m;
                int val = min(m, 1000);
                update(x, y, val, 1, 0, n-1);
            }
        }
    }
    return 0;
}

