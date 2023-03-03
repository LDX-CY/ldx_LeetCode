#include <stdio.h>
#include <malloc.h>
typedef struct en
{
	unsigned char string;
	int num;
}End;
char* ss = "text";
void string(char* s, End* end)
{
	unsigned char i;
	int Left = 0, Right = 0;
	end->string = 0;
	end->num = 0;
	while (s[Right] != ':')
	{
		Right++;
		if (s[Right] == '\0')
			return;
	}	
	for (; Left < Right; Left++)
		if (s[Left] != ss[Left])
			return;		
	end->string = 111;
	while (s[++Right] != '\0')
	{
		end->num *= 10;
		end->num += s[Right] - '0';
	}
}

int main()
{
	char* s = "text:123456";
	End* end = (End*)malloc(sizeof(End));
	string(s, end);
	printf("string:%d\tnum:%d\r\n", end->string,end->num);
	return 0;
}