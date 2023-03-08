#include <stdio.h>

//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。
int reverse(int x) 
{
	int num=0;
	if (x < 10 && x > -10)
		return x;
	while (x != 0)
	{
		num *= 10;
		num += x % 10;
		x /= 10;
		if (((num > +214748364 || (num == +214748364 && x % 10 > 7)) 
			|| (num < -214748364 || (num == -214748364 && x % 10 > 8))) && x != 0)
			return 0;
	}
	return num;
}

int main()
{
	int x = 1534236469;
	int num = 0;
	num = reverse(x);
	printf("%d\r\n", num);
	return 0;
}