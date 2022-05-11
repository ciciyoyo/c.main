//
//  main.c
//  5.01
//
//  Created by Rido on 2022/5/1.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
//c/c++程序内存分配的几个区域
    //栈区（stack);在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时，这些存储单元自动被释放，栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限，栈区主要存放运行函数而分配的局部变量。函数参数，返回数据，返回地址等
    //堆区（heap）一般由程序员分配释放，若程序员不释放，程序结束时可能由OS（操作系统）回收，分配方式类似于链表
    //数据段(静态区)(static)存放全局变量，静态数据。程序结束后由系统释放
    //代码段：存放函数体（类成员函数和全局函数的）的二进制代码，常量字符串也是放到这里面的

//一、动态内存管理malloc free callor realloc 需要引头文件stdlib.h
//栈区存放：局部变量，局部数组，函数的形参，
//堆区存放：动态内存分配 malloc  free  callor  realloc
//静态区：全局变量，全局数组，静态变量：（static创建的变量）

//二、为什么存在动态内存分配
//  int val = 20；在栈上开辟四个字节
//  char arr[10] = {0};在栈上开辟是个字节的连续空间
//上述开辟空间有两个特点
//  1.空间开辟大小是固定的
//  2.数组在申明的时候必须指定数组的长度，它所需要的内存在编译时分配
//但是对开空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，数组的方式就不能满足了。这时候就只能试试动态内存开辟
//malloc和free介绍
    //malloc开辟成功返回一个指向开辟好的空间指针
    //如果开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查
    //返回值的类型void*，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定
    //如果参数size为0，malloc的行为是标准的位定义的，取决于编译器
//free函数。专门是用来做动态内存的释放和回收的，函数原型如下
//    void free(void* ptr)//
    //如果参数ptr指向的空间不是动态开辟的，那free函数的行为时未定义的
    //如果参数ptr是NULL指针，则函数什么事都不做。
//void* malloc（size)需要引用头文件stdlib.h，没有空间返回空指针
//int main(int argc, const char * argv[]) {
//    //向堆内存申请10个整型的空间,返回这块空间的地址；
//    int* p = (int*) malloc(10*sizeof(int));
//    if (p == NULL)
//    {   //打印错误原因
//        printf("%s\n", strerror(errno));
//    }
//    else
//    {
//        int i;
//        for (i = 0; i < 10; i++)
//        {
//            *(p+i) = i;
//        }
//    }
//    //使用空间
//    int i;
//    for (i = 0; i < 10; i++) {
//        printf("%d\n", *(p+i));
//    }
//    //空间不再使用就要还回去free
//    free(p);
//    //空间还回去了可指针变量此时还是指向那个地址所以需要
//    p = NULL;
//    //程序结束后空间也会自动回收
//    return 0;
//}

//calloc函数功能是为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0
//与函数malloc的区别只在于calloc会在返回地址之前把申请的空间的每个字节初始化为0
//void* calloc(size_t num , size_t size)
//int main()
//{
//    int* p = (int*)calloc(INT_MAX, 4);//INT_MAX引用头文件limits
//    if (p == NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    else
//    {
//        int i;
//        for (i = 0; i < 5; i++)
//        {
//            printf("%d\n", p[i]);
//        }
//    }
//
//    free(p);
//    p = NULL;
//    return 0;
//}

//realloc函数的出现让动态内存管理更加灵活
//有时侯我们发现过去申请的空间太小了，有时侯我们又觉得空间过大了，那为了合理的使用内存，我们一定会对内存的大小做灵活的调整，那realloc函数就可以做到对动态开辟的内存大小的调整了。原型如下
//void* reclloc(void* ptr， void* size)
    //ptr是要调整的内存地址
    //size 调整之后的大小
    //返回值为调整之后的内存起始位置
    //这个函数调整原内存空间大小的基础上，还会将原内存中的数据移动到新空间
    
//int main()
//{
//    //使用calloc开辟了10个4个字节的空间
//    int* p = (int*) calloc(10, 4);
//    if (p == NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    else
//    {
//        int i;
//        for (i = 0; i < 10; i++)
//        {
//            p[i] = i;
//        }
//    }
//    //使用realloc来调整动态开辟的内存
//    //realloc在调整内存空间时存在两种情况
//        //1.如果p指向的空间之后有足够的内存空间，则直接追加返回原来的地址
//        //2.如果p指向的空间之后没有足够的内存空间，则realloc函数会重新找一块内存区域，开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间，最后返回新内存空间的地址
        //所以得用一个新的变量来接收realloc函数的返回值
    //3.如果realloc的第一个参数传一个空指针NULL可以实现malloc功能
//    int * new_p = realloc(p, 80);//新空间的内容时随机值
//    if (new_p == NULL)
//    {
//        new_p = p;
//    }
//    int i;
//    for (i = 0; i < 20; i++)
//    {
//        printf("%d\n",new_p[i]);
//    }
//    free(new_p);
//    new_p = NULL;
//    return 0;
//}

//常见的动态内存错误
//对空指针的解引用操作
//void test1(void)
//{
//    int *p = (int*) malloc(INT_MAX);
//    *p = 20;//如果p的值是NULL，就会有问题
//    free(p);
//}
////对动态开辟空间的越界访问
//void test2(void)
//{
//    int i;
//    int *p = (int*) malloc(10*sizeof(int));
//    if (p == NULL)
//        exit(EXIT_FAILURE);
//    else
//    {
//        for (i = 0; i<= 10; i++)
//            *(p+1) = i;//当i是0的时候越界访问
//    }
//    free(p);
//}
////对非动态开辟的内存使用free释放
//void test3(void)
//{
//    int a = 10;
//    int *p = &a;//是在栈空间开辟的
//    free(p);//释放堆空间的
//}
////使用free释放一块动态开辟内存的一部分
//void test4(void)
//{
//    int *p = (int*) calloc(25, 4);
//    p++;
//    //free只能从起始位置来释放
//    free(p);//p不再指向动态内存的起始位置
//}
////对同一块内存多次释放
//void test5(void)
//{
//    int *p = (int*) malloc(20);
//    free(p);
//    free(p);//重复释放
//}
////对动态开辟的空间忘记释放(内存泄漏)
//void test6(void)
//{
//    malloc(4);
//}
//int main()
//{
//    printf("%s", strerror(errno));
//    test5();
//    return 0;
//}

//栈，堆， 静态区问题
//指针变量进行值传递，实参赋值给形参，会在栈区申请一个局部的指针变量，和外面实参是两个变量
//void getmemory(char *p)
//{
//     p =(char *) malloc(100);
//      strcpy(p, "hello world");
//}
//int main()
//{
//    char *str= NULL;
//     getmemory(str);
//     printf("%s",str);  //一直未NULL，多次调用会造成内存空间泄漏，无法释放
//     free(str);
//     return 0;
//}

//返回栈空间地址问题
//char * get(void)
//{
//    char p[] = "rido";//栈区开辟的数组，出了函数就会被销毁
//    return p;
//}
//void test(void)
//{
//    char * p = NULL;
//    p = get();//此时p所指向的空间是什么不确定（非法访问内存）野指针
//    printf(p);
//}
//static修饰的局部变量变成了静态区的了
//int * test()
//{
//    static int a= 10;//静态区的开辟的，程序结束才会销毁
//    return &a;
//}
//int main()
//{
//    int* ptr = test();
//    *ptr += 20;
//    printf("%d",*ptr);
//    return 0;
//}

//int * test()
//{
//堆区开辟的没有free空间还在，ptr变量会在函数结束销毁之前，返回地址
//    int* ptr = malloc(100);
//    return ptr;
//}
//int main()
//{
//    int* ptr = test();
//    *ptr = 20;
//    printf("%d",ptr[0]);
//    free(ptr);
//    ptr = NULL;
//    return 0;
//}

//int * f2(void)
//{
//    int *ptr;//指针未初始化是随机值
//    *ptr = 20;//改变随机地址会出问题（野指针）
//    return ptr;
//}
void test(void)
{
    char *str = (char*)malloc(100);//在堆区开辟100个字节
    strcpy(str, "ridoisil");//把字符串拷贝到里面
    free(str);//释放这块空间此时str此时通过str还是可以找到(野指针）
    if (str != NULL)
    {
//        strcpy(str, "hello");//强行找地址把ridoisli覆盖掉
        printf("%s\n", str);
    }
}
int main()
{
    test();
    return 0;
}


//void test(char * i)
//{
//    printf("%s\n", i);
////    printf("%s", i);
////    *i = 'w';
////    printf("%s\n", i);
//
//}
//int main()
//{
////    char* p =NULL;
////    test(p);
//    char p[5] = "hell";
//    printf(p);
//    printf("%p\n", p);
////    *c = 'w';
////    c = "rido";
//    printf("%s\n", c);
//    return 0;
//}

