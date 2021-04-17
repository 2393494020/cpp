#include <stdio.h>
#include <stdlib.h>

void fabonacci(int num)
{
    int fabonacci_ary[num];
    int length = sizeof(fabonacci_ary) / sizeof(fabonacci_ary[0]);

    fabonacci_ary[0] = 1;
    fabonacci_ary[1] = 1;
    for (int i = 2; i < length; i++)
    {
        fabonacci_ary[i] = fabonacci_ary[i - 1] + fabonacci_ary[i - 2];
    }

    for (int i = 0; i < length; i++) {
        printf("%d is %d\n", i + 1, fabonacci_ary[i]);
    }
}

void fabonacci_plus(int len)
{
    int first = 1;
    int second = 1;
    int target = 1;
    for (int i = 2; i < len; i++)
    {
        target = second + first;
        first = second;
        second = target;
    }

    printf("target is %d\n", target);
}

int main(int argc, char const *argv[])
{
    int fabonacci_length;
    printf("input fabonacci length:");
    scanf("%d", &fabonacci_length);
    fabonacci_plus(fabonacci_length);
    return 0;
}
