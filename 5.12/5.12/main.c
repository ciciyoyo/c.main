//
//  main.c
//  5.12
//
//  Created by Rido on 2022/5/12.
//

#include <stdio.h>
//c语言预处理
//一.在ANSI C的任何一种实现中，存在两个不同的环境
  //1.翻译环境,在这个环境中的源代码被转换为可执行的机器指令
  //2.执行环境,它用于实际执行代码
//二.程序的翻译环境
    //源文件->编译器->目标文件->链接器(链接库)->可执行程序
    //·组成一个程序的每个源文件通过编译过程分别转换成目标代码(ofject code)
    //·每个目标文件有链接器（linker）捆绑在一起，形成一个单一而完整的可执行程序。
    //·链接器同时也会引入标准c函数库中任何被改程序所用到的函数，而且它可以搜索程序员个人的程序库将其需要的函数也链接到程序中

//三.程序的执行环境
    //详解：c语言程序的编译+连接
    //test.c                            test.ext
    //                 翻译环境           运行环境
    //    编译(编译器)      链接(链接器)
    //预编译  编译   汇编 （生成目标文件通过链接处理最后生成可执行程序）
//.c  预处理阶段(*.i)  编译(*.s)   汇编(*.o)     链接
//      预处理指令    语法分析      形成符号表    合并段表
//                  词法分析     汇编指令->    符号表合并
//                  语义分析    二进制指令     符号表重定位
//                  符号汇总
//多文件隔离编译，一起链接
    //1.预处理 gcc -E test.c 预处理后的结果放在test.c文件中
    //2.编译 gcc -S test.c 编译成汇编放到test.s文件中
    //3.汇编 gcc -C test.c 编译成二进制指令放到test.c文件中

//四.预定义符号介绍
//int main(int argc, const char * argv[]) {
//    printf("%s\n", __FILE__);//当进行编译的源文件路径
//    printf("%d\n",__LINE__);//文件当前行号
//    printf("%s\n",__DATE__);//文件被编译的日期
//    printf("%s\n",__TIME__);//文件被编译的时间
//    printf("%s\n",__FUNCTION__);//当前函数
//    printf("%d\n",__STDC__);//如编译器遵循ANSI C 返回1
//    return 0;
//}

//五.预处理指令#define。以#开头的都是预处理指令
        //#define 是定义标识符
        //#include
        //#pragma pack（）
        //#if
        //#endif
        //#line
        //#iddef
#define MAX 100
#define STR "hehe"//所有类型数据
#define reg refister //为register关键字创建一个简短的名字
#define do_forever for(;;)//用更形象的符号来替换一种实现
#define CASE break; case//在写case语句的时候自动把break加上
//如果定义的stuff过长，可以分成几行写，除了最后一行外，每行的后面都讲一个反斜杠（换行符）
#define DEBUG_PRINT printf("file:%s\tline:%d\t \                            date:%s/ttime:%s\n", \
                           __FILE__,__LINE__,\
                           __DATE__,__TIME__)
int main()
{
    printf("%d", MAX);
    printf("%s\n", STR);
    DEBUG_PRINT;
    return 0;
}
//六.宏和函数的对比
//七.预处理操作符#和##的介绍
//八.命令定义
//九.预处理指令#include
//十.预处理指令#undef
//十一.条件编译

