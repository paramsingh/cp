// dp(x) = number of strings that can be made starting from s[x:]
// dp(x) = 1 if x == len - 1
// dp(x) = dp(x+1) + ( dp(x+2) if s[x:x+1] <= 26 )

#include <bits/stdc++.h>

long long int dp[5010];
int len;
char* s;
long long int ans(int x) {
    if (dp[x] != -1)
        return dp[x];
    if (x == len-1 && s[x] != '0')
        return dp[x] = 1;
    else if (x == len - 1 && s[x] == '0')
        return dp[x] = 0;
    if (x >= len)
        return dp[x] = 1;
    else {
        long long int f = 0;
        f += ans(x+1);
        if (x <= len-2 && (s[x] == '1' || (s[x] == '2' && '0' <= s[x+1] && s[x+1] <= '6')))
            f += ans(x+2);
        if (s[x] == '0')
            return dp[x] = 0;
        return dp[x] = f;
    }
}

int main(void) {
    while (true) {
        s = (char *) calloc(5010, sizeof(char));
        scanf("%s", s);
        len = strlen(s);
        if (s[0] == '0' && len == 1)
            break;
        for (int i = 0; i < 5010; i++)
            dp[i] = -1;
        printf("%lld\n", ans(0));
        free(s);
    }
    return 0;
}
