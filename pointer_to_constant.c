#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *buf = (char *)malloc(30);

	char ii[] = "yours";
	char *pp = "love";
	char a = 'c';
	printf("%s,%s,%c\n", buf, pp, a);	

	pp = "Who am I? Please told me!";
	sprintf (buf, "%s,%c", pp, a);
	printf("%s\n", buf);

	pp = "hi";
	// change pp's address is OK, change pp's content is wrong.
	// sprintf(pp, "%c", a); //Segment fault. because "hi" is constant
	// pp[0] = 'b'; //Segmentation fault.
	ii[0] = 'i';

	sprintf(buf, "%s", pp);//pp is hi\0
	printf("%s\t%s\n", buf, ii);
	return 0;
}
