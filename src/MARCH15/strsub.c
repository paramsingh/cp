#include <stdio.h>
int main( void ){
    int terms;
    scanf("%d", &terms);
    while(terms--){
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        char str[n];
        scanf("%s", str);
        int zeros[n];
        int ones[n];
        int i,j;
        for(i=0;i<n;i++){
            zeros[i] = 0;
            ones[i] = 0;
        }
        for(i=0;i<n;i++){
            if( str[i] == '0' )
                zeros[0]++;
            else
                ones[0]++;
        }
        for(i=1;i<n;i++){
            if(str[i-1]=='0'){
                zeros[i] = zeros[i-1] - 1;
                ones[i] = ones[i-1];
            }
            else{
                ones[i] = ones[i-1] - 1;
                zeros[i] = zeros[i-1];
            }
        }
        while(q--){
            int count = 0;
            int li, ri;
            scanf("%d%d", &li, &ri);
            int looper, l;
            for(looper=li-1; looper<ri;looper++){
                for(l=looper; l<ri; l++){
                    int z = zeros[looper] - zeros[l];
                    if (str[l]=='0')
                        z++;
                    int o = ones[looper] - ones[l];
                    if (str[l] == '1')
                        o++;
                    if (z<=k && o<=k)
                        count++;
                    else
                        break;
                }
            }
            printf("%d\n", count);
        }
    }
}
