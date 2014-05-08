/* Usage:
 *     ./a.out create cc.rrd -a 1234 -b 432 -c -e
 * getopt() does not work well on Darwin platform
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ch;
#ifndef ERROR
	opterr = 0;
#endif
	while ((ch = getopt(argc, argv, "a:b:cd")) != -1)
	{
		printf("optind:%d\n",optind);
		printf("optarg:%s\n",optarg);
		printf("ch:%c\n",ch);

		switch (ch)
		{
			case 'a':
				printf("option a:%s\n", optarg);
				break;
			case 'b':
				printf("option b:%s\n", optarg);
				break;
			case 'c':
				printf("option c\n");
				break;
			case 'd':
				printf("option d\n");
				break;
			case '?':
				printf("unknown option:%c\n", (char)optopt);
				break;
			default:
				printf("other option:%c\n", ch);
		}
		printf("optopt:%i\n", optopt);
	}

	printf("argc:%d, optind:%d, %s, %s, %s\n", argc, optind,
			argv[optind], argv[optind+1], argv[optind+2]);
	return 0;
}
