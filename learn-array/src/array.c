#include <stdio.h>

int main()
{
	int x,i;
	const int n=10;
	int count[n];

	for(i=0;i<n;i++){
		count[i]=0;
	}

	scanf("%d",&x);
	while(x != -1){
		if(x >= 0 && x <= n){
			count[x]++;
		}
		scanf("%d",&x);
	}

	for(i=0;i<n;i++){
		printf("%d:%d\n",i,count[i]);
	}

	return 0;
}
