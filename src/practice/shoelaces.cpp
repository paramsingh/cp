// http://codeforces.com/problemset/problem/129/B
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graph[200];
int order[200] = {0};
int main(void) {
    scanf("%d %d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        order[u]++;
        graph[v].push_back(u);
        order[v]++;
    }
    int size = n;
    int groups = 0;
    while (size > 0) {
        int rem = 0;
        int* freq = (int*) calloc(200, sizeof(int));
        for (int i = 1; i <= n; i++) {
            if (order[i] == 1) {
                rem++;
                order[i]--;
                for (int j = 0; j < graph[i].size(); j++) {
                    freq[graph[i][j]]++;
                }
            }
        }
        if (rem == 0)
            break;
        size = size - rem;
        groups++;
        for (int i = 1; i <= n; i++)
            order[i] -= freq[i];
        free(freq);
    }
    printf("%d\n", groups);
    return 0;
}
