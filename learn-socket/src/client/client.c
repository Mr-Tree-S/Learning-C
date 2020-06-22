#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#define portN 3333


int main(int argc, char *argv[])
{

    if (argc != 2) {
        fprintf(stderr,"Usage :%s hostname \a\n",argv[0]);
        exit(1);
    }

    /* 创建socket */
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf(stderr,"Socket Error :%s\a\n",strerror(errno));
		exit(1);
	}

	/* 设置sockaddr_in Caddr结构体相关参数 */
    struct sockaddr_in Caddr;
    memset(&Caddr, 0, sizeof(Caddr));
    Caddr.sin_family = AF_INET;
    Caddr.sin_port = htons(portN);
	Caddr.sin_addr.s_addr = inet_addr(argv[1]);

    /* 调用connect函数主动发起对服务器端的连接 */
    if (connect(sockfd, (struct sockaddr*)&Caddr, sizeof(Caddr)) < 0) {
        fprintf(stderr,"Connect Error :%s\a\n",strerror(errno));
        exit(1);
    }

    /* 发送消息给服务器端 */
	char buffer[1024];
	printf("Please input char :\n");
	fgets(buffer,1024,stdin);
    write(sockfd, buffer, strlen(buffer));

	/* 调用recv()函数接收客户端的请求 */
	int recvbytes;
	char revbuf[1024];
	memset(revbuf, 0, sizeof(revbuf));
	if ((recvbytes = recv(sockfd, revbuf, sizeof(revbuf), 0)) < 0) {
        perror("recv");
        exit(1);
	}
    printf("Received a message: %s\n", revbuf);
    close(recvbytes);
//	int recv(int sockfd, void *buf,int len, unsigned int flags)
    close(sockfd);
    exit(0);
}
