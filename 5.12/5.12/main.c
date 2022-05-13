//
//  main.c
//  5.12
//
//  Created by Rido on 2022/5/12.
//

#include <stdio.h>
#include <stdlib.h>
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
//四.详解：c语言程序的编译+连接
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

//五.预定义符号介绍
//int main(int argc, const char * argv[]) {
//    printf("%s\n", __FILE__);//当进行编译的源文件路径
//    printf("%d\n",__LINE__);//文件当前行号
//    printf("%s\n",__DATE__);//文件被编译的日期
//    printf("%s\n",__TIME__);//文件被编译的时间
//    printf("%s\n",__FUNCTION__);//当前函数
//    printf("%d\n",__STDC__);//如编译器遵循ANSI C 返回1
//    return 0;
//}

//六.预处理指令#define。以#开头的都是预处理指令
    //#define定义标识符
        //#define 是定义标识符
        //#include
        //#pragma pack（）
        //#if
        //#endif
        //#line
        //#iddef
#define MA 100
#define STR "hehe"//所有类型数据
#define reg refister //为register关键字创建一个简短的名字
#define do_forever for(;;)//用更形象的符号来替换一种实现
#define CASE break; case//在写case语句的时候自动把break加上
//如果定义的stuff过长，可以分成几行写，除了最后一行外，每行的后面都讲一个反斜杠（换行符）
#define DEBUG_PRINT printf("file:%s\tline:%d\t                             date:%s/ttime:%s\n", \
                           __FILE__,__LINE__,\
                           __DATE__,__TIME__)
//int main()
//{
//    printf("%d", MAX);
//    printf("%s\n", STR);
//    DEBUG_PRINT;
//    return 0;
//}
   
//七.宏和函数的对比 #define定义宏
    //#define还可以定义宏(宏是替换的不是穿参的）
    //#define机制包括一个规定，允许把参数替换到文本中，这种实现通常称为宏（macro）或定义宏（define macro
    //宏声明方式
    //#define name(parament-list) stuff 其中的parament-list 是一个由逗号隔开的符号表，它们可能出现在stuff中
    //注意：参数列表的左括号必须与name紧邻。如果两者之间有任何空白存在，参数列表就会被解释为stuff的一部分
    //#define替换规则 需要涉及几个步骤
        //1.在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号，如果是，它们首先被替换
        //2.替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被它们的值替换
        //3.最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号。如果是，就重复上述处理过程
    //注意：
        //1.宏参数和#define定义中可以出现其他#define定义的变量，但是对于宏，不能出现递归。
        //2.当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索
#define SQUARE(x) ((x)*(x))//不要吝啬括号
#define DOUBLE(y) y+y
//int main()
//{
//    int ret;
//    ret = 10 * DOUBLE(SQUARE(2+1));//99首先替换SQUARE
//    printf("%d\n", ret);
//    printf("%d", ret);
//    return 0;
//}

//八.预处理操作符#和##的介绍
    //如何把参数插入到字符串中？#的作用
        //这里#A不会被替换成值，而是双引号的变量名
#define PRINT(A) printf("the value "#A" is %d\n", A)
//int main()
//{
//    int a = 10;
//    int b = 20;
//    PRINT(a);
//    PRINT(b);
//    return 0;
//}
    //##的作用
        //可以把位于它两遍的符号合成一个符号。它允许宏定义从分离的文本片段创建标识符
        //注：这样的链接必须产生一个合法的标识符。否则结果就是为定义的
#define CAT(X, Y) X##Y
//int main()
//{
//    int rido66 = 999;
//    printf("%d\n",CAT(rido,66));//X=rido, Y=66
//    return 0;
//}
    //带副作用的宏参数
        //当宏参数在宏的定义中出现超过一次的时候，如果参数带有副作用，那么在使用的时候可能出现不可预测的后果。副作用就是表达式求值的时候出现的永久性效果。例如：
            //x+1   不带副作用
            //x++   带有副作用
#define MAX(X,Y) (X)>(Y)?(X):(Y)
//int main()
//{
//    int a = 10;
//    int b = 11;
//    float c = 36.4f;
//    float d = 5.1f;
////    int max = MAX(a++,b++);//直接替换，不会计算好在替换
//    printf("%f\n", MAX(c,b));
//    printf("%d\n", a);
//    printf("%d\n", b);
//    return 0;
//}
    //宏与函数对比
        //宏通常被应用于执行简单的运算。比如在两个数中找出最大的一个
        //不用函数完成有两个原因
            //1.用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作还要久，所以宏在规模和速度方面更胜一筹
            //2.更为重要的是函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用，反之宏可以适用于整形，长整形，浮点型等可以用><来比较类型。宏是类型无关的
        //当然和宏相比函数也有劣势的地方
            //1.每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序长度
            //2.宏是没法调试的
            //3.宏由于类型无关，也就不够严谨
            //4.宏可能会带来运算符优先级的问题，程序容易出错
        //宏有时候可以做到函数做不到的事情，比如：宏的参数可以出现类型，但是函数做不到
#define MALLOC(TYPE, NUM) (TYPE*)malloc(sizeof(TYPE) *NUM)
//int main()
//{
//    //使用
//    int* par = MALLOC(int, 10);//类型作为参数
//    //预处理替换之后
////    （int*) malloc(sizeof(int)*10);
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        par[i] = i;
//    }
//    for (i = 0; i < 10; i++)
//    {
//        printf("%d\n", par[i]);
//    }
//    printf("%d", MA);
//#undef MA
////    printf("%d", MA);
//    free(par);
//    par = NULL;
//    return 0;
//}
    //命名约定
        //一般来讲函数和宏的使用语法很相似，所以语言本身没发帮我们区分二者。那我们平时的一个习惯是：
            //把宏的名全部大写，函数名不要全部大写
    //undef
        //这条指令用于移除一个宏定义或标识符
//九.命令行定义
    //许多c的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。例如：当我们根据同一个源文件要变异处不同的一个程序的不同版本的时候，这个特性优点用处（假定某个程序中声明了一个某个长度的数组，如果机器内存有限，我们需要一个很小的数组，但是另外一个机器内存大一些，我们需要一个数组能够大些
    //linux 系统下 gcc -D SZ = 10 test.c
//int main()
//{
//    int arr[SZ] = {1,2,3,4,5,6,7,8,9,0};
//    int i;
//    for (i = 0; i < SZ; i++)
//    {
//        arr[i] = i;
//    }
//    for (i = 0; i < SZ; i++)
//    {
//        printf("%d", arr[i]);
//    }
//    return 0;
//}
    //条件编译
        //在编译一个程序的时候我们如果要将一条语句（一组语句）编译或者放弃是很方便的因为我们有条件编译指令 比如说：
            //调试性的代码，删除可惜，保留又碍事，所以我门可以选择性编译
    //常见的条件编译指令：
        //1.
            //#if 常量表达式
                //.....
            //#endif
            //常量表达式由预处理器求值
            //如：
            //#define __DEBUG__ 1
            //if __DEBUG__
                //...
            //endif
        //2.多分枝的条件编译
            //#if 常量表达式
                //。。。
            //#elif
                //。。。
            //#else
                //。。。
            //#endif
        //3.判断是否被定义
            //if defined(symbol)
            //ifdef symbol
            //if !defined(symbol)
            //ifndef symbol

    
#define DBUG //只要定义可就行，可以不给值
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    int i;
    for (i= 0; i < 10; i++)
    {
        arr[i] = 0;
#if 1==11//条件表达式为真执行，假则反之
        printf("haha");
#elif 1==1
        printf("hehe\n");
#else
        printf("rido")
//#ifdef DBUG //如果DBUG定义过就执行下面代码 否则不执行
        printf("%d\n", arr[i]);//预处理的时直接干掉了
#endif//根ifdef是一对，是用来结束iddef的
    }
    printf("%d\n",DEBUG);
    return 0;
}
//十.预处理指令#include
//十一.预处理指令#undef
//十二.条件编译

