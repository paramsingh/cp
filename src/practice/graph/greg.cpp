#include <bits/stdc++.h>
using namespace std;

int done[600];
int adj[600][600];
int main(void) {
    memset(done, 0, sizeof(done));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    }
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        order.push_back(x);
    }
    reverse(order.begin(), order.end());
    vector<long long> ans;
    for (int i = 0; i < order.size(); i++) {
        int via = order[i];
        done[via] = 1;
        long long x = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][j] > adj[i][via] + adj[via][j])
                    adj[i][j] = adj[i][via] + adj[via][j];
                if (done[i] && done[j])
                    x += adj[i][j];
            }
        }
        ans.push_back(x);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        printf("%I64d ", ans[i]);
    printf("\n");
    return 0;
}
