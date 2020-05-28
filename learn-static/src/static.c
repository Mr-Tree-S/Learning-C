#include <stdio.h>

int n=10;

void fn()
{
	int n=10;
	printf("n=%d\n",n);
	n++;
	printf("n++=%d\n",n);
}

void fn_static()
{
	static int n=10;
	printf("static n=%d\n",n);
	n++;
	printf("static n++=%d\n",n);
}

void fn_extern()
{
	extern int n;
	printf("extern n=%d\n",n);
	n++;
	printf("extern n++=%d\n",n);
}


int main()
{
	fn();
	printf("#####################\n");
	fn_static();
	printf("#####################\n");
	fn_extern();
	printf("---------------------\n");
	fn();
	printf("#####################\n");
	fn_static();
	printf("#####################\n");
	fn_extern();

	return 0;
}
