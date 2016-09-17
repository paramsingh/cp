#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[510][510];
ll sum1[510][510];
ll sum2[510][510];
vector<int> here[5];
int n, k;

ll rowsum[510];
ll colsum[510];

int check(ll* arr, ll mx) {
    ll s = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s + arr[i] > mx) {
            cnt++;
            s = 0;
        }
        s += arr[i];
    }
    return cnt + 1 <= k;
}

void print(ll* arr, ll mx, int id) {
    ll s = 0;
    int cnt = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (s + arr[i] > mx) {
            cnt++;
            here[id].push_back(i - 1);
            last = i;
            s = 0;
        }
        s += arr[i];
    }
    for (int i = 1; i <= k - cnt - 1; i++) {
        here[id].push_back(last + i - 1);
        cnt++;
    }
}

void getcols() {
    int cnt = 0;
    ll s = 0;
    for (int j = 0; j < n; j++) {
        cnt = 0;
        s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i][j];
            if (i == here[0][cnt]) {
                sum1[cnt++][j] = s;
                s = 0;
            }
        }
        if (cnt < k)
            sum1[cnt++][j] = s;
    }
}

void getrows() {
    int cnt = 0;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        s = 0;
        for (int j = 0; j < n; j++) {
            s += a[i][j];
            if (j == here[1][cnt]) {
                sum2[i][cnt++] = s;
                s = 0;
            }
        }
        if (cnt < k)
            sum2[i][cnt++] = s;
    }
}

int check1(ll mx) {
    int cnt = 0;
    ll temp[k] = {0};
    for (int j = 0; j <= n; j++) {
        ll x = 0;
        for (int i = 0; i < k; i++)
            x = max(x, temp[i] + sum1[i][j]);
        if (x > mx) {
            memset(temp, 0, sizeof(temp));
            cnt++;
        }
        if (j == n)
            break;
        for (int i = 0; i < k; i++)
            temp[i] += sum1[i][j];
    }
    return cnt + 1 <= k;
}

int check2(ll mx) {
    int cnt = 0;
    ll temp[k] = {0};
    for (int i = 0; i <= n; i++) {
        ll x = 0;
        for (int j = 0; j < k; j++)
            x = max(x, temp[j] + sum2[i][j]);
        if (x > mx) {
            memset(temp, 0, sizeof(temp));
            cnt++;
        }
        if (i == n)
            break;
        for (int j = 0; j < k; j++)
            temp[j] += sum2[i][j];
    }
    return cnt + 1 <= k;
}

void print1(ll mx) {
    int cnt = 0;
    ll temp[k] = {0};
    int last = 0;
    for (int j = 0; j < n; j++) {
        ll x = 0;
        for (int i = 0; i < k; i++)
            x = max(x, temp[i] + sum1[i][j]);
        if (x > mx) {
            memset(temp, 0, sizeof(temp));
            cnt++;
            printf("%d ", j);
            last = j;
        }
        for (int i = 0; i < k; i++)
            temp[i] += sum1[i][j];
    }
    for (int i = 1; i <= k - cnt - 1; i++)
        printf("%d ", last + i);
    printf("\n");
}

void print2(ll mx) {
    int cnt = 0;
    ll temp[k] = {0};
    int last = 0;
    for (int i = 0; i < n; i++) {
        ll x = 0;
        for (int j = 0; j < k; j++)
            x = max(x, temp[j] + sum2[i][j]);
        if (x > mx) {
            memset(temp, 0, sizeof(temp));
            cnt++;
            printf("%d ", i);
            last = i;
        }
        for (int j = 0; j < k; j++)
            temp[j] += sum2[i][j];
    }
    for (int i = 1; i <= k - cnt - 1; i++)
        printf("%d ", last + i);
    printf("\n");
}

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%lld", &a[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rowsum[i] += a[i][j];
            colsum[j] += a[i][j];
        }
    }
    ll lo = 0, hi = 1e15;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(rowsum, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    print(rowsum, lo, 0);
    getcols();

    lo = 0, hi = 1e15;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check1(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    ll ans1 = lo;

    lo = 0, hi = 1e15;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(colsum, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    print(colsum, lo, 1);
    getrows();

    lo = 0, hi = 1e15;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check2(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    ll ans2 = lo;
    if (ans2 > ans1) {
        // first rows then column
        //printf("hello, ans1 = %lld\n", ans1);
        for (int i = 0; i < here[0].size(); i++)
            printf("%d ", here[0][i] + 1);
        printf("\n");
        print1(ans1);
    }
    else {
        // first columns then rows
        //printf("ans2 = %lld\n", ans2);
        print2(ans2);
        for (int i = 0; i < here[1].size(); i++)
            printf("%d ", here[1][i] + 1);
        printf("\n");
    }
    return 0;
}
