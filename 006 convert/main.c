#include <stdio.h>
#include <malloc.h>
#include <string.h>

//��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�
char* convert(char* s, int numRows) 
{
	char* str=(char*)malloc(sizeof(char)*strlen(s)+1);
	int i = 0, index = 0, a = 0, num = numRows * 2 - 2, add = 0;;
	if (numRows == 1 || numRows >= strlen(s))
		return s;
	for (i = 0; i < numRows; i++)
	{
		add = i * 2;
		for (a = i; a < strlen(s);)
		{
			//����N����������ص㣬��ѧ���ʽ��������ͬ����۲�δ֪������֪������ϵ�������γɱ��ʽ��
			add = num - add;
			str[index++] = s[a];
			a += (i == 0 || i == numRows - 1) ? num : add;
		}		
	}
	str[index] = '\0';
	return str;
}

int main()
{
	char* s = "PAYPALISHIRING";
	int numRows = 4;
	printf("%s\r\n", convert(s, numRows));
	return 0;
}