#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

vector<tuple<int, int, int> > edges;
vector<pair<int, int> > graph[100100];
ll compressed_graph[510][510];
ll dist[510][510];

int done[100100]; // array to check if node has been visited or not
int cmp = 0;      // variable to store component number
int cnt[100100];
int c[100100];
int type[100100];
int component[101000];

void dfs(int u) {
    done[u] = 1;
    component[u] = cmp;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first, w = graph[u][i].second;
        if (done[v] == 0 && w == 0) { // w == 0 because right now we're only going through 0 cost edges
            dfs(v);
        }
    }
}

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int last = 1;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        for (int x = 1; x <= c[i]; x++)
            type[last++] = i;
    }

    // create the graph and store the edges in another
    // list for later processing during compression of the
    // graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back(make_tuple(u, v, w));
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    // dfs to assign each node in the entire graph a connected
    // component number
    for (int i = 1; i <= n; i++)  {
        if (done[i] == 0) {
            cmp++;
            dfs(i);
        }
    }

    // alright, have assigned numbers to each node, now to check if
    // each TYPE has only one component or not
    // if any type doesn't, our answer is NO
    for (int i = 2; i <= n; i++) {
        if (type[i] == type[i - 1] && component[i] != component[i - 1]) {
            printf("No\n");
            return 0;
        }
    }

    // If we get here, then each node has a path with distance 0 to
    // all other nodes of its own type, so we compress the graph
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++)
            compressed_graph[i][j] = inf;
        compressed_graph[i][i] = 0;
    }

    for (int i = 0; i < edges.size(); i++) {
        int u = get<0>(edges[i]), v = get<1>(edges[i]), w = get<2>(edges[i]);
        int tu = type[u], tv = type[v];
        // add edge if no edge present or if costlier edge present
        if (compressed_graph[tu][tv] > w)
            compressed_graph[tu][tv] = w;
        if (compressed_graph[tv][tu] > w)
            compressed_graph[tv][tu] = w;
    }


    // now run floyd warshall on compressed graph
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            dist[i][j] = compressed_graph[i][j];
        }
    }

    for (int via = 1; via <= k; via++) {
        for (int from = 1; from <= k; from++) {
            for (int to = 1; to <= k; to++) {
                if (dist[from][to] > dist[from][via] + dist[via][to])
                    dist[from][to] = dist[from][via] + dist[via][to];
            }
        }
    }

    printf("Yes\n");
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            printf("%lld ", dist[i][j] == inf ? -1 : dist[i][j]);
        }
        printf("\n");
    }
}
