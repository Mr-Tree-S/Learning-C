#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#define port_N 10001
 
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
 
int main()
{
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ERR_EXIT("socket");

    int on = 1;
    int ret = setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on) );
    
	/* 设置sockaddr_in 结构体相关参数 */
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port_N);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	/* 绑定函数bind() */
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		ERR_EXIT("bind");

	/* 调用listen()函数，创建未处理请求队列 */
    if ((listen(sockfd,SOMAXCONN)) < 0 )		//主动套接字，变成被动套接字
		ERR_EXIT("listen");
      
    struct sockaddr_in Caddr;
    socklen_t socklen = sizeof(Caddr);
    int conn;
    if ((conn = accept(sockfd, (struct sockaddr*)&Caddr,&socklen)) < 0)	//获得到是主动套接字
        ERR_EXIT("accept");
	printf("ip:%s   port:%d\n", inet_ntoa(Caddr.sin_addr), ntohs(Caddr.sin_port));       

	char sendbuf[1024];
	char recvbuf[1024];

	pid_t pid;
	pid = fork();
	
	if (pid == -1)
		ERR_EXIT("pid");

	if (pid == 0) {
		signal(SIGUSR1, handler);
		while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
			write(conn, sendbuf, strlen(sendbuf));                
			memset(sendbuf, 0, sizeof(sendbuf));
		}
		printf("child closed\n");
		exit(EXIT_SUCCESS);
	} else {
		while (1) {
			memset(recvbuf, 0, sizeof(recvbuf));
			int ret = read(conn, recvbuf, sizeof(recvbuf));
			if (ret  == -1) {
				ERR_EXIT("read");
			} else if (ret == 0) { 
			  printf("peer close\n");
			  break;
			}
			printf("Client:");
			fputs(recvbuf, stdout);
		}
		printf("kill parent!\n");
		kill(pid, SIGUSR1);
		exit(EXIT_SUCCESS);
		//do_something(conn);
	 
	}
	
	close(conn);
	close(sockfd);
	exit(0);
}

void do_something(int conn)
{
     char recvbuf[1024];
     for(;;)
     {
     memset(recvbuf,0,sizeof(recvbuf));
     int ret = read(conn,recvbuf,sizeof(recvbuf));
     if(ret == 0)
     {
         printf("client closed!\n");
         break;
     }
     else if(ret == -1)
     {
         ERR_EXIT("read");
     }
     fputs(recvbuf,stdout);
     write(conn,recvbuf,ret);
     }
}

