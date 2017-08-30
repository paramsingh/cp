#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[212345];
set<vector<int> > mem;
int a[212345];
int ans[212345];

int gcd(int u, int v) {
		if (u == 0)
				return v;
		if (v == 0)
				return u;
		while (u > 0) {
				int tmp = v % u;
				v = u;
				u = tmp;
		}
		return v;
}

void dfs(int u, int p, int skip, int hcf) {
		vector<int> key = {u, p, skip, hcf};
		if (skip)
				ans[u] = max(ans[u], hcf);
		int nhcf = gcd(hcf, a[u]);
		ans[u] = max(ans[u], nhcf);
		if (mem.count(key)) return;
		mem.insert(key);
		for (int i = 0; i < graph[u].size(); i++) {
				int v = graph[u][i];
				if (v != p) {
						if (skip)
								dfs(v, u, 0, hcf);
						dfs(v, u, skip, nhcf);
				}
		}
}


int main(void) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
				scanf("%d", &a[i]);
				ans[i] = -1;
		}
		for (int i = 1; i < n; i++) {
				int u, v;
				scanf("%d %d", &u, &v);
				graph[u].push_back(v);
				graph[v].push_back(u);
		}

		dfs(1, -1, 1, 0);
		for (int i = 1; i <= n; i++) 
				printf("%d ", ans[i]);
		printf("\n");
}


