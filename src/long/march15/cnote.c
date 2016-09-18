#include <stdio.h>
int main (void){
    int terms;
    scanf("%d", &terms);
    while(terms--){
        int x, y, k, n;
        scanf("%d%d%d%d", &x, &y, &k, &n);
        int req_pages = x - y;
        int i, flag = 0;
        for(i=1;i<=n;i++){
            int pi, ci;
            scanf("%d%d", &pi, &ci);
            if( pi>=req_pages && ci<=k )
                flag = 1;
        }
        if(flag)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
    }
}
