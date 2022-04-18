//
//  04.c
//  04.17
//
//  Created by Rido on 2022/4/18.
//

#include "04.h"
#include <stdio.h>
int add(int x, int y)
{
    return x+y;
}
int sub(int x, int y)
{
    return x-y;
}
int mul(int x, int y)
{
    return x*y;
}
int dva(int x, int y)
{
    return x/y;
}void cpfa(int(*pf)(int, int))
{
    int x;
    int y;
    printf("请输入您要计算的两个数字\n");
    scanf("%d%d", &x, &y);
    printf("结果是%d\n",pf(x,y));
}
void meu(void)
{
    printf("***************************\n");
    printf("**** 1.add       2.sub ****\n");
    printf("**** 3.mul       4.dva ****\n");
    printf("*****      0.exit      ****\n");
    printf("***************************\n");
}
int main()
{
//    int x;
//    int y;
    short input;
    //指针数组，这种方式又叫转移表
//    int(*ptr[5])(int, int)= {0, add, sub, mul, dva};
    do
    {
        
        meu();
        printf("请输入运算符号数字");
        scanf("%hd",&input);
        
//        if (input >0 && input <=4)
//        {
//            printf("请输入您要计算的数字\n");
//            scanf("%d%d", &a, &b);
//            int ret = ptr[input](a, b);
//            printf("结果是%d\n", ret);
//        }else if( input == 0)
//        {
//            printf("退出\n");
//        }else {
//            printf("输入有误\n");
//        }
        
        //switch办法解决麻烦考虑函数指针，还可以用回调函数
        //回调函数
        //就是通过函数指针调用的函数，如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向函数时，我们就说这是回调函数。会调函数不是由该函数的实现方直接调用，而是在特定的时间内或条件发生时由另外一方调用的，用于该事件或条件进行响应
        switch (input)
        {
        case 1:
                cpfa(add);
//                printf("请输入您要计算的两个数字\n");
//                scanf("%d%d", &x, &y);
//                printf("结果是%d\n",add(x,y));
            break;
        case 2:
                cpfa(sub);
//                printf("请输入您要计算的两个数字\n");
//                scanf("%d%d", &x, &y);
//                printf("结果是%d\n",sub(x,y));
            break;
        case 3:
                cpfa(mul);
//                printf("请输入您要计算的两个数字\n");
//                scanf("%d%d", &x, &y);
//                printf("结果是%d\n",mul(x,y));
            break;
        case 4:
                cpfa(dva);
//                printf("请输入您要计算的两个数字\n");
//                scanf("%d%d", &x, &y);
//                printf("结果是%d\n",dva(x,y));
            break;
            case 0:
                printf("退出\n");
                break;
        default :
                printf("输入有误\n");
                break;
        }
    } while(input);
    return 0;
}
