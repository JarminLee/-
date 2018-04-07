/*************************************************************************
	> File Name: client.c
	> Author:李嘉明 
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月06日 星期二 17时37分25秒
 ************************************************************************/

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

    fflush(stdout);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr))) {
        return -1;
    }
    return sockfd;
}

int main() {
    int port = 5555;
    char host[] = {"192.168.1.196"};
    int sockfd = socket_connect(port, host);
    char *buffer = (char *)malloc(sizeof(char) * 1997);
    FILE *fp;
    char *fname = "out";
    char order[10];
    scanf("%s", order);
    system(strcat(order, " -a > out"));
    //system("ll -a > out");
    fp = fopen(fname, "r");
    fseek(fp, 0, SEEK_END);
    rewind(fp);
    char txt[1000];
    while ((fgets(txt, 1000, fp)) != NULL) {
        strcat(buffer, txt);
    }
    
    fclose(fp);
    int size = strlen(buffer);
    send(sockfd, buffer, sizeof(char) * size, 0);
    memset(buffer, 0, strlen(buffer));
    free(buffer);
    return 0;
}
