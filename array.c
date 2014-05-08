#include <stdio.h>

int index_array()
{
    int a[5];
    int *p, n;

    printf("Please input words:");
    for(n=0; n<5; n++)
        scanf("%d", &a[n]);
    printf("\n");

    for(n=0; n<7; n++)
        printf("%d, %d\n", a[n], *(a+n));
    printf("\n");

    for(p=a; p<(a+7); p++)
        printf("%d\n", *p);

    return 0;
}

int main()
{
	index_array();
    return 0;
}
