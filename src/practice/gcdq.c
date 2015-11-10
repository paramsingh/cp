#include <stdio.h>

int hcf( int a, int b )
{
	while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
	}
	return a;
}

int main( void )
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n, q;
		scanf("%d %d", &n, &q);
		int i;
		int arr[n];
		for(i=0;i<n;i++){
			scanf("%d", arr+i);
		}
        int left[n], right[n];
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for (i = 1; i < n; i++)
            left[i] = hcf(arr[i], left[i-1]);
        for (i = n-2; i >= 0; i--)
            right[i] = hcf(arr[i], right[i+1]);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--;
            r--;
            if (l == 0)
                printf("%d\n", right[r+1]);
            else if (r == n-1)
                printf("%d\n", left[l-1]);
            else
                printf("%d\n", hcf(left[l-1], right[r+1]));
		}
	}
}
