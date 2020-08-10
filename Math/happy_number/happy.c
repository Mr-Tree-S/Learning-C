#include <stdio.h>
#include <stdbool.h>


int deal(int n)
{
	int ret = 0;
	while (n != 0) {
		ret += (n%10)*(n%10);
		n = n/10;
	}
	return ret;
}

bool happy(int n)
{
	int fast = n, slow = n;
	do {
		fast = deal(fast);
		fast = deal(fast);
		slow = deal(slow);
	} while (fast != slow);
	return fast == 1;
}


void main()
{
	int i;
	scanf("%d", &i);

	if (happy(i))
		printf("Happy\n");
	else
		printf("Sad\n");
}
