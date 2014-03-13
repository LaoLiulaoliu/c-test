#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo()
{
	int n = rand();
	return n;
}

int main(int argc, char *argv[])
{
	int i;
	time_t t = 0;

	srand((unsigned) time(&t));//initialize the seed.Different seed generate different "random sequence" in the next rand() cycle. 

	//srand(3);
	/* Every run comes with the same result. */
	for (i =0; i < 6; i++)
	{
		printf("%d\n", foo());
	}
	return 0;
}
