#include <stdio.h>
#include "my.h"

int main() {
    int count = 0;
    int PID;
    for (int i = 0; i < 11; i++) {
        count++;
        PID = fork();
        if (PID == 0) break;
    }
    if (PID != 0) return 0;
    
    if (count == 1) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi1_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi1_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/1/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("1.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi1_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/1/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("1.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi1_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/1/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("1.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi1_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/1/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("1.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi1_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/1/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("1.user close done\n");
        }
        close(sockfd);
    }


    else if (count == 2) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi2_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi2_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/2/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("2.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi2_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/2/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("2.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi2_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/2/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("2.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi2_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/2/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("2.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi2_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/2/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("2.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 3) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi3_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi3_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/3/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("3.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi3_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/3/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("3.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi3_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/3/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("3.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi3_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/3/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("3.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi3_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/3/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("3.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 4) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi4_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi4_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/4/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("4.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi4_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/4/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("4.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi4_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/4/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("4.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi4_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/4/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("4.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi4_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/4/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("4.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 5) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi5_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi5_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/5/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("5.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi5_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/5/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("5.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi5_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/5/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("5.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi5_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/5/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("5.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi5_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/5/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("5.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 6) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi6_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi6_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/6/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("6.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi6_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/6/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("6.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi6_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/6/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("6.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi6_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/6/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("6.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi6_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/6/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("6.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 7) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi7_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi7_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/7/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("7.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi7_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/7/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("7.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi7_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/7/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("7.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi7_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/7/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("7.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi7_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/7/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("7.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 8) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi8_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi8_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/8/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("8.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi8_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/8/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("8.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi8_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/8/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("8.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi8_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/8/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("8.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi8_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/8/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("8.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 9) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi9_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi9_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/9/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("9.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi9_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/9/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("9.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi9_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/9/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("9.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi9_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/9/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("9.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi9_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/9/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("9.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 10) {
        // 1 socket()
        int sockfd;
        sockfd = create_socket();
        // 2 connect()
        begin_connect(sockfd, link_con_port, pi10_host);
        // 3 send();
        char *buffer = (char *)calloc(2000, sizeof(char));
    
        // send_cpu
        send(sockfd, send_cpu, strlen(send_cpu), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_cpu_socketfd = create_socket();
            begin_connect(my_cpu_socketfd, link_cpu_port, pi10_host);
            FILE *save_cpu = fopen("/home/quan/linux/TCP项目/10/save_cpu", "a+");
            while(recv(my_cpu_socketfd, buffer, 2000, 0)) {
                fprintf(save_cpu, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_cpu);
            close(my_cpu_socketfd);
            p("10.cpu close done\n");
        }
        
        // send_mem
        send(sockfd, send_mem, strlen(send_mem), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_mem_socketfd = create_socket();
            begin_connect(my_mem_socketfd, link_mem_port, pi10_host);
            FILE *save_mem = fopen("/home/quan/linux/TCP项目/10/save_mem", "a+");
            while(recv(my_mem_socketfd, buffer, 2000, 0)) {
                fprintf(save_mem, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_mem);
            close(my_mem_socketfd);
            p("10.mem close done\n");
        }

        // send_disk
        send(sockfd, send_disk, strlen(send_disk), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_disk_socketfd = create_socket();
            begin_connect(my_disk_socketfd, link_disk_port, pi10_host);
            FILE *save_disk = fopen("/home/quan/linux/TCP项目/10/save_disk", "a+");
            while(recv(my_disk_socketfd, buffer, 2000, 0)) {
                fprintf(save_disk, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_disk);
            close(my_disk_socketfd);
            p("10.disk close done\n");
        }
        // send_sys
        send(sockfd, send_sys, strlen(send_sys), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_sys_socketfd = create_socket();
            begin_connect(my_sys_socketfd, link_sys_port, pi10_host);
            FILE *save_sys = fopen("/home/quan/linux/TCP项目/10/save_sys", "a+");
            while(recv(my_sys_socketfd, buffer, 2000, 0)) {
                fprintf(save_sys, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_sys);
            close(my_sys_socketfd);
            p("10.sys close done\n");
        }
        // send_user
        send(sockfd, send_user, strlen(send_user), 0);
        memset(buffer, 0, 2000);
        recv(sockfd, buffer, 2000, 0);
        p("receive = %s\n", buffer);
        if(stringtoint(buffer) == yes) {
            sleep(0.5);
            memset(buffer, 0, 2000);
            int my_user_socketfd = create_socket();
            begin_connect(my_user_socketfd, link_user_port, pi10_host);
            FILE *save_user = fopen("/home/quan/linux/TCP项目/10/save_user", "a+");
            while(recv(my_user_socketfd, buffer, 2000, 0)) {
                fprintf(save_user, "%s", buffer);
                memset(buffer, 0, 2000);
            }
            fclose(save_user);
            close(my_user_socketfd);
            p("10.user close done\n");
        }
        close(sockfd);
    }
    else if (count == 11) {
        while (1) {
            // 1 socket() 
            int my_sockfd = create_socket();
            // 2 set_socket()
            set_socket(my_sockfd);
            // 3 bind()
            begin_bind(my_sockfd, share_warning_port);
            // 4 listen()
            begin_listen(my_sockfd);
            // 5 accept
            int rec_sockfd;
            struct sockaddr_in client_message;
            socklen_t len = sizeof(struct sockaddr_in);
            while (1) {
                rec_sockfd = begin_accept(my_sockfd, &client_message, &len);
                getpeername(rec_sockfd, (struct sockaddr *)&client_message, &len);
                char rec_addr[50] = {'\0'};
                int rec_port;
                inet_ntop(AF_INET, (void *)&client_message.sin_addr, rec_addr, 49);
                rec_port = ntohs(client_message.sin_port);
                p ("waring rec_port = %d\n", rec_port);
                p ("waring rec_addr = %s\n", rec_addr);
                //接收字符串
                char *rec_buf = (char *) calloc (2000, sizeof (char));
                FILE *f_warning = fopen("/home/quan/linux/TCP项目/warning/warning.log", "a+");
                while (recv(rec_sockfd, rec_buf, 2000, 0)) {
                    fprintf(f_warning, "%s", rec_buf);
                }
                fclose(f_warning);
                free(rec_buf);
            }
        }
    } 
    return 0;
}
