#include <stdio.h>

int main()
{
	int x=30;
	printf("First out x\n");
	printf("x is out block: %d at %p\n",x,&x);
	
	{
		int x=66;
		printf("x is in block: %d at %p\n",x,&x);
	}

	printf("Second out x\n");
	printf("x is out block: %d at %p\n",x,&x);

	while(x++ < 32){
		int x=100;
		x++;
		printf("x is while block: %d at %p\n",x,&x);
	}

	printf("Third out x\n");
	printf("x is out block: %d at %p\n",x,&x);

	return 0;
}
