/*************************************************************************
	> File Name: test.c
	> Author:李嘉明
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月09日 星期五 18时14分04秒
 ************************************************************************/

#include "head.h"


int main() {
   int ctrl_sock = socket_connect(CTRL_PORT, IP);

    //CPU
    //send CPU1
    send(ctrl_sock, CPU1, strlen(CPU1), 0);
    printf("CPU1 : %s\n", CPU1);
    //receive CPU2
    char buffer[50] = {0};//字符串初始化问题！！！！！
    recv(ctrl_sock, buffer, 40, 0);
    printf("ans : %s\n", buffer);
    if (strcmp(buffer, CPU2) == 0) {
        //printf("ans : %s\n", CPU2);
        int cpu_sock = socket_connect(DATA_PORT1, IP);
        //send CPU3
        send(cpu_sock, CPU3, strlen(CPU3), 0);
        printf("The meeage of cpu.log\n");
        while (recv(cpu_sock, buffer, 40, 0) > 0) {
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
        close(cpu_sock);
    }

    //MEM
    //send MEM1
    send(ctrl_sock, MEM1, strlen(MEM1), 0);
    printf("MEM1 : %s\n", MEM1);
    //receive MEM
    memset(buffer, 0, sizeof(buffer));//字符串初始化问题！！！！！
    recv(ctrl_sock, buffer, 40, 0);
    printf("ans : %s\n", buffer);
    if (strcmp(buffer, MEM2) == 0) {
        //printf("ans : %s\n", MEM2);
        int mem_sock = socket_connect(DATA_PORT1, IP);
        //send MEM3
        send(mem_sock, MEM3, strlen(MEM3), 0);
        printf("The message of memory.log\n");
        while (recv(mem_sock, buffer, 40, 0) > 0) {
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
        close(mem_sock);
    }

    //DISK
    //send DISK1
    send(ctrl_sock, DISK1, strlen(DISK1), 0);
    printf("DISK1 : %s\n", DISK1);
    //receive MEM
    memset(buffer, 0, sizeof(buffer));//字符串初始化问题！！！！！
    recv(ctrl_sock, buffer, 40, 0);
    printf("ans : %s\n", buffer);
    if (strcmp(buffer, DISK2) == 0) {
        //printf("ans : %s\n", DISK2);
        int disk_sock = socket_connect(DATA_PORT1, IP);
        //send DISK3
        send(disk_sock, DISK3, strlen(DISK3), 0);
        printf("The message of disk.log\n");
        while (recv(disk_sock, buffer, 40, 0) > 0) {
            printf("%s", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
        close(disk_sock);
    }
    
   /*
   //MEM
   send(ctrl_sock,MEM1,strlen(MEM1),0);
   printf("MEM1 : %s\n",MEM1);
   //receive CPU2
   recv(ctrl_sock,buff,40,0);
   printf("MEM2 : %s\n",MEM2);
   // printf("buff : %s\n",buff);
   if (strcmp(buff,MEM2) == 0) {
      int cpu_sock = socket_connect(DATA_PORT2,IP);
      //send CPU3
      send(cpu_sock,MEM3,strlen(MEM3),0);
      printf("The message of mem.log\n");
      while (recv(cpu_sock,buff,40,0) > 0 ){
          printf("%s", buff);
          memset(buff,0,sizeof(buff));
   }
      close(cpu_sock);
   }
   //DISK
   send(ctrl_sock,DISK1,strlen(DISK1),0);
   //receive CPU2
   recv(ctrl_sock,buff,40,0);
   // printf("buff : %s\n",buff);
   if (strcmp(buff,DISK2) == 0){
   int cpu_sock = socket_connect(DATA_PORT3,IP);
   //send CPU3
   send(cpu_sock,DISK3,strlen(CPU3),0);
   printf("The message of disk.log\n");
   while (recv(cpu_sock,buff,40,0) > 0 ) {
        printf("%s", buff);
        memset(buff,0,sizeof(buff));
   }
      close(cpu_sock);
   }
   close(ctrl_sock);
*/
return 0;

}


