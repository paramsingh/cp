#include <bits/stdc++.h>
using namespace std;

struct intersection {
    int x, y;
};

int dist(intersection a, intersection b) {
    return (abs(a.x - b.x) + abs(a.y - b.y)) * 200;
}

intersection* people;
intersection* taxies;
int graph[500][500] = {0};
int p, cabs, speed, tim;
int match[500];
int seen[500];

int bpm(int u) {
    for (int i = 0; i < p; i++) {
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
    int result = 0;
    for (int i = 0; i < cabs; i++) {
        memset(seen, 0, sizeof(seen));
        if (bpm(i))
            result++;
    }
    return result;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &p, &cabs, &speed, &tim);
        people = (intersection*) calloc(p+1, sizeof(intersection));
        taxies = (intersection*) calloc(cabs+1, sizeof(intersection));
        int cnt = 1;
        for (int i = 0; i < p; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            people[i].x = x;
            people[i].y = y;
        }
        for (int i = 0; i < cabs; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            taxies[i].x = x;
            taxies[i].y = y;
        }
        for (int i = 0; i < cabs; i++) {
            for (int j = 0; j < p; j++) {
                if (dist(taxies[i], people[j]) / speed <= tim) {
                    graph[i][j] = 1;
                }
            }
        }
        printf("%d\n", matching());
        for (int i = 0; i < 500; i++)
            for (int j = 0; j < 500; j++)
                graph[i][j] = 0;
        free(people);
        free(taxies);
    }
    return 0;
}

