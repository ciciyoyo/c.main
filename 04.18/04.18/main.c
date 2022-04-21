//
//  main.c
//  04.18
//
//  Created by Rido on 2022/4/18.
//
#include <stdio.h>
//指向函数指针数组的指针
//int add(int x, int y)
//{
//    return x + y;
//}
//int main(int argc, const char * argv[]) {
//    //指针总结
//    int a = 10; //变量
//    int *p = &a; //指针
//    int *ps = "asdzcx"; //把常量字符串里面的'a'字符放到ps指针里面，常量字符串不可以改，而字符数组是可以改的
//    int* *pp = &p;//二级指针...
//
//    int arr[10] = {0};//数组
//    int (*par)[10] = arr;//&arr/数组指针
//    int* parr[10] = &par;//指针数组
//    int* (*parrr)[10] //指针数组的指针（二级指针）...
//    int* (*(*parrrr))[10] //指针数组指针（三级级指针）...
//
//    add(5, 6);  //函数,对一个函数取地址没有作用，因为函数名就是地址
//    int (*pad)(int,int) = &add;//函数指针
//    int (*(*padd))(int,int)= &pad;//函数指针的二级指针
//    int (*(*(*paddd)))(int,int)= &pad;//函数指针的三级指针...
//
//    int (*par[5])(int,int); //函数指针数组
//    int (*(*parr)[5])(int, int);//函数指针数组的指针 二级指针
//    int (*(*(*parrrr))[5])(int, int);//函数指针数组指针的指针 三级指针
//    printf("Hello, World!\n");
//    return 0;
//}

//回调函数
//就是通过函数指针调用的函数，如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向函数时，我们就说这是回调函数。会调函数不是由该函数的实现方直接调用，而是在特定的时间内或条件发生时由另外一方调用的，用于该事件或条件进行响应
//void print(char * str)
//{
//    printf("rido:%s\n",str);
//}
////void test(void p(char*))//这里使用变量接受函数
////{
////    p("asd");
////}
//void test(void (*p)(char*))//这里使用指针接受函数
//{
//    (*p)("asd");//回调函数
//}
//int main()
//{
////    char str[10] = "is good man";
//    test(print);
//    return 0;
//}
//万能指针 void*
//void*可以接受任意类型的地址
//void*对它解引用会报错，因为电脑不知道要访问几个字节
//p++ 以为是不可以的，因为电脑不知道一次加加跳过几个字节
//可以用强制类型转换对其解引用操作
int main()
{
    int a = 10;
    void* p = &a;
//    *p = 20;//Incomplete type 'void' is not assignable
    *(int*)p = 20;
//    void(*(*b))() = (void(*)())0;
    printf("%d",a);
    return 0;
}
