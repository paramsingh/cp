#include <stdio.h>
#include <stdlib.h>
int main(void){
    int terms;
    scanf("%d", &terms);
    while(terms--){
        int base, mod;
        scanf("%d%d", &base, &mod);
        char *ch = (char *)calloc(1000*sizeof(char), sizeof(char));
        scanf("%s", ch);
        int i=0;
        int num = 0;
        while(ch[i] != '\0'){
            int digit = ch[i] - '0';
            num = num * base + digit;
            printf("%d ", num%mod);
            i++;
        }
        printf("\n");
    }
}
