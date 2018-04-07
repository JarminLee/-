/*************************************************************************
	> File Name: client.c
	> Author:李嘉明 
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月06日 星期二 17时37分25秒
 ************************************************************************/

#include "head.h"
/*
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
*/
int main() {
    int port = 5555;
    char host[] = {"192.168.1.110"};
    int sockfd = socket_connect(port, host);
    char *buffer = (char *)malloc(sizeof(char) * 1997);

    /*FILE *fp;
    char *fname = "in";
    fp = fopen(fname, "r");
    fseek(fp, 0, SEEK_END);
    rewind(fp);
    char txt[1000];
    while ((fgets(txt, 1000, fp)) != NULL) {
        strcat(buffer, txt);
    }*/

    //int size = strlen(buffer);
    char op[1];
    while (~scanf("%s", op)) {
        if (strcmp(op, "1") == 0) {
            send(sockfd, op, sizeof(char) * 1, 0);
            memset(op, 0, 1);
            char chuan[10];
            scanf("%s", chuan);
            int size = strlen(chuan);
            send(sockfd, chuan, sizeof(char) * size, 0);
            memset(chuan, 0, strlen(buffer));
        }
        if (strcmp(op, "2") == 0) {
            FILE *fp;
            send(sockfd, op, sizeof(char) * 1, 0);
            memset(op, 0, 1);
            printf("Has sent op!\n");
            char *fname = (char *)malloc(sizeof(char) * 10);
            scanf("%s", fname);
            send(sockfd, fname, sizeof(char) * strlen(fname), 0);
            printf("Has sent file name !\n");
            //memset(fname, 0, strlen(fname));
            
            fp = fopen(fname, "r");
            fseek(fp, 0, SEEK_END);
            rewind(fp);
            char txt[1000];
            while ((fgets(txt, 1000, fp)) != NULL) {
                strcat(buffer, txt);
            }
            memset(fname, 0, strlen(fname));
            fclose(fp);
            int size = strlen(buffer);
            send(sockfd, buffer, sizeof(char) * size, 0);
            memset(buffer, 0, strlen(buffer));
            
        }
    }
    //fclose(fp);
    //int size = strlen(buffer);
    //send(sockfd, buffer, sizeof(char) * size, 0);
    //memset(buffer, 0, strlen(buffer));
    free(buffer);
    return 0;
}
