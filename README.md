# cpp
https://github.com/fqxy/DataStructures-Algorithms \
https://github.com/2604150210/ACM_Algorithm \
https://github.com/sr6033/dataStructure-Algorithms

### 相同 class 造出来的 objects 互为 friends(友元)

### 析构函数
1. 不带指针的类多半不用写析构函数

### inline
1. class body 里边的函数按语法理解都是内联函数
2. class body 外边的函数可以用 inline 关键字建议编译器将其编译为内联函数
3. 函数体如果太过复杂编译器不会接受建议

### c 编译过程
1. gcc -E hello.c -o hello.i 预处理:宏定义展开,头文件展开
2. gcc -S hello.i -o hello.s 编译:语法检查,将目标文件编译生成汇编文件
3. gcc -c hello.s -o hello.o 汇编:将汇编文件生成目标文件(不可以执行)
4. gcc hello.o -o hello.out  链接:链接依赖库到目标文件生成可执行文件