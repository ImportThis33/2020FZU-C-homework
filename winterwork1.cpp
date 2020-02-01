#include<stdio.h>
#include<string.h>
int j;
int num(char* s);//将汉字转为数字
int change(char* s);//将单个汉字转换为数字
char *extract(char* a, char* b);//提取“十”字前后的数字
char chinese[11][3] = { "零","一","二","三","四","五","六","七","八","九","十" };
int main()
{
	char s[10];
	char sp[10];
	int i,caibu;
	printf("提示：本程序仅支持输入整数进行运算\n");
	scanf("%s", s);
	if (strcmp(s, "整数") == 0)
	{
		scanf("%s", s);
		strcpy(sp, s);
		for (i = 0; i < 2; i++)
			scanf("%s", s);
		caibu = num(s);
		scanf("%s", s);
		while (strcmp(s, sp) == 0)
		{
			scanf("%s", s);
			if (strcmp(s, "增加") == 0)
			{
				scanf("%s", s);
				caibu += num(s);
			}
			else if (strcmp(s, "减少") == 0)
			{
				scanf("%s", s);
				caibu -= num(s);
			}
			scanf("%s", s);
		}
		scanf("%s", s);
		if (caibu <= 10)
			printf("%s", chinese[caibu]);
		else if (caibu > 10 && caibu < 20)
			printf("十%s", chinese[caibu - 10]);
		else if (caibu % 10 == 0)
			printf("%s十", chinese[caibu / 10]);
		else
			printf("%s十%s", chinese[caibu / 10], chinese[caibu % 10]);
	}
	else
		printf("错误！请输入整数！");
	return 0;
}
int num(char* s)
{
	char buffer[5] = "";
	if (strlen(s) == 2)//处理0-9的汉字
	{
		j=change(s);
	}
	else if (strlen(s) == 4)//处理10-19以及十的倍数的汉字
	{
		strcpy(buffer,extract(buffer, s));
		if (strcmp(buffer, "十") == 0)//处理10-19的汉字
		{
			j = 10 + change(extract(buffer,s+2));
		}
		else//处理十的倍数
		{
			j = change(buffer) * 10;
		}
	}
	else//处理几十几的汉字
	{
		j = change(extract(buffer, s)) * 10 + change(extract(buffer, s + 4));
	}
	return j;
}
int change(char* s)
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