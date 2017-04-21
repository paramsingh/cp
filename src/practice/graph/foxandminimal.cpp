#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> graph[1010];
int mat[1010][1010];
int nxt; // variable to track the next node to add


int main(void) {
    int k;
    scanf("%d", &k);
    int src = 1, dest = 2;
    nxt = 3; // source and destination
    int power = 0;
    while (k > 0) {
        int dig = k % 10;
        k /= 10;
        if (dig == 0) {
            power++;
            continue;
        }
        else {
            int start = nxt;
            vector<int> prev;
            // add first level
            for (int i = 0; i < dig; i++) {
                graph[src].push_back(nxt++);
                graph[nxt - 1].push_back(src);
                prev.push_back(nxt - 1);
            }
            // add power of ten
            int cnt = 0;
            for (int i = 0; i < 10; i++, cnt++) {
                vector<int> v; // vector to track the nodes added in this level
                int nodes = cnt < power ? 10 : 1;
                for (int j = 0; j < nodes; j++) {
                    // add edges from previous level
                    for (int x: prev) {
                        graph[x].push_back(nxt);
                        graph[nxt].push_back(x);
                    }
                    v.push_back(nxt);
                    nxt++;
                }
                prev = v;
            }
            // add last level
            assert(prev.size() == 1);
            for (int x: prev) {
                graph[dest].push_back(x);
                graph[x].push_back(dest);
            }
        }
        power++;
    }
    int fin = nxt - 1;
    printf("%d\n", fin);
    for (int i = 1; i <= fin; i++) {
        for (int x: graph[i]) {
            mat[i][x] = 1;
        }
        for (int j = 1; j <= fin; j++)
            printf("%s", mat[i][j] ? "Y" : "N");
        printf("\n");
    }
    return 0;
}
