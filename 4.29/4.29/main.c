//
//  main.c
//  4.29
//
//  Created by Rido on 2022/4/29.
//

#include <stdio.h>
#include <stddef.h>
//结构体进阶

//匿名结构体1
//struct{

//    char name[20];
//    int age;
//}x;

//链表2
//结构体的自引用
//struct Node
//{
//    int data;//数据域
//    struct Node* next;//指针域
//};

//结构体的重命名3
//typedef struct Stu
//{
//    int data;
////    Stu* n2;//必须使用'struct'标签来引用类型'Stu'
//    struct Stu* n3;
//    char name[5];
//}Stu;

//结构体变量的定义和初始化4
//struct t
//{
//    double w;
//    int b;
//};
//struct S
//{
//    char c;
//    struct t st;
//    double d;
//    int a;
//    char name[20];
//}S1;//声明的同时定义一个结构体变量N1。是全局变量

//结构体内存对齐 5
//对齐原则：
//1.第一个成员在于结构体变量偏移量为0的地址处。
//2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处
//（对齐数： 编译器默认的一个对齐书与该成员大小的较小值，本机默认8）
//3.结构体总大小为最大对齐书（每个成员变量都有一个对齐数）的整数倍
//4如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整倍数
//为什要存在内存对齐
//1.平台原因(移植原因)
//不是所有的硬件平台都能访问任意地址上的任意数据的某些硬件平台在某些地址处取某些特定类型的数据，否则抛出硬件异常
//2.性能原因：数据结构（尤其是栈）应该尽可能的在自然边界上对齐。原因在于，为了访问未对齐的内存，处理器需要做两次内存访问；而对齐的内存访问仅需要一次访问。
//总体来说：结构体的内存对齐是拿空间来换取时间的做法
//原则一：结构体中元素是按照定义顺序一个一个放到内存中去的，但并不是紧密排列的。从结构体存储的首地址开始，每一个元素放置到内存中时，它都会认为内存是以它自己的大小来划分的，因此元素放置的位置一定会在自己宽度的整数倍上开始（以结构体变量首地址为0计算）
//原则二：在经过第一原则分析后，检查计算出的存储单元是否为所有元素中最宽的元素的长度的整数倍，是，则结束；若不是，则补齐为它的整数倍。
//struct S
//{
////    char c;
//    double d;
//    char a;
////    char name[20];
//    int c;
//};
//struct S4
//{
////    char c;
//    short d;
//    char a;
//    struct S s6;
//    char name[13];
//    int c;
//};

//修改默认对齐数#pragma pack(4)
//offsetof(结构体类型名,成员名)不是函数是宏需要引用头文件<stddef.h>
//用来计算结构体成员相对于结构体起始位置的偏移量
//#pragma pack(4)//设置默认对齐数是4
//struct S1
//{
//    char a;
//    double b;
//};
//#pragma pack()//取消对默认的设置
//
//
//int main(int argc, const char * argv[]) {
    //step 5
//    struct S1 s1 = {0};
//    printf("%lu\n",offsetof(struct S1, b));
//    printf("%d", sizeof(s1));
//    //step 4
//    struct S S2 = {0}//将成员全部默认初始化成0
//    struct S S2 = {'l',{2.1,5}, 3.14, 33, "rido"};//结构体成员的初始化
//    printf("%c %lf %lf %d %s\n", S2.c,S2.st.w,S2.d,S2.a,S2.name);//结构体成员的访问
//    step 3
//    Stu n1;
//    char arr[5] = "rido";
//    n1.data = 33;
//    printf("%d\n", n1.data);
//    return 0;
//}

//结构体传参
struct S
{
    char c;
    int i;
    double d;
//    char arr[10];
//    int arr1[10];
};
#pragma pcak(4)
void Init(struct S* s)//传址操作给结构体变量初始化
{
    (*s).c = 'r';
    s->i = 33;
    s->d = 3.14;
}
#pragma pack()
void print(struct S s)//传值操作不会改变源内容
{
    s.i  = 18;
    printf("%c %d %lf\n", s.c, s.i, s.d);
}
int main() {
    struct S s1 = {0};
    Init(&s1);//因为是结构体变量名所以要&
//    s1.c = 'r';
//    s1.i = 20;
//    s1.d = 3.14;
//    s1.arr = "rido";
    print(s1);
    printf("%d\n", s1.i);
    printf("%lu\n", offsetof(struct S, i));
    printf("%lu\n", sizeof(s1));
    return 0;
}
