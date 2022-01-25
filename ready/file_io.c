#include <stdio.h>
#include <time.h>

int main()
{
    time_t now = time(0);
    char* fmt_time = asctime(localtime(&now)); // 将本地时间转换为字符串

    // 写文件
    FILE* greeting_f_w = fopen("./greeting.txt", "w");
    fputs("hello world!\n", greeting_f_w);
    fputs(fmt_time, greeting_f_w);

    // 关闭文件
    fclose(greeting_f_w);
    
    // 读文件
    FILE* greeting_f_r = fopen("./greeting.txt", "r");
    while(1)
    {
        char c = fgetc(greeting_f_r);
        if (c == EOF)
        {
            break;
        }
        else
        {
            printf("%c", c);
        }
    }

    fclose(greeting_f_r);

    return 0;
}
