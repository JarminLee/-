/*************************************************************************
	> File Name: IPtest.c
	> Author:李嘉明 
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月17日 星期六 10时10分01秒
 ************************************************************************/

#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include "head.h"

int main()

{

    char buff[20];
    struct hostent * hostaddr;
    struct in_addr addr;

     gethostname(buff, sizeof(buff) );  //获取本机名
     printf("hostname=%s\n",buff);
     hostaddr=gethostbyname(buff);   //获取本机ip地址
     memcpy(&addr.s_addr,hostaddr->h_addr_list[0],sizeof(addr.s_addr));
     strcpy(buff,inet_ntoa(addr));
      buff[15]=0;
     fprintf(stderr,"local ip addres=%s\n",buff);
  }
