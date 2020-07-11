#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <windows.h>
#include<cstring>
#include<cmath>
#include<algorithm>
char str[15];
int suiji()
{
	int n;
	srand((unsigned)time(NULL));//以时间为种子
	n = rand() % 4+1;//在1~4产生随机数
	return n;
}
void a(int x) {
	if (x==1)
	{
		printf("大傻子");
	}
	if (x == 2)
	{
		printf("帅哥");
	}
	if (x == 3)
	{
		printf("三个大傻子");
	}
	if (x == 4)
	{
		printf("dalao");
	}
	return;
}
void b(int x) {
	if (x == 1)
	{
		printf("去死");
	}
	if (x == 2)
	{
		printf("坐下");
	}
	if (x == 3)
	{
		printf("起立");
	}
	if (x == 4)
	{
		printf("睡觉");
	}
	return;
}
void zhengwen() {
	scanf("%s", str);
	printf("%s", str);
}
int main() {
	printf("baijingren (c) 2005-2019  版权所有，侵权必究\n");
	printf("C:\\Users\\Administrator>");
	scanf("%s", str);
	if (str[0] == 's' && str[1] == 'b' && str[2] == 0) {
		printf("sb模式已进入。\n");
		printf("SB:\\sb>");
		zhengwen();
	}
	else
	{
		printf("未找到命令");
	}
	//printf("%d", suiji());
	//system("G:\\QQPlayer\\QQPlayer.exe H:\\TFBOYS-样(YOUNG) (《小别离》电视剧主题曲)(蓝光).mp4");
	/*最简单的方法，用system
如
system("C:\Users\xxx\AppData\Roaming\360se6\Application\360se.exe C:\Users\xxx\Desktop\aaa.txt"
用360浏览器打开桌面上的aaa.txt
其中xxx是你的用户名，参数可以用变量代替（这样就灵活了）
当然，更好的方法可用CreateProcess,自己到MSDN研究下参数*/
}