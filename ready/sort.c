#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 20

// 选择排序
// 从未排序的序列中选择最大[小]的元素放在起始
// 从剩余的未排序的序列中选择最大[小]的元素放在有序序列末尾
// 第1轮
// [0]跟[1]比, 如果[0]>[1], 交换
// [0]跟[2]比, 如果[0]>[2], 交换
// ...
// [0]跟[size-1]比, 如果[0]>[size-1], 交换
// size-1次比较后, [0]存储最小的元素
// 第2轮
// [1]跟[2]比, 如果[1]>[2], 交换
// [1]跟[3]比, 如果[1]>[3], 交换
// ...
// [1]跟[size-1]比, 如果[1]>[size-1], 交换
// size-2次比较后, [1]存储次小的元素
// ...
void select_sort(int* unsort_arr)
{
    for (int i = 0; i < ARR_SIZE - 1; i++)
    {
        for (int j = i + 1; j < ARR_SIZE; j++)
        {
            if (unsort_arr[i] > unsort_arr[j])
            {
                int tmp = unsort_arr[j];
                unsort_arr[j] = unsort_arr[i];
                unsort_arr[i] = tmp;
            }
        }
        printf("\n排序次:%d", i + 1);
        for (int k = 0; k < ARR_SIZE; k++) {
            printf("\t%d", unsort_arr[k]);
        }
    }
}

// 冒泡排序
// 相邻元素互相比较
// 第1轮
// [0]跟[1]比, 如果[0]>[1], 交换
// [1]跟[2]比, 如果[1]>[2], 交换
// ...
// [size-2]跟[size-1]比, 如果[size-2]>[size-1], 交换
// size-1次比较后, [size-1]存储最大的元素
// 第2轮
// [0]跟[1]比, 如果[0]>[1], 交换
// [1]跟[2]比, 如果[1]>[2], 交换
// ...
// [size-3]跟[size-2]比, 如果[size-3]>[size-2], 交换
// size-2次比较后, [size-2]存储次大的元素
// ...
void bubble_sort(int* unsort_arr)
{
    for (int i = 0; i < ARR_SIZE - 1; i++)
    {
        for (int j = 0; j < ARR_SIZE - 1 - i; j++)
        {
            if (unsort_arr[j] > unsort_arr[j + 1])
            {
                int tmp = unsort_arr[j + 1];
                unsort_arr[j + 1] = unsort_arr[j];
                unsort_arr[j] = tmp;
            }
        }
        printf("\n排序次:%d", i + 1);
        for (int k = 0; k < ARR_SIZE; k++) {
            printf("\t%d", unsort_arr[k]);
        }
    }
}

// 改良版, 如果前后数据比较没有发生冒泡动作, 证明余下的子序列已排好序
void bubble_sort_pro(int* unsort_arr)
{
    int unsorted = 1;
    for (int i = 0; i < ARR_SIZE - 1 && unsorted; i++)
    {
        unsorted = 0;
        for (int j = 0; j < ARR_SIZE - 1 - i; j++)
        {
            if (unsort_arr[j] > unsort_arr[j + 1])
            {
                int tmp = unsort_arr[j + 1];
                unsort_arr[j + 1] = unsort_arr[j];
                unsort_arr[j] = tmp;
                unsorted = 1;
            }
        }
        // printf("\n排序次:%d", i + 1);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    printf("排序前:");
    int* unsort_arr = (int*)malloc(sizeof(int) * ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        int r = rand() % 100;
        unsort_arr[i] = r;
        // printf("\t%d", unsort_arr[i]);
    }

    // 写文件
    FILE* result_f_w = fopen("./result.txt", "w");
    time_t start = time(0);
    char* fmt_start_time = asctime(localtime(&start));
    fputs(fmt_start_time, result_f_w);

    bubble_sort(unsort_arr);

    time_t end = time(0);
    char* fmt_end_time = asctime(localtime(&end));
    fputs(fmt_end_time, result_f_w);
    fputs("\n", result_f_w);
    
    printf("\n排序后:");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        // printf("\t%d", unsort_arr[i]);
        char num[5];
        fputs(itoa(unsort_arr[i], num, 10), result_f_w);
        if (i < ARR_SIZE - 1)
        {
            fputs("\t", result_f_w);
        }
    }

    free(unsort_arr);

    // 关闭文件
    fclose(result_f_w);
    return 0;
}