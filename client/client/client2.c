/*************************************************************************
	> File Name: client.c
	> Author:李嘉明
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月06日 星期二 17时37分25秒
 ************************************************************************/

#include "head.h"

int socket_connect(int port, char *host)
{
    int sockfd;
    struct sockaddr_in dest_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket() error");
        return -1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    dest_addr.sin_addr.s_addr = inet_addr(host);

    fflush(stdout);
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)))
    {
        return -1;
    }
    return sockfd;
}

int main()
{
    int port = 5555;
    char host[] = {"192.168.1.196"};
    int sockfd = socket_connect(port, host);
    char *buffer = (char *)malloc(sizeof(char) * 1997);
    int pid[3], i, a;
    char str[3][30] = {"ls\n", "ps\n", "last\n"};
    for (i = 0; i <= 2; ++i)
    {
        if ((pid[i] = fork()) < 0)
        {
            printf("fork() error\n");
        }
        if (pid[i] == 0) break;
    }
    if (i == 3)
    {
        exit(0);
    }
    if (pid[i] == 0)
    {
        while (1)
        {
            /*
            FILE *fp;
            char *fname = "out";
            char order[10];
            //scanf("%s", order);
            system(strcat("ls", " -a > out"));
            //system("ll -a > out");
            fp = fopen(fname, "r");
            fseek(fp, 0, SEEK_END);
            rewind(fp);
            char txt[1000000];
            while ((fgets(txt, 1000000, fp)) != NULL)
            {
                strcat(buffer, txt);
            }

            fclose(fp);
            */
            strcpy(buffer, str[i]);
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, strlen(buffer));
            sleep(5);
        }
        /*
         strcpy(buffer, str[i]);
         while (1)
         {
             if ((sockfd = socket_connect(port, host)) < 0)
             {
                 printf("socket_connect() error\n");
                 break;
             }
             //send(sockfd, "3", 1, 0);

             if ((a = recv(sockfd, buffer, 3, 0)) > 0)
             {
                 send(sockfd, buffer, strlen(buffer), 0);
                 memset(buffer, 0, strlen(buffer));

                 if (strncmp(buffer, "ok3", 3) != 0)
                 {
                     printf("error respect %d\n", i);
                     close(sockfd);
                     break;
                 }

                 //memset(buffer, 0, 5500);
                 //memset(path, 0, 500);

                 char path[500];
                 printf("%s", str[i]);
                 sprintf(path, "%s", "./");
                 sprintf(path + strlen(path), "%c", '0' + i);
                 sprintf(path + strlen(path), "%s", ".log");
                 //printf("path = %s\n", path);
                 send(sockfd, path, strlen(path), 0);
                 memset(path, 0, 500);
                 FILE *input = popen(str[i], "r");
                 while ((fgets(buffer, 5000, input)) != NULL)
                 {
                     int size = strlen(buffer);
                     send(sockfd, buffer, size, 0);
                     memset(buffer, 0, 5500);
                 }
                 close(sockfd);
             }
             sleep(10);
         }
         */
    }
    return 0;
}
