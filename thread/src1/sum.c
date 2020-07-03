#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int arr[5000];

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
	for (i = 0; i<5000; i++) {
		arr[i] = rand()%50;
	}

	pthread_t th1;
	pthread_t th2;
	
	MY_ARGS args1 = {0, 2500, 0};
	MY_ARGS args2 = {2500, 5000, 0};

	pthread_create(&th1, NULL, myfunc, &args1);
	pthread_create(&th2, NULL, myfunc, &args2);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	int s1 = args1.result;
	int s2 = args2.result;
	printf("s1=%d\n", s1);
	printf("s1=%d\n", s1);

	printf("s1+s2=%d\n", s1+s2);
	return 0;
}