#include <stdio.h>

void main(){
	int i,y;
	double l;
	double n=100;

	scanf("%d", &y);
	scanf("%lf", &l);

	for(i=0;i<y;i++){
		n=n*l;
		n=n-6.6;
	}

	printf("n=%f	year=%d\n", n, y);

	return 0;
}
