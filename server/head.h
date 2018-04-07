/*************************************************************************
	> File Name: head.h
	> Author:李嘉明 
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月06日 星期二 17时24分40秒
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>

#define CPU1 "100"
#define CPU2 "102"
#define CPU3 "103"
#define MEM1 "200"
#define MEM2 "202"
#define MEM3 "203"
#define DISK1 "300"
#define DISK2 "302"
#define DISK3 "303"

#define CTRL_PORT 5555
#define DATA_PORT1 7610
#define DATA_PORT2 7620
#define DATA_PORT3 7630
#define IP "192.168.1.110"
char *ip[10] = {"192.168.1.40",
               "192.168.1.41",
               "192.168.1.42",
               "192.168.1.43",
               "192.168.1.44",
               "192.168.1.45",
               "192.168.1.46", 
               "192.168.1.47",
               "192.168.1.48",
               "192.168.1.49"};

#define DEBUG
#ifdef DEBUG
#define DBG(s, va_arg...) {\
    printf("FILE:%s LINE:[%d] return = ", __FILE__, __LINE__);\
    printf(s, ##va_arg);\
 }
#else
#define DBG(s, va_arg...)
#endif


#define MAX_SIZE 6666

int socket_connect(int port, char *host) {
    int sockfd;
    struct sockaddr_in dest_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        return -1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);

    fflush(stdout);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr))) {
        return -1;
    }
    return sockfd;
}

/*
*创建监听套接字
*返回套接字描述符，错误返回-1
*/

int socket_create(int port){
	int sockfd;
	int yes = 1;
	struct sockaddr_in sock_addr;

	//创建套接字
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket() error\n");
		return -1;
	}

	//设置本地套接字地址
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(port); //转化为网络字节序
	sock_addr.sin_addr.s_addr = htonl(INADDR_ANY); //0.0.0.0

	//设置本地套接字
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
		close(sockfd);
		perror("setsockopt() error\n");
		return -1;
	}

	//绑定本地套接字到套接字
	if (bind(sockfd, (struct sockaddr *) &sock_addr, sizeof(sock_addr)) < 0) {
		close(sockfd);
		perror("bind() error\n");
		return -1;
	}

	//将套接字设置为监听状态
	if (listen(sockfd, 20) < 0) {
		close(sockfd);
		perror("listen() error");
		return -1;
	}
    struct sockaddr_in client_add;
    socklen_t l = sizeof(sock_addr);
    int listen_soc = accept(sockfd, (struct sockaddr*)&client_add, &l);
    if (listen_soc < 0) {
        printf("accept ERROR\n");
    } else {
        printf("accept OK\n");

        close(sockfd);
    }
    return listen_soc;
	//return sockfd;
}

#endif
