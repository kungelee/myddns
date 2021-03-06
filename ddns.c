/******************************************
* 动态获取ip地址信息
* 前提需要公网IP地址（24h/48h/7day/30day更新)
* 可以联系电信更改(如安装视频，ERP等）
* 获取IP并拼接网址后，再利用start命令打开网址
* 2021年4月8日3:20:52 by jeff lee
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
int main(void)
{
	char ip[32]    = {0};          /*IP地址*/
	char http[]    = {"http://"};  /*httt类型*/
	char ip_port[] = {":8088"};    /*端口号*/
	char cmd[64]   = {0};          /*拼接网址buf*/
	
	system("mode 64,16");
	system("title Parsing IP address, please wait...");
	printf("Parsing IP address, please wait...\n");
	system("ping -4 xlgk.gnway.cc >temp_ip.txt");
	FILE *fp = fopen("temp_ip.txt", "r");
	if (fp == NULL) {
		perror("temp_ip.txt");
		exit(1);
	}
	
	/*获取ip*/
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
	
	/*拼接网址*/
	strcat(cmd, "start ");
	strcat(cmd, http);
	strcat(cmd, ip);
	strcat(cmd, ip_port);
	
	/*打开网站*/
	printf(cmd);
	system(cmd);
	
	/*删除临时文件*/
	system("del/q temp_ip.txt");
	system("exit");
	return 0;
}
