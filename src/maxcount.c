#include <stdio.h>
int main( void ){
    int terms;
    scanf("%d", &terms);
    while( terms-- ){
        int n;
        scanf("%d", &n);
        int arr[n];
        int freq[10001] = {0};
        int i, num = 0, max_count = 0;
        for( i=0; i<n; i++ ){
            scanf("%d", arr+i);
            freq[arr[i]] ++;
            if( freq[arr[i]] > max_count ){
                num = arr[i];
                max_count = freq[arr[i]];
            }
            else if(freq[arr[i]] == max_count)
                num = (num < arr[i]) ? num : arr[i];
        }
        printf("%d %d\n",num, max_count);
    }
}
