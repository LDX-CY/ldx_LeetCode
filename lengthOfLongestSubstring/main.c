#include <stdio.h>
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
int lengthOfLongestSubstring(char* s) 
{
	int num=0, num_next=0,len;
	unsigned char left=0, right=0;
	unsigned char hass[128] = { 0 };
	len = strlen(s);
	for (; right <len;)
	{
		if (hass[s[right]] == 0)
		{
			hass[s[right]] = 1;
			num_next++;
			right++;
			if (num_next > num) num = num_next;
		}
		else
		{
			hass[s[left]] = 0;
			left++;
			num_next--;
		}
	}

	return num;
}

int main()
{
	char* s = "dvdf";
	int num;
	num = lengthOfLongestSubstring(s);
	printf("num:%d\r\n",num);
	return 0;
}