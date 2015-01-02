#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int max = 20, min = -80;
    srandom( (unsigned)time(NULL) );
    long rand = random();

    /* 2 different methods to generate [-80, 20) */
    float i = (float)rand / (RAND_MAX + 1.0) * (max - min) + min; //rational number
    int j = rand % (max - min + 1) + min; // integer
    printf("%f, %d\n", i, j);
    return 0;
}
