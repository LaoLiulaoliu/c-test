#include <stdio.h>
int main(int argc, char *argv[])
{
    char a[] = "abcd";
    printf("%#x\t%#x\t%#x\t%#x\n", a, a+1, a+2, a+3);

    /* char 一个个分配，竟然地址越来越小*/
	char cp = 't';
	char cp0 = '0';
	char cp1 = '1';
	char cp2 = '6';
	char cp3 = '5';
    printf("%#x\t%#x\t%#x\t%#x\t%#x\n", &cp, &cp0, &cp1, &cp2, &cp3);

    /* atoi 从当前开始的字符（数字或+、-）到第一个不是数字的字符结束的数字字符串*/
	printf("%i\t%i\t%i\t%i\n", atoi(&cp), atoi(&cp0), atoi(&cp1), atoi(&cp2)); //0	0	10	610
	return 0;
}
