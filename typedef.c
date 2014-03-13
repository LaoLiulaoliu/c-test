#include <stdio.h>
int main(int argc, char *argv[])
{
	int i;
	typedef int NUM[5];
	NUM n;
	for (i = 0; i < 5; i++)
	{
		n[i] = i;
		printf("%d\n", n[i]);
	}
	return 0;
}
