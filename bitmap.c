#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 5
#define MASK 0x1f

int *apply_memory(size_t size)
{
    size_t number_int = size / (sizeof(int) * 8) + 1;
    int *block = (int *)malloc(sizeof(int) * number_int);
    if (NULL == block)
        perror("malloc failed.");
    else
        memset(block, 0, sizeof(int) * number_int);

    return block;
}

void recover_memory(int *p)
{
    free(p);
    p = NULL;
}

/* 1.求十进制i对应在数组p中的下标: i/32
 * 2.求i对应0-31中的数: i%32 = M
 * 3.利用移位0-31使得对应32bit位为1: 1 << M
 * 不能用二进制编码的形式存储，而要存储相应位，否则会有其他数字形成覆盖
 */
void set(int *p, size_t i)
{
    p[i >> SHIFT] |= 1 << (i & MASK); // p[i/32] |= 1 << (i%32);
}

void clr(int *p, size_t i)
{
    p[i >> SHIFT] &= ~(1 << (i & MASK));
}

int get(int *p, size_t i)
{
    return (p[i >> SHIFT] & 1 << (i & MASK)) != 0;
}

void flip(int *p, size_t i)
{
    if (get(p, i))
        clr(p, i);
    else
        set(p, i);
}

int main(int argc, char **argv)
{
    printf("size_t length: %lu, int length: %lu\n", sizeof(size_t), sizeof(int));

    size_t space = 1000000000; // 1 billion ~ 120M memory
    int *block = apply_memory(space);

    set(block, 35);

    printf("%d\n", get(block, 35));
    printf("%d\n", get(block, 37));

    recover_memory(block);
    return 0;
}
