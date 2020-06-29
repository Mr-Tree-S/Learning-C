#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#define port_N 3333


int main(int argc, char *argv[])
{
    /* 建立socket连接 */
	int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr,"Socket error :%s\n\a", strerror(errno));
        exit(1);
    }
    printf("socket id=%d\n",sockfd);

    /* 设置sockaddr_in 结构体中相关参数 */
    struct sockaddr_in Saddr;
    memset(&Saddr, 0, sizeof(Saddr));
    Saddr.sin_family = AF_INET;
    Saddr.sin_port = htons(port_N);
    Saddr.sin_addr.s_addr = htonl(INADDR_ANY);	//INADDR_ANY表示本机IP
//	Saddr.sin_addr.s_addr = inet_addr("0.0.0.0");

	/* 绑定函数bind() */
    if(bind(sockfd, (struct sockaddr*)&Saddr, sizeof(Saddr)) < 0) {
        fprintf(stderr,"Bind error :%s\n\a", strerror(errno));
        exit(1);
    }
    printf("Binding succeed!\n");
    
	/* 调用listen()函数，创建未处理请求的队列 */
    if (listen(sockfd,5) < 0) {
        fprintf(stderr,"Listen error :%s\n\a", strerror(errno));
        exit(1);
    }
    printf("Listening...\n");
    
	/* 调用accept()函数，等待客户端的连接 */
    int new_fd;
    char buffer[1024];
    int socklen;
    struct sockaddr_in Caddr;
    int nbytes;
    while (1) {
        memset(buffer, 0x00, 1024);
        socklen = sizeof(Caddr);
        if ((new_fd = accept(sockfd, (struct sockaddr*)&Caddr, &socklen)) < 0) {
            fprintf(stderr,"Accept error :%s\n\a", strerror(errno));
            exit(1);
        }
        fprintf(stderr,"Server get connection from %s\n", inet_ntoa(Caddr.sin_addr));
        
		if ((nbytes = read(new_fd, buffer, 1024)) < 0) {
            fprintf(stderr,"Read error :%s\n\a", strerror(errno));
            exit(1);
        }
        
		/*********************************/
        char *str1="HelloServer";
        char *str2="HelloABC";
 
        if (strncmp(buffer, str1, strlen(str1)) == 0) {
            printf("Received a message1111: %s\n", buffer);
            send(new_fd,"Hello,Client",12,0);
            printf("send a message111: Hello,Client\n");
        }
 
 
        if (strncmp(buffer, str2, strlen(str2)) == 0) {
            printf("Received a message2222: %s\n", buffer);
            send(new_fd,"Hello,abc",9,0);
            printf("send a message222: Hello,abc\n");
        }
 
 
        if (strncmp(buffer, "exit", 4) == 0) {
            exit(0);
        }
 
        buffer[nbytes] = '\0';
        printf("Server received  %s\n", buffer);
        close(new_fd);
    }
 
    close(sockfd);
    exit(0);
}
