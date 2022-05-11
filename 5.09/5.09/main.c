//
//  main.c
//  5.09
//
//  Created by Rido on 2022/5/9.
//

#include <stdio.h>
#include <stdlib.h>
//柔性数组
    //也许你从未听说过柔性数组（flexible array）这个概念，但是它确实存在的。c99中，结构中的最后一个元素允许是未知大小的数组，这就叫做柔性数组成员
//特点
    //1.结构中的柔性数组成员前面必须至少一个其他成员
    //2.sizeof返回的这种结构大小不包括柔性数组的内存
    //3.包含柔性数组成员的结构用malloc函数进行内存的动态分配，并且分配的内存应该大于结构大小，以适应柔性数组的预期大小
//好处
    //1.方便内存释放
    //2.有利于访问速度，减少内存碎片
//#pragma pack()
//struct S
//{
//    char n;
////    int *p;
//    int arr[];//数组大小可以调整的
////    int arr1[0];柔性数组成员(形式不一样，意义是一样的）
//};
//#pragma pack()
//柔性数组
//int main(int argc, const char * argv[]) {
////    struct S s1;
////    printf("%d", sizeof(s1));//计算大小的时候不包含这个柔性数组成员
//    struct S* ps = (struct S*)malloc(sizeof(struct S)+5*sizeof(int));//申请动态空间
//    ps->n = 'w';
//    int i;
//    for (i = 0; i <5; i++)
//    {
//        ps->arr[i] = i;
//    }
//    struct S* ptr = realloc(ps, sizeof(struct S)+10*sizeof(int));//扩容动态空间
//    if (ptr !=NULL)
//    {
//        ps = ptr;
//    }
//    for (i = 5; i< 10;i++)
//    {
//        ps->arr[i]= i;
//
//    }
//    for (i = 0; i< 10;i++)
//    {
//        printf("%d\n", ps->arr[i]);
//
//    }
//    printf("%c", ps->n);
//free(ps);
//ps = NULL;
//    return 0;
//}
//还可以这么写67

typedef struct S
{
    char c;
    int* p;
}Stu;
int main()
{
    Stu* ps = (Stu*)malloc(sizeof(Stu));
    ps->p = (int*)malloc(20);
    int i;
    for (i = 0; i< 5; i++)
    {
        ps->p[i] = i;
        
    }
    int* ptr = (int*)realloc(ps->p, 40);
    if (ptr != NULL)
    {
        ps->p = ptr;
    }
    for (i = 5; i< 10; i++)
    {
       ps->p[i] = i;
        
    }
    for (i = 0; i< 10; i++)
    {
       printf("%d", ps->p[i]);
        
    }
    free(ps->p);
    ps->p = NULL;
    free(ps);
    ps = NULL;
    return 0;
}
