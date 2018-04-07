/*************************************************************************
	> File Name: test.c
	> Author:李嘉明
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月09日 星期五 18时14分04秒
 ************************************************************************/

#include "head.h"


void server(char *ip) {
    int ctrl_sock = socket_connect(CTRL_PORT, ip);
    char buffer[50] = {0};
    char buffer2[50] = {0};
    char buffer3[50] = {0};
    //for (int i = 0; i < 10; i++) {
    while (1) {
    char *info = {"Has Connected!\n"};
    send(ctrl_sock, info, strlen(info), 0);
    struct sockaddr_in sa;
    int len = sizeof(sa);
    char ip_str[15] = {0};
    if (!getpeername(ctrl_sock, (struct sockaddr *)&sa, &len)) {
            printf("the IP: %s\n", inet_ntoa(sa.sin_addr));
            
            strcpy(ip_str, inet_ntoa(sa.sin_addr));     
    }
     
    //CPU
    //send CPU1
    send(ctrl_sock, CPU1, strlen(CPU1), 0);
    //printf("CPU1 : %s\n", CPU1);
    //receive CPU2
    char buffer[50] = {0};//字符串初始化问题！！！！！
    recv(ctrl_sock, buffer, 40, 0);
    //printf("ans : %s\n", buffer);
    if (strcmp(buffer, CPU2) == 0) {
        //printf("ans : %s\n", CPU2);
        int cpu_sock = socket_connect(DATA_PORT1, ip);
        //send CPU3
        send(cpu_sock, CPU3, strlen(CPU3), 0);
        //printf("The message of cpu.log\n");
        FILE *fp = fopen("CPU.log", "a+");
        while (recv(cpu_sock, buffer, 40, 0) > 0) {
            printf("%s", buffer);
            fprintf(fp, buffer);
            //memset(buffer, 0, sizeof(buffer));
            /*
            if (ip_str[11] == '0') {
                    fp = fopen("0.log", "a+");
                    fprintf(fp, buffer);
                    printf("Write CPU OK\n");
                    memset(buffer, 0, sizeof(buffer));
                    fclose(fp);
            }*/
        }
        fclose(fp);

        close(cpu_sock);
    }
    
    //MEM
    //send MEM1
     
    send(ctrl_sock, MEM1, strlen(MEM1), 0);
    //printf("MEM1 : %s\n", MEM1);
    //receive MEM
    //memset(buffer, 0, sizeof(buffer));//字符串初始化问题！！！！！
    recv(ctrl_sock, buffer2, 40, 0);
    //printf("ans : %s\n", buffer);
    if (strcmp(buffer2, MEM2) == 0) {
        //printf("ans : %s\n", MEM2);
        int mem_sock = socket_connect(DATA_PORT2, ip);
        //send MEM3
        send(mem_sock, MEM3, strlen(MEM3), 0);
        FILE *fp = fopen("Mem.log", "a+");
        //printf("The message of memory.log\n");
        while (recv(mem_sock, buffer2, 40, 0) > 0) {
            printf("%s", buffer2);
            //memset(buffer2, 0, sizeof(buffer2));
            fprintf(fp, buffer2);
        }
        fclose(fp);
        close(mem_sock);
    }
    
    //DISK
    //send DISK1
    memset(buffer3, 0, sizeof(buffer3));//字符串初始化问题！！！！！
    send(ctrl_sock, DISK1, strlen(DISK1), 0);
    //printf("DISK1 : %s\n", DISK1);
    //receive MEM
    // memset(buffer, 0, sizeof(buffer));//字符串初始化问题！！！！！
    recv(ctrl_sock, buffer3, 40, 0);
    //printf("ans : %s\n", buffer3);
    if (strcmp(buffer3, DISK2) == 0) {
        //printf("ans : %s\n", DISK2);
        int disk_sock = socket_connect(DATA_PORT3, ip);
        //send DISK3
        send(disk_sock, DISK3, strlen(DISK3), 0);
        FILE *fp = fopen("Disk.log", "a+");
        //printf("The message of disk.log\n");
        while (recv(disk_sock, buffer3, 40, 0) > 0) {
            printf("%s", buffer3);
            //memset(buffer3, 0, sizeof(buffer3));
            fprintf(fp, buffer);
        }
        fclose(fp);
        close(disk_sock);
    }

}
}

int main() {
    //server(IP);
   
    int pid, count = 0;
    for (int i = 0; i < 10; i++) {
        if ((pid = fork()) < 0) {
            printf("fork() error\n");
        }
        count++;
        if (pid == 0) break;
    }
   /* 
    if (pid == fork()) { 
        exit(0);
    }
     */
    while (1) {
    switch (count) {
        case 1: 
              server(ip[0]);
        case 2:
              server(ip[1]);
        case 3:
              server(ip[2]);
        case 4:
              server(ip[3]);
        case 5:
              server(ip[4]);
        case 6:
              server(ip[5]);
        case 7:
              server(ip[6]);
        case 8:
              server(ip[7]);
        case 9:
              server(ip[8]);
        case 10:
               server(ip[9]);
               
    }           
    }    

return 0;
}

