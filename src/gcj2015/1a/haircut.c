#include <stdio.h>
int main(void){
    int terms;
    scanf("%d", &terms);
    int cases;
    for(cases=1;cases<=terms;cases++){
        int b, n;
        scanf("%d%d", &b, &n);
        int m[b];
        int index[b];
        int i;
        for(i=0;i<b;i++){
            scanf("%d", m+i);
            index[i] = i;
        }
        if(n<=b){
            printf("Case %d: %d\n", cases, n);
            continue;
        }
    	for(int x=0; x<b; x++){
            for(int y=0; y<b-1; y++){
                if(m[y]>m[y+1]){
                    int temp = m[y+1];
                    m[y+1] = m[y];
                    m[y] = temp;
                    temp = index[y+1];
                    index[y+1] = index[y];
                    index[y] = temp;
    			}
    		}
    	}
        int slowest = m[b-1], si = m[b-1];

    }
}
