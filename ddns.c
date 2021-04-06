#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
int main(void)
{
	char ip[32] = {0};
	char http[32] = {"http://"};
	char ip_port[] = ":8088";
	char cmd[64] = {0};
	system("mode 64,16");
	system("title Parsing IP address, please wait...");
	printf("Parsing IP address, please wait...\n");
	system("ping -4 xlgk.gnway.cc >temp_ip.txt");
	FILE *fp = fopen("temp_ip.txt", "r");
	if (fp == NULL) {
		perror("temp_ip.txt");
		exit(1);
	}
	
	//获取ip
	while (fgetc(fp) != '[')
		;
	int ch;
	int i = 0;
	while ((ch = fgetc(fp)) != ']') 
	{
		ip[i] = ch;
		i++;
	}
	ip[i] = '\0';
	fclose(fp);
	
	//连接网址
	strcat(cmd, "start ");
	strcat(cmd, http);
	strcat(cmd, ip);
	strcat(cmd, ip_port);
	
	//打开网站
	printf(cmd);
	system(cmd);
	
	//删除临时文件
	system("del/q temp_ip.txt");
	system("exit");
	return 0;
}