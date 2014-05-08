#include <stdio.h>

char buf[10] = "hello";

void pro(char *out)
{
	out = buf;
    printf("in fucntion pointer is: %s\n", out);
    // out 指向的地址变了，p没变
}

void pro2(char **out)
{
    /* equal to: p = buf;
     * change p指向的地址
     */
	*out = buf;
}


void foo1(int *pointer)
{
    *pointer = 9;
}

int global = 5;
void foo2(int **doublePointer)
{
    *doublePointer = &global;
}

int main(int argc, char *argv[])
{
    int i = 1;
    int *ip = &i;
    foo1(ip);
    printf("i: %d, *ip: %d\n", i, *ip); //i is 9

    foo2(&ip); // i is still 9, ip is pointing to "global" now
    printf("i: %d, *ip: %d\n", i, *ip);



	char *p = NULL;
	pro2(&p);
	printf("%s, p address: %#x, buffer address: %#x\n", p, &p, buf);

	p = NULL;
	pro(p);
	printf("%s\n", p);//Cannot access memory at address 0x0.Segment fault

	return 0;
}
