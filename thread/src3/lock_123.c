#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct {
	pthread_mutex_t lock1;
	pthread_mutex_t lock2;
}Lock;

Lock *LockCreat()
{
	Lock *L = (Lock*)malloc(sizeof(Lock));

	pthread_mutex_init(&L->lock1, NULL);
	pthread_mutex_init(&L->lock2, NULL);

	pthread_mutex_lock(&L->lock1);
	pthread_mutex_lock(&L->lock2);

	return L;
}

void *first(Lock *L)
{
	printf("first\n");
	pthread_mutex_unlock(&L->lock1);
}

void *second(Lock *L)
{
	pthread_mutex_lock(&L->lock1);
	printf("second\n");
	pthread_mutex_unlock(&L->lock1);
	pthread_mutex_unlock(&L->lock2);
}

void *third(Lock *L)
{
	pthread_mutex_lock(&L->lock2);
	printf("third\n");
	pthread_mutex_unlock(&L->lock2);
}

void LockFree(Lock *L)
{
	pthread_mutex_destroy(&L->lock1);
	pthread_mutex_destroy(&L->lock2);
	free(L);
}


int main()
{
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	Lock *L = LockCreat();

	pthread_create(&th1, NULL, third, L);
	pthread_create(&th2, NULL, second, L);
	pthread_create(&th3, NULL, first, L);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_join(th3, NULL);
	LockFree(L);
	
	return 0;
}
