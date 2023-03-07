#include <stdio.h>
#include <malloc.h>
#include <string.h>

//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
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
			//这是N字形排序的特点，数学表达式，交替相同，多观察未知数与已知数的联系，最终形成表达式。
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