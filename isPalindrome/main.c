#include <stdio.h>

typedef unsigned char bool;
#define false 0
#define true 1

bool isPalindrome(int x)
{
    int num = 0, a = x;
    if (x < 0)
        return false;
    while (a > 0)
    {
        if (num > 214748364)
        {
            if (num == x / 10)
                return true;
            else
                return false;
        }
        num *= 10;
        num += a % 10;
        a /= 10;
    }
    if (num == x)
        return true;
    return false;
}

int main()
{
    char* s = isPalindrome(1234567899) == 1 ? "true" : "false";
    printf("isPalindrome:%s\r\n", s);
	return 0;
}