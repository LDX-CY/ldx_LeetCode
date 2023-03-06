#include <stdio.h>
#include <malloc.h>
typedef struct en
{
	unsigned char string;
	int num;
}End;
//O(n-1),ÓÅ»¯´æ´¢,
void string(char* s, End* end)
{
	int num=0;
	int Right = 0;
	end->string = 0;
	end->num = 0;
	while (s[Right] != ':')
	{
		num += s[Right];
		Right++;
		if (s[Right] == '\0')
			return;
	}	
	if (num != 453)
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