#include <bits/stdc++.h>
using namespace std;

int c[200];
int freq[200][10];
int score[200];

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(freq, 0, sizeof(freq));
        memset(score, 0, sizeof(score));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
            for (int j = 0; j < c[i]; j++) {
                int type;
                scanf("%d", &type);
                freq[i][type]++;
            }
            score[i] = c[i];
            // find how many six distincts can be made
            int m = 1e8;
            for (int t = 1; t <= 6; t++)
                m = min(m, freq[i][t]);
            score[i] += 4 * m;
            for (int t = 1; t <= 6; t++)
                freq[i][t] -= m;

            // now find how many 5 distincts can be made
            m = 1e8;
            int flag = 1;
            for (int t = 1; t <= 6; t++)  {
                if (freq[i][t] == 0 && flag == 1) {
                    flag = 0;
                    continue;
                }
                m = min(m, freq[i][t]);
            }
            score[i] += 2 * m;
            for (int t = 1; t <= 6; t++)
                freq[i][t] = max(0, freq[i][t] - m);


            // now for four
            m = 1e8, flag = 2;
            for (int t = 1; t <= 6; t++) {
                if (freq[i][t] == 0 && flag > 0) {
                    flag--;
                    continue;
                }
                m = min(m, freq[i][t]);
            }
            score[i] += m;
        }
        int m = -1;
        for (int i = 0; i < n; i++)
            m = max(m, score[i]);
        int cnt = 0, winner;
        for (int i = 0; i < n; i++) {
            if (m == score[i]) {
                cnt++;
                winner = i;
            }
        }
        if (cnt > 1)
            printf("tie\n");
        else if (winner == 0)
            printf("chef\n");
        else
            printf("%d\n", winner + 1);
    }
    return 0;
}
