#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 60000

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
        // printf("\n排序次:%d", i + 1);
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
    srand((unsigned)time(NULL));
    printf("排序前:");
    int* unsort_arr = (int*)malloc(sizeof(int) * ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        int r = rand() % 10000;
        unsort_arr[i] = r;
        // printf("%d\t", unsort_arr[i]);
    }

    // 写文件
    FILE* result_f_w = fopen("./result.txt", "w");
    time_t start = time(0);
    char* fmt_start_time = asctime(localtime(&start));
    fputs(fmt_start_time, result_f_w);

    bubble_sort_pro(unsort_arr);

    time_t end = time(0);
    char* fmt_end_time = asctime(localtime(&end));
    fputs(fmt_end_time, result_f_w);
    fputs("\n", result_f_w);
    
    printf("\n排序后:");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        // printf("%d\t", unsort_arr[i]);
        char num[5];
        fputs(itoa(unsort_arr[i], num, 10), result_f_w);
        fputs("\t", result_f_w);
    }

    free(unsort_arr);

    // 关闭文件
    fclose(result_f_w);
    return 0;
}