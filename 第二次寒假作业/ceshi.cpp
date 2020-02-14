#include<stdio.h>
#include<string>
int j;
char chinese[11][3] = { "��","һ","��","��","��","��","��","��","��","��","ʮ" };
int Ch_Switch_Num(char* s);
int ChangeSingle(char* s);
char* extract(char* a, char* b);
void test(char* s, int a);
int main(void)
{
	test("��ʮ��", 99);
	test("��", 0);
	test("һ", 1);
	test("ʮ", 10);
	test("��ʮ", 50);
	test("��ʮ��", 63);
	test("��ʮ��", 77);
	printf("����Ϊ�������\n");
	test("sekiro", 99);
	test("��", 66);
	test("��", 1);
	test("��", 2);
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
	if (strlen(s) == 2)//����0-9�ĺ���
		j = ChangeSingle(s);
	else if (strlen(s) == 4)//����10-19�Լ�ʮ�ı����ĺ���
	{
		strcpy(buffer, extract(buffer, s));
		if (strcmp(buffer, "ʮ") == 0)//����10-19�ĺ���
			j = 10 + ChangeSingle(extract(buffer, s + 2));
		else//����ʮ�ı���
			j = ChangeSingle(buffer) * 10;
	}
	else//����ʮ���ĺ���
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
