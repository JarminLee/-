/*************************************************************************
	> File Name: server.c
	> Author: 史桢港 
	> Mail: 1031091451@qq.com
	> Created Time: 2018年03月06日 星期二 22时24分12秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

int socket_creat(int port) {
    int sockfd;
    int flag = 1;
    struct sockaddr_in sock_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("sock() error\n");
        return -1;
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *) &sock_addr, sizeof(sock_addr)) < 0) {
        close(sockfd);
        printf("bind error\n");
        return -1;
    }
    if (listen(sockfd, 20) < 0) {
        close(sockfd);
        printf("listen error\n");
        return -1;
    }//20代表请求队列的最大长度
    return sockfd;
}

char buffer[4000];

int main() {
    int pids;
    int n;
    printf("please input 端口号\n");
    scanf("%d", &n);
    if ((pids = fork()) < 0) {
        printf("fork() error\n");
        return 0;
    }
    if (pids == 0) {    
        int listen_sockfd, sockfd, a = 0;
        if ((listen_sockfd = socket_creat(n)) < 0) {
            printf("socket_creat() error\n");
            return 0;
        }
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        while (1) {
            if ((sockfd = accept(listen_sockfd, (struct sockaddr *) &client_addr, &len)) < 0) {
                //printf("accept() error\n");
                break;
            }
            int pid;
            if ((pid = fork()) < 0) {
                printf("fork error\n");
                close(sockfd);
                continue;
            }

            if (pid == 0) {
                if ((a = recv(sockfd, buffer, 1, 0)) <= 0) {
                    return 0;
                }
                if (strncmp(buffer, "1", 1) == 0) {
                    close(listen_sockfd);
                    memset(buffer, 0, 4000);
                    int num = send(sockfd, "ok1", 3, 0);
                    printf("num = %d\n", num);
                    while ((a = recv(sockfd, buffer, 3500, 0)) > 0) {
                        printf("%d :个字符%s", (int)strlen(buffer), buffer);
                        memset(buffer, 0, 4000);
                    }
                    printf("\n");
                    close(sockfd);
                    exit(0);
                } 
                if (strncmp(buffer, "2", 1) == 0) {
                    close(listen_sockfd);
                    memset(buffer, 0, 4000);
                    send(sockfd, "ok2", 3, 0);
                    //printf("num = %d\n", num);
                    char *path = (char *)malloc(sizeof(char) * 500);
                    memset(path, 0, sizeof(char) * 500);
                    if ((a = recv(sockfd, path, 500, 0)) > 0) {
                        //printf("path = %s\n", path);
                        FILE *output = fopen(path, "w+");
                        while ((a = recv(sockfd, buffer, 3500, 0))  >0) {
                            fputs(buffer, output);
                            //printf("%s", buffer);
                            memset(buffer, 0, 4000);
                        }
                        fclose(output);
                    }
                    free(path);
                    close(sockfd);
                    exit(0);
                }
                if (strncmp(buffer, "3", 1) == 0) {
                    close(listen_sockfd);
                    memset(buffer, 0, 4000);
                    int num = send(sockfd, "ok3", 3, 0);
                   // printf("num = %d\n", num);
                    char *path = (char *)malloc(sizeof(char) * 1500);
                    memset(path, 0, 1500);
                    if ((a = recv(sockfd, path, 1500, 0)) > 0) {
                        printf("path = %s\n", path);
                        FILE *output = fopen(path, "w");
                        while ((a = recv(sockfd, buffer, 3500, 0)) > 0) {
                            fputs(buffer, output);
                            //printf("%s", buffer);
                            memset(buffer, 0, 4000);
                        }
                        fclose(output);
                    }
                    free(path);
                    close(sockfd);
                    exit(0);
                } 
                close(sockfd);
                exit(0);
            }
            close(sockfd);
        }
        close(listen_sockfd);
    } else {
        exit(0);
    }    
    return 0;
}



    
