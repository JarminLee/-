/*************************************************************************
	> File Name: client.c
	> Author:李嘉明
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月06日 星期二 17时37分25秒
 ************************************************************************/

#include "head.h"

int main() {
    int ctrl_sock = socket_create(CTRL_PORT);

    //receive CPU1
    char buffer[50] = {0};
    
    
    while (1) { 
    int num = recv(ctrl_sock, buffer, 40, 0);
    //printf("signal1 : %s \n", buffer);
    
    //CPU
    if (strcmp(buffer, CPU1) == 0) {
        //send CPU2 and build data sock
        send(ctrl_sock, CPU2, strlen(CPU2), 0);
        int data_sock = socket_create(DATA_PORT1);
        recv(data_sock, buffer, 40, 0);
        // receive CPU3 ans send cpu.log
        if (strcmp(buffer, CPU3) == 0) {
            printf("Has received CPU3 : %s\n", CPU3);
            FILE *fp = fopen("CPU.log", "r");
            while (fgets(buffer, 100, fp) != NULL) {
                send(data_sock, buffer, strlen(buffer), 0);
                //memset(buffer, 0, sizeof(buffer));
                printf("send : %s\n", buffer);
            }
            printf("Client send cpu.log over!\n\n");
            fclose(fp);
            close(data_sock);
        }
        sleep(2);
    }

    //receive MEM1
    memset(buffer, 0, sizeof(buffer));
    num = recv(ctrl_sock, buffer, 40, 0);
    //printf("signal2 : %s\n", buffer);

    //MEM
    if (strcmp(buffer, MEM1) == 0) {
        //send MEM2 and build data sock
        send(ctrl_sock, MEM2, strlen(MEM2), 0);
        int data_sock = socket_create(DATA_PORT1);
        recv(data_sock, buffer, 40, 0);
        // receive MEM3 ans send MEM.log
        if (strcmp(buffer, MEM3) == 0) {
            printf("Has received MEM3 : %s\n", MEM3);
            FILE *fp = fopen("Memory.log", "r");
            while (fgets(buffer, 100, fp) != NULL) {
                send(data_sock, buffer, strlen(buffer), 0);
                //memset(buffer, 0, sizeof(buffer));
                printf("send : %s\n", buffer);
            }
            printf("Client send MEM.log over!\n\n");
            fclose(fp);
            close(data_sock);
        }
        sleep(2);
    }


    //receive DISK1
    memset(buffer, 0, sizeof(buffer));
    num = recv(ctrl_sock, buffer, 40, 0);
    //printf("signal3 : %s\n", buffer);

    //DISK
    if (strcmp(buffer, DISK1) == 0) {
        //send DISK2 and build data sock
        send(ctrl_sock, DISK2, strlen(DISK2), 0);
        int data_sock = socket_create(DATA_PORT1);
        recv(data_sock, buffer, 40, 0);
        // receive DISK3 ans send DISK.log
        if (strcmp(buffer, DISK3) == 0) {
            printf("Has received DISK3 : %s\n", DISK3);
            FILE *fp = fopen("Disk.log", "r");
            while (fgets(buffer, 100, fp) != NULL) {
                send(data_sock, buffer, strlen(buffer), 0);
                //memset(buffer, 0, sizeof(buffer));
                printf("send : %s\n", buffer);
            }
            printf("Client send disk.log over!\n\n");
            fclose(fp);
            close(data_sock);
        }
        sleep(2);
    }
}
  /*
  //MEM
  memset(buff,0,sizeof(buff));
  num = recv(ctrl_sock,buff,40,0);
  if (strcmp(buff,MEM1) == 0){
     printf(" **** mem\n");
     //send CPU2 and build data sock
     send(ctrl_sock,MEM2,strlen(MEM2),0);
     int data_sock = socket_create(DATA_PORT2);
     recv(data_sock,buff,40,0);
     // rece CPU3 ans send cpu.log
     if (strcmp(buff,MEM3) == 0){
        FILE *fp = fopen("mem.log", "r");
        while (fgets(buff,100,fp) != NULL){
        send(data_sock,buff,strlen(buff),0);
        // printf("send : %s\n",buff);
      }
      printf("Cilent send mem.log over !\n");
      fclose(fp); 
      close(data_sock);
    } 
    sleep(2); 
  }

  //DISK 
  memset(buff,0,sizeof(buff));
  num = recv(ctrl_sock,buff,40,0);
  if (strcmp(buff,DISK1) == 0){
     //send CPU2 and build data sock
     send(ctrl_sock,DISK2,strlen(DISK2),0);
     int data_sock = socket_create(DATA_PORT3);
     recv(data_sock,buff,40,0);
     // rece CPU3 ans send cpu.log
     if (strcmp(buff,DISK3) == 0){
     FILE *fp = fopen("disk.log", "r");
     while (fgets(buff,100,fp) != NULL){
          send(data_sock,buff,strlen(buff),0);
          // printf("send : %s\n",buff);
        }
        printf("Cilent send disk.log over !\n");
        fclose(fp); 
        close(data_sock);
      } 
     sleep(2); 
    }
    */
  return 0;
}
