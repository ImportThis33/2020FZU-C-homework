#include<stdio.h>
#include<string>
int j;
char chinese[11][3] = { "零","一","二","三","四","五","六","七","八","九","十" };
int Ch_Switch_Num(char* s);
int ChangeSingle(char* s);
char* extract(char* a, char* b);
void test(char* s, int a);
int main(void)
{
	test("九十九", 99);
	test("零", 0);
	test("一", 1);
	test("十", 10);
	test("五十", 50);
	test("六十三", 63);
	test("七十七", 77);
	printf("以下为错误测试\n");
	test("sekiro", 99);
	test("真", 66);
	test("好", 1);
	test("玩", 2);
	return 0;
		
}
void test(char* s, int a)
{
	if (Ch_Switch_Num(s) == a)
		printf("pass\n");
	else
		printf("error\n");
}
int Ch_Switch_Num(char* s)
{
	char buffer[5] = "";
	if (strlen(s) == 2)//处理0-9的汉字
		j = ChangeSingle(s);
	else if (strlen(s) == 4)//处理10-19以及十的倍数的汉字
	{
		strcpy(buffer, extract(buffer, s));
		if (strcmp(buffer, "十") == 0)//处理10-19的汉字
			j = 10 + ChangeSingle(extract(buffer, s + 2));
		else//处理十的倍数
			j = ChangeSingle(buffer) * 10;
	}
	else//处理几十几的汉字
		j = ChangeSingle(extract(buffer, s)) * 10 + ChangeSingle(extract(buffer, s + 4));
	return j;
}
int ChangeSingle(char* s)
{
	int i;
	for (i = 0; i < 11; i++)
	{
		if (strcmp(s, chinese[i]) == 0)
			return i;
	}
}
char* extract(char* a, char* b)
{
	a[0] = b[0];
	a[1] = b[1];
	return a;
}
