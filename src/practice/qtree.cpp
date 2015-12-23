// http://www.spoj.com/problems/QTREE
// Heavy light decomposition

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#define DEPTH 14
#define SIZE 10010
#define max(a, b) a>b?a:b
using namespace std;

int n;

// struct for a node in the tree
struct node {
    vector<int> adj; // Adjacency list
    vector<int> wt;  // Weights for each edge in the adjacency list
    vector<int> id;  // ids for each edge
    int cid;         // chain to which node belongs
    int pos;         // position of node in the base array
    int subsize;     // size of subtree under the current node
    int depth;       // depth of the node in the tree
} tree[SIZE];

int base[SIZE];           // base array used for construction of segment tree
int end[SIZE];            // array to store the end of edge used to represent
                     // the edge in the base array

int head[SIZE];      // used to store the head of each chain

int pa[DEPTH][SIZE];  // pa[i][j] = (2^i)th ancestor of j

// dfs sets up the subsize, depth and base cases (1 height) of the pa array
void dfs(int cur, int prev, int depth) {
    tree[cur].subsize = 1;   // include the current node in the subsize
    tree[cur].depth = depth; // depth of node is the current depth
    pa[0][cur] = prev;       // ancestor at height 0 is the node with which we came here
    int i;
    for (i = 0; i < tree[cur].adj.size(); i++) {
        if (tree[cur].adj[i] != prev) {
            end[tree[cur].id[i]] = tree[cur].adj[i];
            dfs(tree[cur].adj[i], cur, depth+1); // dfs
            tree[cur].subsize += tree[tree[cur].adj[i]].subsize; // add subsize of child
        }
    }
}

int cno = 0;          // variable to keep track of number of chains
int bs  = 0;          // variable to keep track of positions in base array

// recursive hld function
// sets up cid and pos for each node and sets up the base array
void hld(int cur, int prev, int wt) {
    // if the head of the current chain is not set, set it to current node
    if (head[cno] == -1)
        head[cno] = cur;
    tree[cur].cid = cno; // set the chain id of current node
    tree[cur].pos = bs;  // set the position of current node in base array
    base[bs++] = wt;     // add value to base array

    // finding the special child of the node in order to continue the current
    // chain
    int spid = -1, swt, maxsubsize = INT_MIN;
    int i;
    for (i = 0; i < tree[cur].adj.size(); i++) {
        if ((tree[cur].adj[i] != prev) && (maxsubsize < tree[tree[cur].adj[i]].subsize)) {
            spid = tree[cur].adj[i];
            swt  = tree[cur].wt[i];
            maxsubsize = tree[tree[cur].adj[i]].subsize;
        }
    }

    // if a special child was found i.e if cur is not a leaf, continue current chain
    if (spid != -1) {
        hld(spid, cur, swt);
    }

    // for each non special child, start a new chain
    for (i = 0; i < tree[cur].adj.size(); i++) {
        if (spid != tree[cur].adj[i] && tree[cur].adj[i] != prev) {
            cno++; // ensures that this node begins a new chain
            hld(tree[cur].adj[i], cur, tree[cur].wt[i]);
        }
    }
}

int segtree[6*SIZE]; // segment tree on base array for maximum in a range

// segment tree operations
void build(int i, int l, int r) {
    if (l == r) {
        segtree[i] = base[l];
    }
    else {
        int mid = (l + r) / 2;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
        segtree[i] = max(segtree[2*i], segtree[2*i+1]);
    }
}

void update(int i, int l, int r, int id, int val) {
    if (l == r && id == l) {
        segtree[i] = val;
    }
    else {
        int mid = (l + r) / 2;
        if (id <= mid)
            update(2*i, l, mid, id, val);
        else
            update(2*i+1, mid+1, r, id, val);
        segtree[i] = max(segtree[2*i], segtree[2*i+1]);
    }
}

int query(int l, int r, int i, int cl, int cr) {
    if (cl > r || cr < l)
        return INT_MIN;
    else if (cl >= l && cr <= r)
        return segtree[i];
    else {
        int mid = (cl + cr) / 2;
        int a = query(l, r, 2*i, cl, mid);
        int b = query(l, r, 2*i+1, mid+1, cr);
        return max(a, b);
    }
}

// function to setup parent array
inline void setup_parents() {
    int i, j;
    // row zero has been set by dfs
    // therefore we know the immediate parents
    for (i = 1; i < DEPTH; i++) {
        for (j = 1; j <= n; j++) {
            if (pa[i-1][j] != -1) {
                pa[i][j] = pa[i-1][pa[i-1][j]];
            }
        }
    }
}

// returns the LCA of u and v in O(log n)
int lca(int u, int v) {
    if (tree[u].depth < tree[v].depth) {
        int temp = u;
        u = v;
        v = temp;
    }
    int i, log = 0;
    for (i = 13; i >= 0; i--) {
        if (tree[u].depth - (1 << i) >= tree[v].depth) {
            u = pa[i][u];
        }
    }
    if (u == v)
        return v;
    for (i = 13; i >= 0; i--) {
        if (pa[i][u] != -1 && pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

int query_up(int u, int v) {
    // guaranteed that v is an ancestor of u
    if (u == v)
        return 0;
    int uchain = tree[u].cid, vchain = tree[v].cid;
    int ans = -1;

    while (true) {
        uchain = tree[u].cid;
        if (uchain == vchain) {
            int x = tree[u].pos;
            int y = tree[v].pos;
            int a = query(y+1, x, 1, 0, bs-1);
            if (ans < a)
                ans = a;
            break;
        }
        else {
            int h = head[uchain];
            int a = query(tree[h].pos, tree[u].pos, 1, 0, bs-1);
            if (ans < a)
                ans = a;
            u = pa[0][h];
        }
    }
    return ans;
}

int query1(int u, int v) {
    int ancestor = lca(u, v);
    return max(query_up(u, ancestor), query_up(v, ancestor));
}

void update1(int i, int val) {
    int x = end[i];
    update(1, 0, bs-1, tree[x].pos, val);
}

int main(void) {
    int t, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i <= n; i++) {
            tree[i].adj.clear();
            tree[i].wt.clear();
            tree[i].id.clear();
            head[i] = -1;
            for (j = 0; j < DEPTH; j++)
                pa[j][i] = -1;
        }
        for (i = 1; i < n; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            tree[a].adj.push_back(b);
            tree[a].wt.push_back(c);
            tree[a].id.push_back(i);
            tree[b].adj.push_back(a);
            tree[b].wt.push_back(c);
            tree[b].id.push_back(i);
        }
        bs = 0;
        cno = 0;
        dfs(1, -1, 0);
        hld(1, -1, 0);
        build(1, 0, bs-1);
        setup_parents();
        char choice[100];
        int u, v;
        while (true) {
            scanf("%s", choice);
            if (choice[0] == 'D')
                break;
            else if (choice[0] == 'Q') {
                scanf("%d %d", &u, &v);
                int ans = query1(u, v);
                printf("%d\n", ans);
            }
            else {
                scanf("%d %d", &u, &v);
                update1(u, v);
            }
        }
    }
    return 0;
}
