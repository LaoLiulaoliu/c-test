//the parameter "-Wshadow" will find the error
#include <stdio.h>
int main()
{
	int ret = 0;
	int i;
	for (i = 0; i < 3; i++)
	{
		int ret = 1;
		ret++;
		printf("%i,",ret);
	}
	printf("\n");
	if (ret == 0)
		return ret;

	return 0;
}
