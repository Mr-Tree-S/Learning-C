#include <stdio.h>

int main(){
	int n,i;

	scanf("%d",&n);
	int fa=1;

	for(i=2; i<=n; i++){
		fa*=i;
	}
	printf("factorial=%d \n",fa);
	
	return 0;
}
