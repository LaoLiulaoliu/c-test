#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
#ifdef ER
	FILE *fp;
	char str2[9] = "love you";
	if ((fp = fopen("whod", "w")) == NULL) {
		printf("Can't open the file.\n");
		exit(0);
	}
	fprintf(stdout, "%s", str2);
	fclose(fp);
#else
	char var = 'a';
	char str[5] = "love";
	char dest[10];
	int ava = 33;
	int count = snprintf(dest, 6, "%c,%s", var, str);
	printf("%i,%s\n", count, dest);

	printf("%s//%d//%s//%s//%s\n", __FILE__, __LINE__, __DATE__, __TIME__, __FUNCTION__);
	printf("%d, %d,%d,%d,%d\n", '\0', '\n', '\r', EOF, NULL);
	printf("%c,%#x\n", var, var);
	printf("%d,%#X\n", (char)ava, (char)ava);
#endif
	return 0;
}
