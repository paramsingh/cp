// http://codeforces.com/contest/29/problem/C

#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

class node {
	public:
		int val;
		int order;
		int visited;
		vector<int> adj;
};

map<int, int> id;
node* graph;

void dfs(int cur) {
	printf("%d ", graph[cur].val);
	graph[cur].visited = 1;
	for (int i = 0; i < graph[cur].adj.size(); i++) {
		int v = graph[cur].adj[i];
		if (graph[v].visited == 0)
			dfs(v);
	}
}
int main(void) {
	int n;
	scanf("%d", &n);
	graph = (node*) calloc(n+10, sizeof(node));
	int m = n;
	int i = 0;
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (id.count(u) == 0 && id.count(v)==0) {
			int uid = i, vid = i + 1;
			i += 2;
			id[u] = uid;
			id[v] = vid;
			graph[uid].val = u;
			graph[vid].val = v;
			graph[uid].order++;
			graph[vid].order++;
			graph[uid].adj.push_back(vid);
			graph[vid].adj.push_back(uid);
		}
		else if (id.count(u) == 0) {
			int uid = i;
			i++;
			id[u] = uid;
			int vid = id[v];
			graph[uid].val = u;
			graph[uid].order++;
			graph[vid].order++;
			graph[uid].adj.push_back(vid);
			graph[vid].adj.push_back(uid);
		}
		else if (id.count(v) == 0) {
			int vid = i;
			i++;
			id[v] = vid;
			int uid = id[u];
			graph[vid].val = v;
			graph[uid].order++;
			graph[vid].order++;
			graph[uid].adj.push_back(vid);
			graph[vid].adj.push_back(uid);
		}
		else {
			int vid = id[v], uid = id[u];
			graph[uid].order++;
			graph[vid].order++;
			graph[uid].adj.push_back(vid);
			graph[vid].adj.push_back(uid);
		}
	}
	for (int i = 0; i < n; i++) {
		if (graph[i].order == 1) {
			dfs(i);
			return 0;
		}
	}
}
