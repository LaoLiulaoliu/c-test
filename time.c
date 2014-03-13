#include <stdio.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    clock_t start, end;
    start = clock();

	struct timeval tseed;
	gettimeofday(&tseed, NULL);
	printf("%i, %i\n", sizeof(time_t), sizeof(suseconds_t));
	printf("%#x\t %#x\t %d\n", tseed.tv_sec, tseed.tv_usec, time(0));
	printf("%#x\n", tseed.tv_sec ^ tseed.tv_usec);

    /* “开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数
     * CLOCKS_PER_SEC，它用来表示一秒钟会有多少个时钟计时单元
     */
    end = clock();
    printf("%ld \t %lu\n", start, (end - start) / CLOCKS_PER_SEC);
	return 0;
}
