#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < 256; i++)
	{
		printf("%d %#x %c\t", i, i, i);
		printf("%d\n", isprint(i));
	}
	return 0;
}
