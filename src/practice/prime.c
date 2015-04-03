#include <stdio.h>

int main(void){
    int terms;
    scanf("%d", &terms);
    while(terms--){
        int n;
        scanf("%d", &n);
        if(n==0 || n==1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
