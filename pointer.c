#include <stdio.h>

void foo1(int *pointer)
{
	*pointer = 9;
}

int global = 5;
void foo2(int **doublePointer)
{
	*doublePointer = &global;
}

int main()
{
	int i = 10;
	int *ip = &i;

	foo1(ip);
    printf("i: %d, ip: %d\n", i, *ip);

	foo2(&ip);//i is still 9, ip is pointing to "global" now
    printf("i: %d, ip: %d\n", i, *ip);

	return 0;
}
