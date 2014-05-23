#include <stdio.h>
#include <string.h>

int array_pointer_add(int b[][3])
{
	++b;
	return b[0][1] * b[1][2];
}


int main()
{
	int i;
	int a[5] = {1,2,3,4,5};
	int *p = (int *)(&a+1); /* +1 means add the length of array a to a*/
	printf("%d,%d\n", *(a+1), *(p-1)); //2,5


#ifdef ERR
	int *q = &a; //"gcc charpointer.c -DERR" an warning will occur 
#else
	int *q = &a[0];
#endif

	for (i = 0; i < 3; i++)
		printf("%d,", *q++); //*(q++)
	for (i = 0; i < 3; i++)
		printf("%d,", *p++); //0,random,random,




	int arr[3][3] = { {1,2,3},
                      {4,5,6},
                      {7,8,9}
                    };
    int (*pp)[3] = arr;
    pp++;
    printf("\n sth: %d\n", *(*pp+3)); // 7
    printf("\n%d, %d\n", arr[0][1] * arr[1][2], array_pointer_add(arr)); // 12, 45

	char b[10] = "china\0cc";
	printf("%lu %lu %s\n", strlen(b), sizeof(b), b);

	return 0;
}
