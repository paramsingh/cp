// https://www.codechef.com/problems/DIGJUMP

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10];
queue<int> q;
int dist[100006];
bool visited[100006];
int main(void) {
    string s;
    cin >> s;
    int l = s.size();
    for (int i = 1; i < l; i++)
        graph[s[i] - '0'].push_back(i);
    for (int i = 0; i < l; i++) {
        dist[i] = 0;
        visited[i] = false;
    }
    dist[0] = 0;
    visited[0] = true;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        if (u == l-1)
            break;
        q.pop();
        int val = s[u] - '0';
        for (int i = 0; i < graph[val].size(); i++) {
            int v = graph[val][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
        graph[val].clear();
        if (u + 1 < l && !visited[u+1]) {
            visited[u+1] = true;
            q.push(u+1);
            dist[u+1] = dist[u] + 1;
        }
        if (u - 1 >= 0 && !visited[u-1]) {
            visited[u-1] = true;
            q.push(u-1);
            dist[u-1] = dist[u] + 1;
        }
    }
    printf("%d\n", dist[l-1]);
    return 0;
}
