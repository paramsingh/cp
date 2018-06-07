#include <bits/stdc++.h>
using namespace std;

int done[1010];

int main(void) {
    int n;
    scanf("%d", &n);
    vector<int> p;
    for (int i = 1; i <= n / 2; i++) {
        int x;
        scanf("%d", &x);
        p.push_back(x);
    }
    sort(p.begin(), p.end());
    int even_ans = 0;
    int odd_ans = 0;
    for (int i = 0; i < n / 2; i++) {
        int x = p[i];
        even_ans += abs(p[i] - (2*i + 2));
        odd_ans += abs(p[i] - (2*i + 1));
    }
    printf("%d\n", min(odd_ans, even_ans));
    return 0;
}

