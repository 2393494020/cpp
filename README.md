# tools
https://godbolt.org

# cpp
https://github.com/fqxy/DataStructures-Algorithms \
https://github.com/2604150210/ACM_Algorithm \
https://github.com/sr6033/dataStructure-Algorithms

## basic facilities

1. 指针
2. 数组指针和二维数组
3. 智能指针
4. 引用
5. 内存分块: text,data,heap,stack; $ ulimit -a; C:\Users\xyz> size xxx.exe
6. c/c++ 的数组默认在栈区分配
7. 左值右值
8. extern
9. const
10. auto
11. using
12. nullptr
13. io

## oop

1. 成员变量
2. 成员函数
3. 构造函数
4. 拷贝构造函数
5. 析构函数
6. 运算符重载
7. 友元(friend)
8. 虚函数(virtual)
9. 内联函数(inline)

### 相同 class 造出来的 objects 互为 friends(友元)

### 析构函数
1. 不带指针的类多半不用写析构函数

### inline
1. class body 里边的函数按语法理解都是内联函数
2. class body 外边的函数可以用 inline 关键字建议编译器将其编译为内联函数
3. 函数体如果太过复杂编译器不会接受建议

## stl
1. allocator
2. 访函数

## 网络

## 多线程

## c/c++ 编译过程
1. gcc hello.c --save-temps 
2. gcc -E hello.c -o hello.i 预处理:宏定义展开,头文件展开
3. gcc -S hello.i -o hello.s 编译:语法检查,将目标文件编译生成汇编文件
4. gcc -c hello.s -o hello.o 汇编:将汇编文件生成目标文件(不可以执行)
5. gcc hello.o -o hello.out  链接:链接依赖库到目标文件生成可执行文件
