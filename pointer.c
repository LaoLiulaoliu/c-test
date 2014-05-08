#include <stdio.h>

/* 指针变量environ，它指向的是包含所有的环境变量的一个列表 */
extern char **environ;

void printarg(int argc, char *argv[])
{
    int i;
    /* argv[0] -> ./a.out */
    for (i = 0; i < argc; i++)
        printf("argv[%i]=%s\n", i, argv[i]);
    printf("\n");
}

void printenv()
{
    char ** var;
    for (var = environ; *var != NULL; ++var)
        printf("%s\n", *var);
    printf("\n");
}


void different_type_pointer()
{
    int a = 97; 
    char *p = (char *)&a;
    if (*p == *(char *)&a)
        printf("%c,%d\n", *p, *p); //a,97
}

int main(int argc, char *argv[])
{
    printarg(argc, argv);
    printenv();

    different_type_pointer();

    return 0;
}
