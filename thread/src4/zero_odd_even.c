#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct {
	int n;
	pthread_mutex_t lock0;
	pthread_mutex_t lock1;
	pthread_mutex_t lock2;
	int flag;
}Lock;

Lock *LockCreat(int n)
{
	Lock *L = (Lock*)malloc(sizeof(Lock));

	L->n = n;
	L->flag = 1;
	pthread_mutex_init(&L->lock0, NULL);
	pthread_mutex_init(&L->lock1, NULL);
	pthread_mutex_init(&L->lock2, NULL);

	pthread_mutex_lock(&L->lock1);
	pthread_mutex_lock(&L->lock2);

	return L;
}

void *Zero(Lock *L)
{
	int i;
	int n = L->n;
	for (i = 1; i <=n; i++) {
		pthread_mutex_lock(&L->lock0);
		printf("0");
		
		if (L->flag) {
		pthread_mutex_unlock(&L->lock1);
//		printf("###unlock one###\n");
		} else {
		pthread_mutex_unlock(&L->lock2);
//		printf("###unlock two###\n");
		}

		L->flag = !L->flag;
	}
}
void *Odd(Lock *L)
{
	int i;
	int n = L->n;
	for (i = 1; i <=n; i+=2) {
		pthread_mutex_lock(&L->lock1);
		printf("%d", i);
		pthread_mutex_unlock(&L->lock0);
	}
}
void *Even(Lock *L)
{
	int i;
	int n = L->n;
	for (i = 2; i <=n; i+=2) {
		pthread_mutex_lock(&L->lock2);
		printf("%d", i);
		pthread_mutex_unlock(&L->lock0);
	}
}

void LockFree(Lock *L)
{
	pthread_mutex_destroy(&L->lock0);
	pthread_mutex_destroy(&L->lock1);
	pthread_mutex_destroy(&L->lock2);
	free(L);
}


int main()
{
	int n;
	scanf("%d", &n);
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	Lock *L = LockCreat(n);


	pthread_create(&th1, NULL, Zero, L);
	pthread_create(&th2, NULL, Odd, L);
	pthread_create(&th3, NULL, Even, L);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_join(th3, NULL);
	LockFree(L);
	
	return 0;
}
