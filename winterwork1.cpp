#include<stdio.h>
#include<string.h>
int j;
int In_Or_De(char* s, char * sp,int a);//�ж������ӻ��Ǽ���
void output(int a);//������
int Ch_Switch_Num(char* s);//������תΪ����
int changeSingle(char* s);//����������ת��Ϊ����
char *extract(char* a, char* b);//��ȡ��ʮ����ǰ�������
char chinese[11][3] = { "��","һ","��","��","��","��","��","��","��","��","ʮ" };
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
		if (strcmp(s, "����") == 0)
		{
			scanf("%s", s);
			a += Ch_Switch_Num(s);
		}
		else if (strcmp(s, "����") == 0)
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
		printf("ʮ%s", chinese[a - 10]);
	else if (a % 10 == 0)
		printf("%sʮ", chinese[a / 10]);
	else
		printf("%sʮ%s", chinese[a / 10], chinese[a % 10]);
}
int Ch_Switch_Num(char* s)
{
	char buffer[5] = "";
	if (strlen(s) == 2)//����0-9�ĺ���
		j=changeSingle(s);
	else if (strlen(s) == 4)//����10-19�Լ�ʮ�ı����ĺ���
	{
		strcpy(buffer,extract(buffer, s));
		if (strcmp(buffer, "ʮ") == 0)//����10-19�ĺ���
			j = 10 + changeSingle(extract(buffer,s+2));
		else//����ʮ�ı���
			j = changeSingle(buffer) * 10;
	}
	else//����ʮ���ĺ���
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