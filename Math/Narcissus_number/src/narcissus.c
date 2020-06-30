#include <stdio.h>
#include <stdlib.h>


int main()
{
	int x,a,b,c;
	for (x = 100; x <= 999; x++) {
		a = x/100;
		b = x/10%10;
		c = x%10;
		if (x == a*a*a+b*b*b+c*c*c)
			printf("Ë®ÏÉ»¨Êý:%d=%d*%d*%d+%d*%d*%d+%d*%d*%d\n", x, a, a, a, b, b, b, c, c, c);
	}

	return 0;
}
