#include <stdio.h>
#include <stdlib.h>

long long int big = 1000000000;
int main(void){

    int **choose;
    choose = (int **)calloc(4001, 8);
    int n, r;
    for(n=0; n<4001; n++){
        choose[n] = (int *)calloc(2001, 8);
        choose[n][0] = 1;
        choose[n][1] = n;
    }
    int cases, loop, i, j, ans;
    /* printf("%d\n", choose[2][1] ); */
    for(n=1; n<4001; n++){
        for(r=2; r<2001; r++){
            if(n<r)
                break;
            choose[n][r] = (choose[n-1][r-1] + choose[n-1][r]) % big;
        }
    }
    scanf("%d", &cases);
    for(loop = 0; loop < cases; loop++){
        ans = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        int req[m+1];
        int sums[m+1];
        for(i=0;i<=m;i++){
            /** req[i] = m+i-1 choose i
              * will have to use granville's generalisation of lucas' theorem
              * and then, the chinese remainder theorem to find
              * (m+i-1 choose i) mod 10 ^ 9
              * or we could compute them earlier and be done with this shit
              * n choose r = n choose (n-r)
              * therefore, m+i-1 choose i = m+i-1 choose m-1
              */
            if(i <= 2000)
                req[i] = sums[i] = choose[m+i-1][i];
            else
                req[i] = sums[i] = choose[m+i-1][m-1];
        }
        for(i=0; i<n; i++){
            ans = 0;
            for(j=0; j<=m; j++){
                ans += sums[j];
                ans %= big;
                sums[j] = ((req[j] % big)* (ans)) % big;
            }
        }
        printf("%d\n", ans);
    }
}


