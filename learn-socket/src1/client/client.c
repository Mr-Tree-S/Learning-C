#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#define portN 10001

#define ERR_EXIT(m) \
     do {  \
           perror(m); \
           exit(EXIT_FAILURE); \
     } while(0) 


void handler(int sig)
{
    printf("recv a sig = %d\n",sig);
    exit(EXIT_SUCCESS);
}
 
 
int main(int argc, char *argv[])
{
    int sockfd;
    
	if (argc != 2) {
        fprintf(stderr,"Usage :%s hostname \a\n",argv[0]);
        exit(1);
    }

	/* 创建socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ERR_EXIT("socket");

	/* 设置sockaddr_in Caddr结构体相关参数 */
	struct sockaddr_in Caddr;
    memset(&Caddr, 0, sizeof(Caddr));
    Caddr.sin_family = AF_INET;
    Caddr.sin_port = htons(portN);
    Caddr.sin_addr.s_addr = inet_addr(argv[1]);
//  Caddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	/* 调用connect函数主动发起对服务器端的连接 */
    if (connect(sockfd, (struct sockaddr*)&Caddr,sizeof(Caddr)) < 0)
		ERR_EXIT("connect");
 
    char sendbuf[1024];
    char recvbuf[1024];
	
	pid_t pid;
	pid = fork();

	if (pid == -1)
		ERR_EXIT("fork");
    
	if (pid == 0) {
		while (1) {
			memset(recvbuf, 0, sizeof(recvbuf));
            int ret = read(sockfd, recvbuf, sizeof(recvbuf));
            if (ret == -1)
				ERR_EXIT("read");
            else if (ret == 0) {
                printf("peer closed\n");
                break;
            }
			printf("Server:");
            fputs(recvbuf,stdout);
        }
 
        printf("child close\n");
        kill(pid,SIGUSR1);
        exit(EXIT_SUCCESS);
    } else {        
        signal(SIGUSR1,handler);
        while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
            write (sockfd,sendbuf,strlen(sendbuf));  
            memset(sendbuf,0,sizeof(sendbuf));
		}
        printf("parent close!\n");
    }
    close(sockfd);
    exit(0);
}
