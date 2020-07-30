#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int arr[4000];

typedef struct {
	int first;
	int last;
	int result;
} MY_ARGS;

void *myfunc(void *args)
{
	int i;
	int s = 0;
	MY_ARGS *my_args = (MY_ARGS*)args;
	int first = my_args->first;
	int last = my_args->last;
	for (i = first; i < last; i++) {
		s = s + arr[i];
	}
	my_args->result = s;
	return NULL;
}

int main()
{
	int i;
	for (i = 0; i<4000; i++) {
//		arr[i] = rand()%100;
		arr[i] = 1;
	}

	pthread_t th1;
	pthread_t th2;
	
	MY_ARGS args1 = {0, 2000, 0};
	MY_ARGS args2 = {2000, 4000, 0};

	pthread_create(&th1, NULL, myfunc, &args1);
	pthread_create(&th2, NULL, myfunc, &args2);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	int s1 = args1.result;
	int s2 = args2.result;
	printf("s1=%d\n", s1);
	printf("s2=%d\n", s2);

	printf("s1+s2=%d\n", s1+s2);
	return 0;
}
