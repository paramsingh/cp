#include <bits/stdc++.h>
using namespace std;

int a[100100];

int main(void) {
    int n;
    scanf("%d", &n);
    long long int m = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        if (m  < a[i])
            m = a[i];
    }
    long long int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != m)
            s += a[i];
    }
    cout << m - s + 1 << endl;
    return 0;
}

