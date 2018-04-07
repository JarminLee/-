/*************************************************************************
	> File Name: client.c
	> Author:李嘉明
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月06日 星期二 17时37分25秒
 ************************************************************************/

#include "head.h"

int countCPU = 0, countMem = 0, countDisk = 0;
int countSys = 0, countUser = 0;

void CPU() {
    char buffer[1000] = {0};
    char buff[100] = {0};
    memset(buff, 0 , sizeof(buff));
    //int countCPU = 0;
    //CPU
        char *instruction1 = {"bash CPUtest.sh"};
        FILE *output1 = popen(instruction1, "r"), *fp1;
            fgets(buff, sizeof(buff), output1);
            strcat(buffer, buff);
            printf("%s", buff);
            memset(buff, 0, sizeof(buff));
        
        sleep(1);
        countCPU++;
        //printf("%d\n", countCPU);
        if (countCPU % 6 == 0) {
            fp1 = fopen("CPU.log", "a+");
            fprintf(fp1, "%s",  buffer);
            printf("Write CPU OK\n");
            memset(buffer, 0, sizeof(buffer));
            fclose(fp1);
        
        } 
}

void Memory() {
    char buffer[1000] = {0};
    char buff[100] = {0};
    memset(buff, 0 , sizeof(buff));
    //int countMem = 0;
 //MEM
        char *instruction2 = {"bash MEMtest.sh"};
        FILE *output2 = popen(instruction2, "r"), *fp2;
        while (fgets(buff, sizeof(buff), output2)) {
            strcat(buffer, buff);
            printf("%s", buff);
            memset(buff, 0, sizeof(buff));
        }
        sleep(1);
        countMem++;
        if (countMem % 6 == 0) {
            fp2 = fopen("Mem.log", "a+");
            fprintf(fp2, "%s", buffer);
            printf("Write Mem OK\n");
            memset(buffer, 0, sizeof(buffer));
            fclose(fp2);
        }

}

void Disk() {
    char buffer[1000] = {0};
    char buff[100] = {0};
    memset(buff, 0 , sizeof(buff));
    //int countDisk = 0;
     //Disk
        char *instruction3 = {"bash DISKtest.sh"};
        FILE *output3 = popen(instruction3, "r"), *fp3;
        while (fgets(buff, sizeof(buff), output3)) {
            strcat(buffer, buff);
            printf("%s", buff);
            memset(buff, 0, sizeof(buff));
        }
        sleep(1);
        countDisk++;
        if (countDisk % 6 == 0) {
            fp3 = fopen("Disk.log", "a+");
            fprintf(fp3, "%s", buffer);
            printf("Write Disk OK\n");
            memset(buffer, 0, sizeof(buffer));
            fclose(fp3);
        
    }
}

void System() {
    char buffer[1000] = {0};
    char buff[100] = {0};
    memset(buff, 0 , sizeof(buff));
    //int countCPU = 0;
    //CPU
        char *instruction1 = {"bash System.sh"};
        FILE *output1 = popen(instruction1, "r"), *fp1;
            fgets(buff, sizeof(buff), output1);
            strcat(buffer, buff);
            printf("%s", buff);
            memset(buff, 0, sizeof(buff));
        
        sleep(1);
        countSys++;
        //printf("%d\n", countCPU);
        if (countSys % 6 == 0) {
            fp1 = fopen("System.log", "a+");
            fprintf(fp1, "%s",  buffer);
            printf("Write System OK\n");
            memset(buffer, 0, sizeof(buffer));
            fclose(fp1);
        
        } 
}

void User() {
    char buffer[1000] = {0};
    char buff[100] = {0};
    memset(buff, 0 , sizeof(buff));
    //int countCPU = 0;
    //CPU
        char *instruction1 = {"bash User.sh"};
        FILE *output1 = popen(instruction1, "r"), *fp1;
            fgets(buff, sizeof(buff), output1);
            strcat(buffer, buff);
            printf("%s", buff);
            memset(buff, 0, sizeof(buff));
        
        sleep(1);
        countUser++;
        //printf("%d\n", countCPU);
        if (countUser % 6 == 0) {
            fp1 = fopen("User.log", "a+");
            fprintf(fp1, "%s",  buffer);
            printf("Write User OK\n");
            memset(buffer, 0, sizeof(buffer));
            fclose(fp1);
        
        } 

}

int main() {
     
    int pid, count = 0;
    for (int i = 0; i < 2; i++) {
        if ((pid = fork()) < 0) {
            printf("fork() error\n");
        }
        count++;
        if (pid == 0) break;
    }

    if (pid != 0) {
        return 0;
    }
    
    if (count == 1) {
        while (1) {
            //CPU();
            //Memory();
            //Disk();
            System();
            User();
        }
    }
     
    
    if (count == 2)  {
    int ctrl_sock = socket_create(CTRL_PORT);
    while (1) {
    
    //receive CPU1
    char buffer[50] = {0};
    int num = recv(ctrl_sock, buffer, 40, 0);
     
    //CPU
    if (strcmp(buffer, CPU1) == 0) {
        //send CPU2 and build data sock
        send(ctrl_sock, CPU2, strlen(CPU2), 0);
        int data_sock = socket_create(DATA_PORT1);
        recv(data_sock, buffer, 50, 0);
        // receive CPU3 ans send cpu.log
        if (strcmp(buffer, CPU3) == 0) {
            printf("Has received CPU3 : %s\n", CPU3);
            FILE *fp = fopen("CPU.log", "r");
            flock(fp->_fileno, LOCK_EX);
            while (fgets(buffer, 50, fp) != NULL) {
                send(data_sock, buffer, strlen(buffer), 0);
                //memset(buffer, 0, sizeof(buffer));
                printf("send : %s\n", buffer);
                
            }
            printf("Client send cpu.log over!\n\n");
            fclose(fp);
            flock(fp->_fileno, LOCK_UN);
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
        int data_sock = socket_create(DATA_PORT2);
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
        int data_sock = socket_create(DATA_PORT3);
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
    }
return 0;
       
        
}

