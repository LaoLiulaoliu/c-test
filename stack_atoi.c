/* 同一个stack frame下面的变量分配完全可以随意，正着反着乱序都无所谓，也可能根本就没分配空间，只存在寄存器里 */

#include <stdio.h>
int main(int argc, char *argv[])
{
    /* 数组在栈中占据连续内存区域，首（元素）地址为内存块中最低的那块。*/
    char a[] = "abcd";
    printf("%#x\t%#x\t%#x\t%#x\n", a, a+1, a+2, a+3);//0x5a7e8bdb  0x5a7e8bdc  0x5a7e8bdd  0x5a7e8bde

    /* char 一个个分配，地址越来越小.
     * 栈在内存中由高地址向低地址生长，故变量分配地址减小
     */
	char cp = 't';
	char cp0 = '0';
	char cp1 = '1';
	char cp2 = '6';
	char cp3 = '5';
    printf("%#x\t%#x\t%#x\t%#x\t%#x\n", &cp, &cp0, &cp1, &cp2, &cp3);//0x5a7e8bda  0x5a7e8bd9  0x5a7e8bd8  0x5a7e8bd7  0x5a7e8bd6

    /* atoi 从当前开始的字符（数字或+、-）到第一个不是数字的字符结束的数字字符串*/
	printf("%i\t%i\t%i\t%i\n", atoi(&cp), atoi(&cp0), atoi(&cp1), atoi(&cp2)); //0	0	10	610
	return 0;
}
