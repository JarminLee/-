/*************************************************************************
	> File Name: server.c
	> Author:李嘉明
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月06日 星期二 17时31分40秒
 ************************************************************************/

#include "head.h"
#define MAX_SIZE 6666
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
	return sockfd;
}

int main() {
	int a = 0;
	int server_listen, socketfd, port, pid;


	port = 5555;

	if ((server_listen = socket_create(port)) < 0 ) {
		printf("Error creating server_listen socket");
		exit(1);
	}

	while(1) {
		struct sockaddr_in client_addr;
		socklen_t len = sizeof(client_addr);
		if((socketfd = accept(server_listen, (struct sockaddr*) &client_addr, &len)) < 0)
			break;


		struct sockaddr_in peer;
		socklen_t peer_len = sizeof(struct sockaddr_in);
		bzero(&peer, sizeof(struct sockaddr_in));
		getpeername(socketfd, (struct sockaddr *)&peer, &peer_len);
		char buff_peer[64] = {'\0'};
		inet_ntop(AF_INET, (void*)&peer.sin_addr, buff_peer, 63);


		if ((pid = fork()) < 0)
			printf("Error forking child process");
		if (pid == 0) {
			close(server_listen);
			char buffer[MAX_SIZE];
                int flag = 0;
                int step = 0;
                char fname[1000];
		while ((a = recv(socketfd, buffer, 100, 0)) >  0 ) {
			  printf("%s", buffer);
              printf("\n");
		      fflush(stdout);
			  memset(buffer, 0, sizeof(buffer));
            
            
            
            
		}
			printf("\n");
			close(socketfd);
			exit(0);

		}
		close(socketfd);
	}
	return 0;
}
