#include<stdio.h>
#include<string.h>
int j;
int In_Or_De(char* s, char * sp,int a);//判断是增加还是减少
void output(int a);//输出结果
int Ch_Switch_Num(char* s);//将汉字转为数字
int changeSingle(char* s);//将单个汉字转换为数字
char *extract(char* a, char* b);//提取“十”字前后的数字
char chinese[11][3] = { "零","一","二","三","四","五","六","七","八","九","十" };
int main()
{
	char s[10];char sp[10];
	int i, caibu;
	freopen("D:\\lang.txt", "r", stdin);
	scanf("%s", s);
	scanf("%s", s);
	strcpy(sp, s);
	for (i = 0; i < 2; i++)
		scanf("%s", s);
	caibu = Ch_Switch_Num(s);
	scanf("%s", s);
	caibu = In_Or_De(s,sp,caibu);
	scanf("%s", s);
	output(caibu);
	return 0;
}
int In_Or_De(char* s, char* sp,int a)
{
	while (strcmp(s, sp) == 0)
	{
		scanf("%s", s);
		if (strcmp(s, "增加") == 0)
		{
			scanf("%s", s);
			a += Ch_Switch_Num(s);
		}
		else if (strcmp(s, "减少") == 0)
		{
			scanf("%s", s);
			a -= Ch_Switch_Num(s);
		}
		scanf("%s", s);
	}
	return a;
}
void output(int a)
{
	if (a <= 10)
		printf("%s", chinese[a]);
	else if (a > 10 && a < 20)
		printf("十%s", chinese[a - 10]);
	else if (a % 10 == 0)
		printf("%s十", chinese[a / 10]);
	else
		printf("%s十%s", chinese[a / 10], chinese[a % 10]);
}
int Ch_Switch_Num(char* s)
{
	char buffer[5] = "";
	if (strlen(s) == 2)//处理0-9的汉字
		j=changeSingle(s);
	else if (strlen(s) == 4)//处理10-19以及十的倍数的汉字
	{
		strcpy(buffer,extract(buffer, s));
		if (strcmp(buffer, "十") == 0)//处理10-19的汉字
			j = 10 + changeSingle(extract(buffer,s+2));
		else//处理十的倍数
			j = changeSingle(buffer) * 10;
	}
	else//处理几十几的汉字
		j = changeSingle(extract(buffer, s)) * 10 + changeSingle(extract(buffer, s + 4));
	return j;
}
int changeSingle(char* s)
{
	int i;
	for (i = 0; i < 11; i++)
	{
		if (strcmp(s, chinese[i]) == 0)
			return i;
	}
}
char *extract(char* a, char* b)
{
	a[0] = b[0];
	a[1] = b[1];
	return a;
}