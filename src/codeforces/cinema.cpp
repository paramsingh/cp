#include <bits/stdc++.h>
using namespace std;

map<int, int> know;
int movie[200200][2];
int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int lang;
        scanf("%d", &lang);
        if (know.count(lang) == 0)
            know[lang] = 1;
        else
            know[lang]++;
    }

    int m;
    scanf("%d", &m);
    int id = -1, vs = -1, as = -1;
    for (int i = 0; i < m; i++)
        scanf("%d", &movie[i][0]);
    for (int i = 0; i < m ;i++)
        scanf("%d", &movie[i][1]);
    for (int i = 0; i < m; i++) {
        int voice, sub;
        voice = movie[i][0], sub = movie[i][1];
        if (know.find(voice) != know.end()) {
            if (vs < know[voice]) {
                id = i;
                vs = know[voice];
                as = know[sub];
            }
            else if (vs == know[voice]) {
                if (know.find(sub) != know.end()) {
                    if (as < know[sub]) {
                        id = i;
                        as = know[sub];
                    }
                }
            }
        }
    }
    if (id == -1)
        printf("1\n");
    else
        printf("%d\n", id+1);
    return 0;
}
