#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int max = 20, min = -80;
    srandom( (unsigned)time(NULL) );
    long rand = random();

    /* 2 different methods to generate [-80, 20)
     * RAND_MAX == 0x7fffffff */

    float i = (float)rand / (RAND_MAX + 1.0) * (max - min) + min; //rational number
    int j = rand % (max - min + 1) + min; // integer
    printf("%f, %d\n", i, j);
    return 0;
}

int randrange(int start, int end)
{
    /* generate random integer in [start, end) */
    srandom( (unsigned)time(NULL) );
    return random() % (end - start + 1) + start;
}

int randint(int start, int end)
{
    /* generate random integer in [start, end] */
    return randrange(start, end+1)
}
