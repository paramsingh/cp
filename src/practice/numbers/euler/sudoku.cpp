#include <bits/stdc++.h>
using namespace std;

int puzzle[10][10];
int cnt = 0;
int fin = 0;
int final_depth;

void print_puzzle() {
    printf("Currently the puzzle is as follows\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", puzzle[i][j]);
        printf("\n");
    }
    printf("nodes expanded = %d\n", cnt);
    fin += cnt;
}

void generate_moves(int i, int j, vector<int>& possible) {
    int cant[10];
    memset(cant, 0, sizeof(cant));
    // same row
    for (int x = 0; x < 9; x++) {
        if (puzzle[i][x] != 0) {
            int val = puzzle[i][x];
            // val can't be used now
            cant[val] = 1;
        }
    }
    // same column
    for (int x = 0; x < 9; x++) {
        if (puzzle[x][j] != 0) {
            int val = puzzle[x][j];
            cant[val] = 1;
        }
    }
    // 3 by 3 box
    // find which box the co-ordinate is in
    int bi = i / 3, bj = j / 3;
    int ci = 0;
    for (int x = bi * 3; ci < 3; ci++, x++) {
        int cj = 0;
        for (int y = bj * 3; cj < 3; cj++, y++) {
            if (puzzle[x][y] != 0) {
                int val = puzzle[x][y];
                cant[val] = 1;
            }
        }
    }
    for (int x = 1; x <= 9; x++) {
        if (cant[x] == 0)
            possible.push_back(x);
    }
}

int solve(int depth) {
    cnt++;
    // generate possible moves
    int mn = 10, mi, mj;
    int solved = 1;
    vector<int> possible[10][10];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (puzzle[i][j] == 0) {
                solved = 0;
                generate_moves(i, j, possible[i][j]);
                if (possible[i][j].size() < mn) {
                    mn = possible[i][j].size();
                    mi = i, mj = j;
                }
            }
        }
    }
    if (solved) {
        final_depth = depth;
        return 1;
    }

    for (int i = 0; i < possible[mi][mj].size(); i++) {
        // put possible value in the puzzle and then solve further
        puzzle[mi][mj] = possible[mi][mj][i];
        int done = solve(depth + 1);
        if (done == 1)  return 1;
        puzzle[mi][mj] = 0;
    }
    return 0;
}

int main(void) {
    int t = 50;
    char c = 0;
    int ans = 0;
    while (t--) {
        // input
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                while (c < '0' || c > '9')
                    c = getchar_unlocked();
                puzzle[i][j] = c - '0';
                c = getchar_unlocked();
            }
        }
        print_puzzle();
        solve(1);
        print_puzzle();
        printf("solved at depth = %d\n", final_depth);
        cnt = 0;
        int n = 0;
        for (int j = 0; j < 3; j++)
            n = n * 10 + puzzle[0][j];
        ans += n;
    }
    printf("final answer = %d\n", ans);
    printf("total number of nodes expanded = %d\n", fin);
    printf("average number of nodes expanded for one puzzle = %0.2f\n", fin / 50.0);
    return 0;
}

