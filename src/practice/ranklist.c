#include "stdio.h"

int main( void ){
    long long terms; //variable to store the number of terms
    scanf("%lld", &terms);
    long long sums[100000];
    sums[0] = 0;
    long long i;
    for(i=1;i<100000;i++)
        sums[i] = i + sums[i-1];
    while( terms-- ){
        long long num, sum;
        scanf("%lld %lld", &num, &sum);
        long long difference = sums[num] - sum;
        long long j;
        if( difference == 0 ){
            printf("0\n");
            continue;
        } 
        for(j=num; j>=1; j--){
            if( (difference - j + 1) <= 0 ){
                break;
            }
            else {
                difference = difference - j + 1;
            }
        }
        printf("%lld\n", num - j + 1);
    }
}