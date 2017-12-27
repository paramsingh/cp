#include <bits/stdc++.h>
using namespace std;

int n;

int a[200100];

vector<int> subs[200100];

int find(int x) {
    // find the subsequence in which x should go
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int size = subs[mid].size();
        // if this subarray is empty or if it's last element is 
        // smaller than x, then answer is either mid or less than mid
        if (size == 0 || subs[mid][size - 1] < x)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}


int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int x = find(a[i]);
        subs[x].push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!subs[i].size()) break;
        for (int j = 0; j < subs[i].size(); j++)
            printf("%d ", subs[i][j]);
        printf("\n");
    }
    return 0;
}

