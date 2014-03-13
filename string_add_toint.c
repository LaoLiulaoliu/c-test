#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
    /* One difference between %i and %d is that when used with scanf(),
     * then %d always expects a decimal integer,
     * whereas %i recognizes the 0 and 0x prefixes as octal and hexadecimal
     */
	char c[5] = "lov";
	printf("%i\n", strlen(c));
	c[strlen(c)+1] = 0; /* c[4] */
	c[strlen(c)] = 'e'; /* c[3] */
	printf("%i\n", strlen(c));
	printf("%s\n", c);

	if ('\0' == 0 && NULL == 0 && EOF == -1 && '\n' == 10)
		printf("Character value right\n");
	
	unsigned long method = strtoul(argv[1], NULL, 10);
	printf("%lu\n", method); //the result is 0.If argv[1] is a number,result is the number.

	return 0;
}
