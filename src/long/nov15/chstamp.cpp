#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Edge {
    public:
        int day;
        int dest;
        int max;
        Edge(int d, int des) {
            day = d;
            dest = des;
            max = 0;
        }
};

class Node {
    public:
        vector<Edge> adj;
        int max;
        int deg;
        Node() {
            deg = 0;
            max = 0;
        }
};

class Offer {
    public:
        int day, x, y;
};

int cmp(const void* a, const void* b) {
    Offer* o1 = (Offer *) a;
    Offer* o2 = (Offer *) b;
    if (o1->day != o2->day) {
        return o1->day - o2->day;
    }
    else {
        if (o1->x != o2->x)
            return o1->x - o2->x;
        else
            return o1->y - o2->y;
    }
}

Node* graph;
bool* visited;

void dfs(int i, int prop, int day) {
    if (!visited[i]) {
        visited[i] = true;
        graph[i].max = prop;
    }
    int j;
    for (j = 0; j < graph[i].adj.size(); j++) {
        if (graph[i].adj[j].day > day)
            break;
        else {
            if (graph[i].adj[j].max < prop) {
                graph[i].adj[j].max = prop;
                dfs(graph[i].adj[j].dest, prop, graph[i].adj[j].day);
            }
        }
    }
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        graph = (Node*) calloc(50002, sizeof(Node));
        visited = (bool*) calloc(50002, sizeof(bool));
        int stamps[n];
        int i;
        for (i = 0; i < n; i++)
            scanf("%d", stamps+i);
        Offer o[m];
        int max = -1;
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &o[i].day, &o[i].x, &o[i].y);
            if (max < o[i].x)
                max = o[i].x;
            if (max < o[i].y)
                max = o[i].y;
        }
        qsort(o, m, sizeof(Offer), cmp);
        for (i = 0; i < m ; i++) {
            graph[o[i].x].adj.push_back(Edge(o[i].day, o[i].y));
            graph[o[i].x].deg++;
            graph[o[i].y].adj.push_back(Edge(o[i].day, o[i].x));
            graph[o[i].y].deg++;
        }
        for (i = max; i >= 0; i--) {
            if (graph[i].deg != 0)
                dfs(i, i, 50005);
        }
        long long int sum = 0;
        for (i = 0; i < n; i++) {
            if (graph[stamps[i]].deg != 0)
                sum += graph[stamps[i]].max;
            else
                sum += stamps[i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
