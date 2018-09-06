#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 1e9 + 8;
const ll infll = 1e18;

int n;
int a[100100];
int b[100100];

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    /*
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    printf("\n");
    */
    ll ans = 0;
    int moves = 0;
    int i = n, j = n;
    int cur = 1;
    while (moves <= 2 * n) {
        cur ^= 1; moves++;
        if (cur == 0) {
       //     printf("A's turn...\n");
            if (i == 0) {
      //          printf("remove %d\n", b[j]);
                j--;
                continue;
            }
            else if (j == 0) {
     //           printf("add %d\n", a[i]);
                ans += a[i];
                i--;
                continue;
            }
            if (a[i] > b[j]) {
    //            printf("add %d\n", a[i]);
                ans += a[i];
                i--;
            }
            else {
   //             printf("remove %d\n", b[j]);
                j--;
            }
        }
        else {
        //    printf("B's turn...\n");
            if (i == 0) {
  //              printf("take %d\n", b[j]);
                ans -= b[j];
                j--;
                continue;
            }
            else if (j == 0) {
 //               printf("remove %d\n", a[i]);
                i--;
                continue;
            }

            if (a[i] > b[j]) {
//                printf("remove %d\n", a[i]);
                i--;
            }
            else {
//                printf("take %d\n", b[j]);
                ans -= b[j];
                j--;
            }
        }
//        printf("turn done! i = %d, j = %d, ans = %lld\n", i, j, ans);
    }
    printf("%lld\n", ans);
    return 0;
}

