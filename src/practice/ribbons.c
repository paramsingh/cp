#include <stdio.h>
unsigned long long gcd(unsigned long long u, unsigned long long v) {
    return (v != 0)?gcd(v, u%v):u;
}
int main(void){
    unsigned long long terms, n;
    scanf("%lld", &terms);
    while(terms--){
        scanf("%lld", &n);
        unsigned long long a[n];
        unsigned long long i;
        for(i=0;i<n;i++){
            scanf("%lld", a+i);
        }
        unsigned long long hcf = gcd(a[0], a[1]);
        for(i=2;i<n;i++)
            hcf = gcd(hcf, a[i]);
        printf("%lld\n", hcf);
    }
}
