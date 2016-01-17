/** http://acm.timus.ru/problem.aspx?space=1&num=1280 */
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1010

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> graph[n+10];
    int* order = (int*) calloc(n+10, sizeof(int));
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        order[v]++;
    }
    int flag = 0;
    int cur;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        if (order[cur] > 0) {
            flag = 1;
            break;
        }
        else {
            for (int j = 0; j < graph[cur].size(); j++) {
                order[graph[cur][j]]--;
            }
        }
    }
    if (flag == 1)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}

