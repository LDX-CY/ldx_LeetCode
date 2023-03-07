#include <stdio.h>

/*����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
����ַ����ķ�����ԭʼ�ַ�����ͬ������ַ�����Ϊ�����ַ�����*/
char* longestPalindrome(char* s) 
{
	//char* res=NULL;
	short int head = 0, visit_h = 0, tail = 0, visit_t = 0, prev_num = 0, i = 0;
	while (s[head])
	{
		if (s[head] == s[tail])
		{
			visit_h = head;
			visit_t = tail;
			for (;visit_h<visit_t;)
			{
				if (s[visit_h] != s[visit_t])
					goto go;
				visit_h++;
				visit_t--;
			}
			if ((tail - head + 1) > prev_num)
			{
				prev_num = tail - head + 1;
				i = head;
				//if (res != NULL)
				//	free(res);
				//res = (char*)malloc(sizeof(char) * (prev_num+1));
				//visit_h = head;
				//for (i = 0; i < prev_num; i++)
				//	res[i] = s[visit_h++];
				//res[prev_num] = '\0';
			}
		}
go:
		tail++;
		if (!s[tail]&&s[head])
		{
			head++;
			tail = head;
		}
	}
	s[i + prev_num] = '\0';
	return s+i;
}

int main()
{
	char* s = "aacabdkacaa";
	char* res=NULL;
	res = longestPalindrome(s);
	printf("s:%s\r\nlongestPalindrome:%s\r\n",s,res);
	return 0;
}