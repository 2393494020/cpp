#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SIZE 10
int main()
{
    char* ptrHello = (char*)malloc(sizeof(char) * 12);
    strcpy(ptrHello, "hello world");
    printf("%s\n", ptrHello);
    free(ptrHello);
    
    int* ptrNum = (int*)malloc(sizeof(int) * NUM_SIZE);
    memset(ptrNum, 0, sizeof(int) * NUM_SIZE);
    ptrNum[0] = 10;
    for (int i = 0; i < NUM_SIZE; i++)
    {
        printf("ptrNum[%d]=%d\n", i, ptrNum[i]);
    }
    free(ptrNum);
    return 0;
}
