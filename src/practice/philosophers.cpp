/** https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4206 */
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;
        vector<int> graph[n+10];
        int* order = (int*) calloc(n + 10, sizeof(int));
        int u, v;
        while (m--) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            order[v]++;
        }
        int ans = 1;
        int count = 0;
        int size = n;
        int *freq;
        while (size > 0) {
            freq = (int*) calloc(n+10, sizeof(int));
            count = 0;
            for (int i = 1; i <= n; i++) {
                if (order[i] == 0) {
                    order[i] = -1;
                    count++;
                    size--;
                    for (int j = 0; j < graph[i].size(); j++)
                        freq[graph[i][j]]++;
                }
            }
            if (count == 0) {
                ans = 0;
                break;
            }
            else if (count > 1) {
                ans = 2;
            }
            for (int i = 1; i <= n; i++)
                order[i] -= freq[i];
            free(freq);
        }
        printf("%d\n", ans);
    }
    return 0;
}
