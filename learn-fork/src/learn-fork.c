#include <unistd.h>
#include <stdio.h>


int main(void)
{
	int i=0;
	printf("i	son/parent	ppid	pid	fpid\n");

	for(i=0;i<2;i++){
		pid_t fpid=fork();
		if(fpid == 0)
		printf("%d	son		%4d	%4d	%4d\n", i, getppid(), getpid(), fpid);
		else
		printf("%d	parent		%4d	%4d	%4d\n", i, getppid(), getpid(), fpid);
	}
	return 0;
}

