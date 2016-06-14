#include <bits/stdc++.h>
using namespace std;

int graph[30][30] = {0};
int match[30];
int seen[30];

int n;
int bpm(int u) {
    for (int i = 0; i < n; i++) {
        if (graph[u][i] == 1 && seen[i] == 0) {
            seen[i] = 1;
            if (match[i] == -1 || bpm(match[i])) {
                match[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int matching() {
    memset(match, -1, sizeof(match));
    int m = 0;
    for (int i = 0; i < 26; i++) {
        memset(seen, 0, sizeof(seen));
        if (bpm(i))
            m += 1;
    }
    return m;
}


int main(void) {
    int t;
    int cnt = 1;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d:\n", cnt++);
        scanf("%d", &n);
        locale l;
        vector<string> words[n];
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < x; j++) {
                string a;
                cin >> a;
                string la;
                for (int k = 0; k < a.length(); k++)
                    la += tolower(a[k], l);
                char ch = la[0];
                words[i].push_back(la);
                graph[ch-'a'][i] = 1;
            }
        }
        matching();
        vector<string> w;
        for (int i = 0; i < n; i++) {
            char ch = match[i] + 'a';
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j][0] == ch) {
                    w.push_back(words[i][j]);
                    break;
                }
            }
        }
        sort(w.begin(), w.end());
        for (int i = 0; i < w.size(); i++) {
            cout << toupper(w[i][0], l);
            for (int j = 1; j < w[i].length(); j++) {
                cout << w[i][j];
            }
            cout << endl;
        }
        memset(graph, 0, sizeof(graph));
        memset(match, -1, sizeof(match));
        memset(seen, 0, sizeof(seen));
    }
    return 0;
}

