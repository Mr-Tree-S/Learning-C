#include <stdio.h>


int main()
{
	printf("sizeof(char)=%ld\n", sizeof(char));
	printf("sizeof(short)=%ld\n", sizeof(short));
	printf("sizeof(int)=%ld\n", sizeof(int));
	printf("sizeof(long)=%ld\n", sizeof(long));
	printf("sizeof(long long)=%ld\n", sizeof(long long));
/*	printf("sizeof(float)=%ld\n", sizeof(float));
	printf("sizeof(double)=%ld\n", sizeof(double));
*/

	char c=255;
	int i=255;
	printf("char c=%d\nint i=%d\n", c, i);
	return 0;
}
