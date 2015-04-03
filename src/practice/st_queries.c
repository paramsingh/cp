#include <stdio.h>

void num_substring(int *a, int x, int y)
{
	int found[] = {0,0,0};
	int last_found[] = {0,0,0};
	int sum_found = 0,i,j;
	for(i=x; i<=y; i++){
		int res = a[i-1]%3;
		found[res % 3] = last_found[0] + 1;
		found[(res+1) % 3] = last_found[1];
		found[(res+2) % 3] = last_found[2];
		sum_found += found[0];
		for(j=0;j<3;j++){
			int tmp = found[j];
			found[j] = last_found[j];
			last_found[j] = tmp;
		}
	}
	printf("%d\n", sum_found);
}

int main(void)
{
	int n,m;
	scanf("%d %d", &n, &m);
	char st[n];
	scanf("%s", st);
	int i;
	int a[n];
	for(i=0;i<n;i++){
		a[i] = st[i] - '0';
	}
	for(i=0; i<m; i++){
		int query, x, y;
		scanf("%d %d %d", &query, &x, &y);
		if( query == 1 ){
			a[x-1] = y;
		}
		else {
			num_substring(a, x, y);
		}
	}
}