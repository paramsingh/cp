// dp(x, y) = number of additions required to make s[x:y] a palindrome
// dp(x, x) = 0
// dp(x, y) = dp(x+1, y-1) if s[x] = s[y]
// dp(x, y) = min(dp(x+1, y)+1, dp(x, y-1)+1) otherwise

#include <bits/stdc++.h>
using namespace std;

int dp[6500][6500];
char* s;

int ans(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];
    if (x == y)
        return dp[x][y] = 0;
    if (s[x] == s[y])
        return dp[x][y] = ans(x+1, y-1);
    int right = ans(x+1, y) + 1; // add the character at s[x] to the left of s[x:y]
    int left = ans(x, y-1) + 1;  // add the character at s[y] to the right of s[x:y]
    return dp[x][y] = min(right, left);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 6200; i++)
            for (int j = 0; j < 6200; j++)
                dp[i][j] = -1;
        s = (char*) calloc(6200, sizeof(char));
        scanf("%s", s);
        int l = strlen(s);
        printf("%d\n", ans(0, l-1));
    }
    return 0;
}
