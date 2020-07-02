#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int s = 0;

pthread_mutex_t lock;

void *myfunc(void *args)
{
	int i = 0;
	for (i = 0; i < 1000000; i++) {
		pthread_mutex_lock(&lock);
		s++;
		pthread_mutex_unlock(&lock);
	}
}


int main()
{
	pthread_t th1;
	pthread_t th2;
	pthread_mutex_init(&lock, NULL);

	pthread_create(&th1, NULL, myfunc, NULL);
	pthread_create(&th2, NULL, myfunc, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_mutex_destroy(&lock);
	
	printf("s=%d\n", s);
	return 0;
}
