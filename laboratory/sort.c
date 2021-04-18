#include <stdio.h>
#include <stdlib.h>

void bubble()
{
    printf("[%s]\n", __FUNCTION__);
    int fabonacci[10] = {144, 89, 2, 34, 21, 13, 8, 5, 3, 55};
    int len = sizeof(fabonacci) / sizeof(fabonacci[0]);
    
    printf("unsorted fabonacci sequence:");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", fabonacci[i]);
    }

    // bubble sort
    int count = 0;
    for (int i = len; i > 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (fabonacci[j] > fabonacci[j + 1]) {
                int temp = fabonacci[j];
                fabonacci[j] = fabonacci[j + 1];
                fabonacci[j + 1] = temp;
            }
        }
        printf("\n             after %d bubble:", ++count);
        for (int k = 0; k < len; k++)
        {
            printf("%d ", fabonacci[k]);
        }
    }

    printf("\n  sorted fabonacci sequence:");
    for (int k = 0; k < len; k++)
    {
        printf("%d ", fabonacci[k]);
    }
    printf("\n");
}

void selection()
{
    printf("[%s]\n", __FUNCTION__);
    int fabonacci[10] = {144, 89, 2, 34, 21, 13, 8, 5, 3, 55};
    int len = sizeof(fabonacci) / sizeof(fabonacci[0]);
    
    printf("unsorted fabonacci sequence:");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", fabonacci[i]);
    }

    // selection sort
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (fabonacci[i] > fabonacci[j]) {
                int temp = fabonacci[j];
                fabonacci[j] = fabonacci[i];
                fabonacci[i] = temp;
            }
        }
        printf("\n          after %d selection:", i + 1);
        for (int k = 0; k < len; k++)
        {
            printf("%d ", fabonacci[k]);
        }
    }

    printf("\n  sorted fabonacci sequence:");
    for (int k = 0; k < len; k++)
    {
        printf("%d ", fabonacci[k]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    bubble();
    printf("\n");
    selection();
    return 0;
}
