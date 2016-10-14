#include <bits/stdc++.h>
using namespace std;

char s[100100];

int main(void) {
    int n, p;
    scanf("%d %d", &n, &p);
    p--;
    scanf("%s", s);
    int ans = 0;
    // adding up and downs
    for (int i = 0; i < n / 2; i++)
        ans += min(abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
    // now need to add left and right;
    int start, end;
    int first = n + 1, last = -1;
    if (p < n / 2)
        start = 0, end = n / 2 - 1;
    else
        start = n / 2, end = n - 1;
    for (int i = start; i <= p; i++) {
        if (s[i] != s[n - i - 1])
            first = min(first, i);
    }
    for (int i = p; i <= end; i++) {
        if (s[i] != s[n - i - 1])
            last = max(last, i);
    }
    int lr;
    if (first == n + 1 && last == -1)
        lr = 0;
    else if (first == n + 1)
        lr = abs(last - p);
    else if (last == -1)
        lr = abs(first - p);
    else
        lr = min(abs(p  - first) + abs(last - first), abs(p - last) + abs(last - first));
    ans += lr;
    printf("%d\n", ans);
}
