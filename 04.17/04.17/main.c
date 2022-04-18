//
//  main.c
//  04.17
//
//  Created by Rido on 2022/4/17.
//

#include <stdio.h>
#include <assert.h>
//函数指针
//int add(int x, int y)
//{
//    return x+y;
//}
//void Print(char * str)
//{
//    printf("%s", str);
//}
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    int a = 10;
//    int b = 20;
//    int c[] = {1,2,3,4,5};
//    add(a, b);
//
//    printf("Hello, World!\n");
//    printf("%p\n", add);//add等价&add
//    printf("%p\n", &add);
//    printf("%d\n", sizeof(add));//只占用了一个字节的空间
//    printf("%d\n", sizeof(a));
//    printf("%d\n", sizeof(b));
//    return 0;
//}
//函数指针用法
//int main()
//{
//    int (*ap)(int, int) = add;
//    printf("%d\n",(*ap)(3, 4));
//    void(*cp)(char*) = Print;
//    (*cp)("rido");
//    return 0;
//}
//有趣的代码
//int main()
//{
//    //代码1,void(*)()函数指针类型，把这个类型放到括号里面就是强制类型转换
//    //把0强制类型转换成函数指针类型，0就是一个函数的地址，对0解引用找到这个函数调用它
//    (*(void(*)())0)();
//    //代码2；
//    //函数声明signal有两个参数第一个为int 第二个为函数指针，该函数指针指向函数参数为int类型返回值为void，返回类型函数指针
//    void (*   signal(int,  void(*)(int))   )(int);
//    //也可以把函数指针换个名字，这样方便理解
//    typedef unsigned int uint;
//    typedef void(*pdf)(int);
//    pdf signal(int void(*)(int));//这样也是可以的
//    return 0;
//}

//指针函数调用时也可以不需要解引用
//int add(int x, int y)
//{
//    return x+y;
//}
//int main()
//{
//    int(*p)(int, int) = add;
//
//    printf("%d\n", p(2,3));
//    printf("%d\n", (*p)(2,3));
//    printf("%d\n", (**p)(2,3));
//    printf("%d\n", (***p)(2,3));
//    //这个解引用有没有都没有意义,因为函数调用本身就是用地址调用
//    printf("%p\n", p);
//    printf("%p\n", add);
//    //所以p 就是add
//    return 0;
//}
////函数指针数组
//int add(int x, int y)
//{
//    return x+y;
//}
//int sub(int x, int y)
//{
//    return x-y;
//}
//int mul(int x, int y)
//{
//    return x*y;
//}
//int dibv(int x, int y)
//{
//    return x/y;
//}
//int main()
//{
////    需要一个函数指针数组
//    int(*arr[4])(int,int) = {add, sub, mul, dibv};
//    int i;
//    for (i = 0; i <=3; i++)
//    {
//        printf("%d\n", (*arr[i])(6,2));
//
//    }
////    void(*arr[])(int);
//
//    return 0;
//}
//练习
//char* my_strpy(char* dest, const char* src)
//{
//    char* ret = dest;
//    assert(dest!=NULL);
//    assert(src != NULL);
//    while(*dest++ = *src++)
//   {
//     }
//    return ret;
//}
//int main()
//{
//    char strr[] ="asd";
//    char strrr[] = "zxc";
//    char*(*pf)(char*,const char*) = my_strpy;
//    char** ar = pf(strr,strrr);
//    printf("%s\n",ar);
//    return 0;
//    char* (*pfArr[4])(char*,const char*);//函数指针数组
//}
