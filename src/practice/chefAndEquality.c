#include <stdio.h>
int main(void){
	int cases;
	scanf("%d", &cases);
	while(cases--){
		int freq[100001] = {0};
		int n;
		scanf("%d", &n);
		int i;
		for(i=0;i<n;i++){
			int pile;
			scanf("%d", &pile);
			freq[pile] ++;
		}
		int max = freq[1];
		for(i=2;i<100001;i++){
			if(freq[i] > max){
				max = freq[i];
			}
		}
		printf("%d\n", n-max);
	}
}