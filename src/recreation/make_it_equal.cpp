#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int height[200001];
ll freq[201000];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
        freq[height[i]] += 1;
    }

    sort(height, height + n);
    ll sum = 0, cnt = 0;
    int ans = 0;
    for (int h = height[n - 1]; ;h--) {
        sum += freq[h] * h;
        cnt += freq[h];
        ll cost = sum - (cnt * h);

        if (h == height[0]) {
            if (cost > 0 && cost <= k) {
                ans++;
            }
            if (cost <= k)
                break;
        }
        if (cost > k) {
            h++;
            cnt -= freq[h - 1];
            sum = cnt * h;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
