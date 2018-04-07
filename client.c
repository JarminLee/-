/*************************************************************************
	> File Name: client.c
	> Author: 史桢港 
	> Mail: 1031091451@qq.com
	> Created Time: 2018年03月06日 星期二 22时04分51秒
 ************************************************************************/

#include <stdio.h>
#include "head.h"

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
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr))) {
        return -1;
    }
    return sockfd;
}

int main() {
    int sockfd, port, op;
    int a = 0;
    char *ip = (char *)malloc(sizeof(char) * 25);
    printf("please input port\n");
    scanf("%d", &port);
    printf("please input ip\n");
    scanf("%s", ip);
    printf("please input op, op == 1 means seadind words, op == 2, means sending files, op == 3,means seading minning\n");
    char *buffer = (char *)calloc(5500, sizeof(char));
    char *path = (char *)malloc(sizeof(char) * 500);
    while (~scanf("%d", &op)) {
        switch(op) {
            case 1 : {
                if ((sockfd = socket_connect(port, ip)) < 0) {
                    printf("socket_connect() error\n");
                    break;
                } 
                send(sockfd, "1", 1, 0);
                if ((a = recv(sockfd, buffer, 3, 0)) > 0) {
                    if (strncmp(buffer, "ok1", 3) != 0) {
                        printf("error respect\n");
                        close(sockfd);
                    } else {
                        //printf("%s\n", buffer);
                        memset(buffer, 0, 5500);
                        printf("please input buffer\n");
                        scanf("%s", buffer);
                        int count = send(sockfd, buffer, strlen(buffer), 0);
                        memset(buffer, 0, strlen(buffer));
                        close(sockfd);
                    }
                }
            } break;
            case 2 : {
                if ((sockfd = socket_connect(port, ip)) < 0) {
                    printf("socket_connect() error2\n");
                    break;
                }
                send(sockfd, "2", 1, 0);
                if ((a = recv(sockfd, buffer, 3, 0)) > 0) {
                    if (strncmp(buffer, "ok2", 3) == 0) {
                        //printf("%s\n", buffer);
                        memset(buffer, 0, 5500);
                        printf("please input end path\n");
                        scanf("%s", path);
                        send(sockfd, path, sizeof(path), 0);
                        memset(path, 0, 500);
                        printf("please input the path\n");
                        scanf("%s", path);
                        FILE *input = fopen(path, "r");
                        while (fgets(buffer, 5000, input) != NULL) {
                            int size = strlen(buffer);
                            send(sockfd, buffer, sizeof(char) * size, 0);
                            memset(buffer, 0, 5500);
                        }
                        memset(path, 0, 500);
                        close(sockfd);
                    } else {
                        printf("error respect2\n");
                        close(sockfd);
                    }
                }
            } break;
            case 3 : {
                int pid[3], i;
                char str[3][30] = {"ls -al", "ps -ef", "whoami"};
                for (i = 0; i <= 2; ++i) {
                    if ((pid[i] = fork()) < 0) {
                        printf("fork() error\n");
                    }
                    if (pid[i] == 0) break;
                }
                if (i == 3) {
                    exit(0);
                }
                if (pid[i] == 0) {
                    while (1) {
                        if ((sockfd = socket_connect(port, ip)) < 0) {
                            printf("socket_connect() error\n");
                            break;
                        }
                        send(sockfd, "3", 1, 0);
                        if ((a = recv(sockfd, buffer, 3, 0)) > 0) {
                            if (strncmp(buffer, "ok3", 3) != 0) {
                                printf("error respect %d\n", i);
                                close(sockfd);
                                break;
                            }
                            memset(buffer, 0, 5500);
                            memset(path, 0, 500);
                            printf("%s", str[i]);
                            sprintf(path, "%s", "./");
                            sprintf(path + strlen(path), "%c", '0' + i);
                            sprintf(path + strlen(path), "%s", ".log");
                            //printf("path = %s\n", path);
                            send(sockfd, path, strlen(path), 0);
                            memset(path, 0, 500);
                            FILE *input = popen(str[i], "r");
                            while ((fgets(buffer, 5000, input)) != NULL) {
                                int size = strlen(buffer);
                                send(sockfd, buffer, size, 0);
                                memset(buffer, 0, 5500);
                            }
                            close(sockfd);
                        }
                        sleep(10);      
                    }
                } 
            } break;
            default : break;
        }
    }
    free(ip);
    free(buffer);
    return 0;
}
