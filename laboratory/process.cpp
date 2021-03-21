#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("before fork, process id:%d\n", getpid());
    int count = 0;
    int pid = fork();

    if (pid == 0)
    {
        // 子进程

        for (int i =0; i < 900000; i++)
        {
            count += 1;
        }
        printf("child process id:%d\n", getpid());
        printf("parent process id:%d\n", getppid());
    } else {
        // 父进程

        for (int i =0; i < 200; i++)
        {
            count += 1;
        }
        printf("after fork, child process id:%d\n", pid);
        printf("after fork, process id:%d\n", getpid());
        // 如果不等待子进程结束会出现子进程找不到父进程的情况
        // wait(NULL);
    }
    // fork 出来的子进程与父进程并发(concurrency)执行
    // 父子进程内存空间相互独立
    // 父子进程内存结构一模一样
    printf("process %d count:%d\n", getpid(), count);
    return 0;
}