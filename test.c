/*************************************************************************
	> File Name: test.c
	> Author:李嘉明
	> Mail: 287438128@qq.com
	> Created Time: 2018年03月09日 星期五 18时14分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DEBUG
#ifdef DEBUG
#define DBG(s, va_arg...) {\
    printf("FILE:%s LINE:[%d] return = ", __FILE__, __LINE__);\
    printf(s, ##va_arg);\
 }
#else
#define DBG(s, va_arg...)
#endif

int get_conf_value(char* pathname, char* key_name, char *value) {

	FILE *fp = NULL;
	char *line = NULL, *substr = NULL;
	size_t len = 0, tmplen = 0;
	ssize_t read;
	//memset(value, 0, sizeof(char)*MAX_SIZE);

	if ( key_name == NULL || value == NULL) {
		DBG("paramer is invaild!n");
		exit(-1);
	}

	fp = fopen(pathname,"r");
	if (fp == NULL) {
		DBG("Open config file error!n");
		exit(-1);
	}

	while (( read = getline(&line, &len,fp)) != -1) {
		substr = strstr(line, key_name);
		if (substr == NULL)
			continue;
		else {
			tmplen = strlen(key_name);
			if (line[tmplen] == '=') {
				strncpy(value, &line[tmplen + 1], (int)read - tmplen + 1);
				tmplen = strlen(value);
				*(value + tmplen - 1) = '';
				break;
			}
			else {
				DBG("Maybe there is something wrong with config file!n");
				continue;
			}
		}
	}

	if (substr == NULL) {
		DBG("%s not found in config file!n", key_name);
		fclose(fp);
		exit(-1);
	}

	DBG("%s=%sn", key_name, value);
	free(line);
	fclose(fp);
	return 0;
}


char *get_information(char *fname, char *instruction) {
    FILE *fp = fopen(fname, "r");
    char *buffer = (char *)malloc(sizeof(char) * 100);
    memset(buffer, 0, 100);
    int whichLine = 0, currentIndex = 0;
    while (!feof(fp)) {
        int count = 0;
        if (currentIndex == whichLine) {
            fgets(buffer, 100, fp);
            printf("%s", buffer);
            return instruction;
        }
        whichLine++;
        fgets(buffer, 100, fp);
        currentIndex++;
    }
    fclose(fp);
    return instruction;
}
int main() {
   // DBG("%d", 1);
    int i;
    while (~scanf("%d", &i))
    get_information("config", "PROT1", i);
    return 0;
}



