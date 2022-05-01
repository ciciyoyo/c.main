//
//  main.c
//  4.30
//
//  Created by Rido on 2022/4/30.
//

#include <stdio.h>
#include <stddef.h>
//位段(二进制位）
//一般用于数据包的封装
//结构体讲完就得讲讲结构体实现位段的能力
//什么是位段
//位段的声明和结构是类似的，有两个不同
//1.位段的成员必须是int unsigned int, 或signed int（实验发现不仅仅这三个，只要是整型就可以）基本上成员类型都一样
//2.位段的成员名后边有一个冒号和一个数字
//位段式结构体
//位段内存分配的规则、
//1、位段成员可以是int unsigned int signed int或者是char（属于整形家族）类型
//2、位段的空间上是按照需要以四个字节（int）或者1ge字节（char）的方式来开辟的。
//3、位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。
//位段跨平台问题
//1、int位段被当成有符号数还是无符号数不确定
//2.位段中最大位的树木不能确定（16位机器最大16，32位机器最大32）
//3.位段中的成员在内存中从左到右还是从右到左分配标准尚未定义。
//4.当一个结构包含两个位段，第二个位段成员较大，无法容纳第一个位段剩余位时，舍弃剩余的位还是利用，这是不确定的
//struct A
//{
//    //先开辟一个int类型的空间给它们用
//    int a:2;//只需要占2个比特位
//    int b:5;//只需要占5个比特位
//    int c:10;//只需要占10个比特位
//    int d:30;//只需要占30个比特位
////    int e:3;
//};
//struct C
//{
//    char _a: 3;
//    char _b: 4;
//    char _c: 5;
//    char _d: 4;
//};
//int main(int argc, const char * argv[]) {
////    struct A a;
//    struct C c;
//    c._a = 10;
//    c._b = 12;
//    c._c = 3;
//    c._d = 4;
//    printf("%lu", sizeof(c));
//    return 0;
//}

//枚举  是一种类型枚举类型
//顾名思义一一列举。列举把可能的取值一一列举
//枚举的优点
//1.增加代码的可读性和可维护性
//2.和#defind定义的标识符比较枚举有类型检查，更加严谨
//3.防治了命名的冲突（封装）
//4.便于调试
//5.使用方便，一次可以定义多个变量
//enum day//enum枚举关键字。day枚举类型名
//{
//    //枚举的可能取值
//    Mon,// 0 枚举常量
//    Tues,//1
//    Wed,//2
//    Thur,//3
//    Fri,//4
//    Sat,//5
//    Sun//6
//};
//enum Color
//{
//    Red = 2,//可以修改默认值
//    Green,///不赋值默认2+1
//    Blue = 6
//};
//int main()
//{
//    enum day d;
//    d = Tues;
//    printf("%d\n",d);
//    enum Color c;
//    c = Green;
//    printf("%d\n", c);
//    printf("%d\n", sizeof(d));
//    return 0;
//}

//联合-联合体-共用体
//联合类型的定义： 联合也是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合体也叫共用体）
//联合体的特点：成员共用一块内存空间的，这样一个连个变量的大小，至少是最大成员的大小（因为联合至少得优能力保存最大的那个成员）
//union Un//union 联合关键字 Un联合体类型名
//{
//    char c;//c在i里面
//    int i;//i在d里面
//    double d;//所以他们共用一块空间
//};
//struct S
//{
//    int a;
//    char c;
//    double d;
//};
//int main()
//{
//    struct S s;
//    union Un u;//联合体变量名
//    printf("%lu\n", sizeof(u));//取共用体里面最大成员的大小
//    printf("%p\n", &u);
//    printf("%p\n", &(u.c));//三个指向一个地址
//    printf("%p\n", &(u.i));
//    printf("%p\n", &(u.d));
//    u.c = 'a';
//    printf("%d\n",u.c);
//    printf("%d\n",u.i);
//    printf("%lu\n", offsetof( union Un, d));
//    return 0;
//}

//联合体大小的计算
//1.联合体的大小至少是最大成员的大小
//2.当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整倍数
union Un
{
    int a;//4 8 对齐数是4
    //对数组计算对齐数的时候是按元素的大小计算的
    char c[5];//5 1 8 对齐数是1
};
int main()
{
    union Un u;
    printf("%d", sizeof(u));
    return 0;
}

//使用联合体来判断机器是大端还是小端字节序存储
//int check_sys(void)
//{
//    union //匿名形式只能用一次
//    {
//        char c;
//        int i;
//    }u;//联合体变量名
//    u.i = 1;
//    u.c = 2;
//    return u.c;
//}
//int is_sys(void)
//{
//    int i = 1;
//    return *(char*)&i;
//}
//int main()
//{
//    //step 1
//    int a = 0x11223344;
//    char* p = (char*)&a;
//    //step 2
//    int ret = check_sys();
////    int ret = is_sys();
//    if (ret == 0)
//        printf("大端存储");
//    else
//        printf("小端存储");
//    printf("%x", *p);
//    return 0;
//}
