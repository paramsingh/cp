#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int a[500100];
int n, k;

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    sort(a, a+n);
    lli steps = 0;
    int mn = a[0], mx = a[n-1];
    int nmn = 1, nmx = n - 2;
    lli cmn = 1, cmx = 1;
    while (steps < k) {
        lli mnd = (a[nmn] - mn) * cmn;
        lli mxd = (mx - a[nmd]) * cmx;
        if (mnd < mxd) {
            mn = a[nmn];
            nmn++;
            cmn++;


