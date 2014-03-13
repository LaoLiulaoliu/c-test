#include <stdio.h>

int index_arrayname()
{
    int a[5];
    int n;
    printf("Please input words:");
    for(n=0;n<5;n++)
        scanf("%d",&a[n]);
    printf("\n");
    for(n=0;n<5;n++)
    {
        printf("%d\n",a[n]); // index method
        printf("%d\n",*(a+n)); // array name method
    }
    printf("\n");
    return 0;
}

int pointer()
{
    int a[5];
    int *p,n;
    printf("Please input words:");
    for(n=0;n<5;n++)
        scanf("%d",&a[n]);
    printf("\n");
    for(p=a;p<(a+10);p++)
        printf("%d\n",*p);
    printf("\n");
    return 0;
}

int main()
{
	//index_arrayname();
    pointer();
    return 0;
}
