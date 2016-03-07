// Check if you can keep converting a currency until you get more money than you began
// with.
// Shortest path from every currency will find the maximum amount of that currency that
// we can get from something else. (dist[src][dest] * rate(dest, src))
// if any of these comes out to be greater than 1, answer is yes
// otherwise no

#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int, double> pid;
typedef pair<int, int> pii;

map<string, int> curs;
int n;

double** dist;

int main(void) {
    int cnt = 1;
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++) {
            string cur;
            cin >> cur;
            curs[cur] = i;
        }
        dist = (double **) calloc(n+10, sizeof(double*));
        for (int i = 1; i <= n; i++) {
            dist[i] = (double*) calloc(n+10, sizeof(double));
        }

        int e;
        scanf("%d", &e);
        while (e--) {
            string src, dest;
            double rate;
            cin >> src >> rate >> dest;
            dist[curs[src]][curs[dest]] = rate;
        }

        for (int k = 1; k <= n; k++) {
            for (int u = 1; u <= n; u++) {
                for (int v = 1; v <= n; v++) {
                    if (dist[u][v] < dist[u][k] * dist[k][v])
                        dist[u][v] = dist[u][k] * dist[k][v];
                }
            }
        }

        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i][i] > 1)
                flag = 1;
        }
        printf("Case %d: ", cnt++);
        if (flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
        for (int i = 1; i <= n; i++) {
            free(dist[i]);
        }
        curs.clear();
        free(dist);
    }
    return 0;
}
