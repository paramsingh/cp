#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int a[100100];
double logs[100100];
int pr[100100];

int getdigit(double x) {
    double frac = x - (int) x;
    return floor(pow(10, frac));
}

int fpow(int n, int a) {
    if (n == 1)
        return 1;
    if (a == 0)
        return 1;
    if (a == 1)
        return n;
    int half = fpow(n, a/2);
    if (a % 2 == 0)
        return (half * (long long) half) % MOD;
    else {
        int x = (half * (long long) half) % MOD;
        return (n * (long long) x) % MOD;
    }
}

inline int inverse(int x) {
    return fpow(x, MOD - 2);
}

int main(void) {
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    if (n <= 10) {
        scanf("%d", &q);
        int type, p, f, r;
        while (q--) {
            scanf("%d", &type);
            if (type == 1) {
                scanf("%d %d", &p, &f);
                a[p-1] = f;
            }
            else {
                scanf("%d", &r);
                long long product = a[0];
                for (int i = r; i < n; i += r) {
                    product = product * a[i];
                }
                long long dig = product;
                while (dig > 9)
                    dig /= 10;
                printf("%lld %lld\n", dig, product % MOD);
            }
        }
        return 0;
    }

    for (int r = 1; r <= n; r++) {
        logs[r] = 0;
        pr[r] = 1;
        for (int i = r; i < n; i += r) {
            logs[r] += log10(a[i]);
            pr[r] = (pr[r] * (long long)a[i]) % MOD;
        }
    }

    scanf("%d", &q);
    int type, p, f, r;
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d", &p, &f);
            p--;

            double remove = log10(a[p]);
            double put = log10(f);
            int previnv = inverse(a[p]);
            a[p] = f;


            for (int i = 1; i <= sqrt(p); i++) {
                if (p % i == 0) {
                    logs[i] += put;
                    logs[i] -= remove;
                    pr[i] = (pr[i] * (long long) previnv) % MOD;
                    pr[i] = (pr[i] * (long long) f) % MOD;
                    int x = p / i;
                    if (x != i) {
                        logs[x] += put;
                        logs[x] -= remove;
                        pr[x] = (pr[x] * (long long) previnv) % MOD;
                        pr[x] = (pr[x] * (long long) f) % MOD;
                    }
                }
            }
        }
        else {
            scanf("%d", &r);
            printf("%d %d\n", getdigit(log10(a[0]) + logs[r]),(int) ((pr[r]*(long long)a[0]) % MOD));
        }
    }
    return 0;
}

