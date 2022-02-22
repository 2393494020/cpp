#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// malloc 使用原则
// 1. 申请
// 2. 判空
// 3. 使用
// 4. 释放
// 5. 置空
// malloc, free 配对使用

#define NUM_SIZE 5
int main()
{
    char* ptr_c = (char*)malloc(sizeof(char) * 12);
    if (NULL != ptr_c)
    {
        strcpy(ptr_c, "hello world");
        printf("%s\n", ptr_c);
        free(ptr_c);
        ptr_c = NULL;
    }
    
    int* ptr_i = (int*)malloc(sizeof(int) * NUM_SIZE);
    memset(ptr_i, 0, sizeof(int) * NUM_SIZE);
    ptr_i[0] = 10;
    for (int i = 0; i < NUM_SIZE; i++)
    {
        printf("*ptr_i[%d]=%d\n", i, ptr_i[i]);
    }
    printf("\n");
    // malloc 申请和初始化 heap 资源都是以字节为单位
    memset(ptr_i, 5, sizeof(int) * NUM_SIZE);
    ptr_c = (char*)ptr_i;

    for (int i = 0; i < sizeof(int) * NUM_SIZE; i++)
    {
        printf("*ptr_c[%d]=%d\n", i, ptr_c[i]);
    }

    free(ptr_i);
    ptr_i = NULL;
    ptr_c = NULL;

    // calloc 申请并初始化
    int* ptr_ic = (int*)calloc(NUM_SIZE, sizeof(int));
    for (int i = 0; i < NUM_SIZE; i++)
    {
        printf("*ptr_ic[%d] = %d\n", i, ptr_ic[i]);
    }
    free(ptr_ic);
    ptr_ic = NULL;

    // realloc
    // 情况1. 恰好在原有基础空间, 返回值与传入的指针相同
    // 情况2. 释放再重新申请并拷贝
    char* ptr_str = (char*)malloc(sizeof(char) * 10);
    strcpy(ptr_str, "hello");

    ptr_str = realloc(ptr_str, sizeof(char) * 20);
    printf("%s\n", ptr_str);

    free(ptr_str);
    ptr_str = NULL;

    return 0;
}
