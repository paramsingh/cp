#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
const int inf = 1e9;

int dp[110][500100];

inline int get(int x, int y) {
    return dp[x][y + 200100];
}

inline int set(int x, int y, int val) {
    dp[x][y + 200100] = val;
}

int n, k;
int a[110], b[110];

int solve(int id, int balance) {
    if (id == 0) return balance == 0 ? 0 : -inf; // base case

    if (get(id, balance) != -1) return get(id, balance); // see if it has been precalculated

    // take this element
    int ans = solve(id - 1, balance + a[id] - b[id]) + a[id];

    // don't take this element
    ans = max(ans, solve(id - 1, balance));

    set(id, balance, ans);
    return ans;
}

int main(void) {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    // this is the condition that must be followed:
    // sum(a[i]) - k * (sum(b[i])) = 0
    // so instead of storing b[i], we store b[i] * k
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        b[i] *= k;
    }
    // now dp is (id, balance)
    // dp[n][0] will the be the final answer
    printf("%d\n", solve(n, 0) == 0 ? -1 : solve(n, 0));

}
