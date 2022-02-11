#include <stdio.h>
#include <stdlib.h>

void mem_explore()
{
    // 栈空间的资源由高地址向低地址分配
    char c = 'c';
    // int d = 0x80000000;
    // int d = 0x7fffffff;
    int d = 0x7fabcdef;
    char e = 'e';
    char f = 'f';
    printf("&c = %x\n", &c);
    printf("&d = %x, d = %d\n", &d, d);
    printf("&e = %x\n", &e);
    printf("&f = %x\n", &f);
    char* p = (char*)&d;
    printf("%x = %x\n", p, *p);
    p++;
    printf("%x = %x\n", p, *p);
    p++;
    printf("%x = %x\n", p, *p);
    p++;
    printf("%x = %x\n", p, *p);

    // 堆空间的资源由低地址向高地址分配
    // l,m,n 指针变量存储在栈空间, l,m,n 所指空间位于堆空间
    int* l = (int*)malloc(sizeof(int));
    int* m = (int*)malloc(sizeof(int));
    int* n = (int*)malloc(sizeof(int));

    *l = 2;
    *m = 0x7fabcdef;
    *n = 9;
    printf("&l = %x, l = %x\n", &l, l);
    printf("&m = %x, m = %x, *m = %d\n", &m, m, *m);
    printf("&n = %x, n = %x\n", &n, n);

    p = (char*)m;
    printf("%x = %x\n", p, *p);
    p++;
    printf("%x = %x\n", p, *p);
    p++;
    printf("%x = %x\n", p, *p);
    p++;
    printf("%x = %x\n", p, *p);
    
    free(l);
    free(m);
    free(n);

    // int 占4字节空间, 数据高位存储在高地址, 低位存储在低地址
}

int main(int argc, char const *argv[])
{
    mem_explore();
    return 0;
}