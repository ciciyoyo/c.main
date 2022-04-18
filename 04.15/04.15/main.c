//
//  main.c
//  0414
//
//  Created by Rido on 2022/4/15.
//

#include <stdio.h>
//指针详解
//int main(int argc, const char * argv[]) {
////    char arr1[] = "abcdef";
////    char* p1 = arr1;
////    printf("%s\n", p1);
////    printf("%c\n", *p1);
////    printf("%s\n", arr1);
////    printf("%c\n", *arr1);
//    const char* p2 = "rido";//rido常量字符串 /const修饰*p
//    printf("%s\n", p2);
//    printf("%c\n", *p2);
////    *p2 = 'l';//报错改不了
//    printf("%s\n", p2);
//
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
//int main()
//{
//    char arr1[] = "asdzxc";
//    char arr2[] = "asdzxc";
//    char* p1 = "asdzxc";//p1和p2地址一样
//    char* p2 = "asdzxc";
//    if (arr1 == arr2)
//        printf("hrhr");
//    else
//    {
//        printf("haha\n");
//        printf("%p\n", &arr1);
//        printf("%p\n", &arr2);
//    }
//    char** p3 = &p1;
//    char** p4 = &p2;
//    printf("p3 =%p\n", p3);
//    printf("p4 =%p\n", p4);
////    if (p1 == p2)
////    {
////        printf("haha\n");
////        printf("%p\n", p1);
////        printf("%p\n", p2);
////    }
////    else
////        printf("hehe\n");
//    return 0;
//}
//指针数组：是用来存放指针的
//int main()
//{
//    int a[4] = {1, 2, 3, 4};
//    int b[4] = {5, 6, 7, 8};
//    int arr[10] = {0};//整形数组
//    char arr2[5] = "asdf";//字符数组
//    int* arr3[5]; //存放整形指针数组-指针数组
//    char* arr4[4]; //存放字符指针的数组-指针数组
//    int* parr[2] = {a, b};//parr[2]是包含2个元素的数组，每个元素是int*类型的
//
////数组指针
//    int c = 5;
//    int *pc = &c;
//    int arr5[10] = {0};
//    int(*parr1)[10] = &arr5;//*parr1是指针，指向10个元素的地址，每个元素是int类型
//    printf("%p", parr1);
//
//    return 0;
//}
//测试1
//int main()
//{
//    char a[] = "rido";
//    char b[] = "is";
//    char c[] = "goodd";
//    char d[] = "man";
//    char* arr[5]= {a, b, c, d};
//    char*(*pa)[5] = &arr;//首先确定&arr是个地址，
//    //需要用指针*pa接收，这个地址指向的是5个元素的数组加上[5],然后每个元素是int*类型
//    printf("%c\n",*(*pa)[0]);
//    return 0;
//}
//用法,一般都是用到二维数组以上才会方便些
//int main()
//{
//    //例1
////    int arr[10] = {1,2,3, 4, 5, 6, 7, 8, 9, 10};
////    int (*pa)[10] = &arr;
//////    printf("%d",(*pa)[1]);
////    int i;
////    for (i = 0; i < 10; i++)
////    {
////        printf("%d\n", (*pa)[i]);
////    }
////    printf("%p\n", arr);
//    return 0;
//}
//例2
//void print1(int arr[3][4], int x, int y)
//{
//    int i;
//    int j;
//    for (i = 0; i < x; i++)
//    {
//        for (j = 0; j < y; j++)
//            printf("li1=%d",arr[i][j]);
//        printf("\n");
//    }
//}
void print2(int(*arr)[4],int x,int y)//这里*arr数组指针指向{1,2,3,4}
{
    int i;
    int j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
//            printf("%d", arr[i][j]);//等价
//            printf("%d", *(arr[i]+j));//等价
//            printf("%d",(*(arr+i))[j]);//等价
            printf("%d", *(*(arr+i)+j));//等价
        }
        printf("\n");
    }
}
int main()
{
    int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,9,9,9}};
//    print1(arr, 3, 4);//arr首元素地址,先把arr想象成一维数组{1,2,3,4}是首元素，相当于&{1,2,3,4}
    print2(arr, 3, 4);
    return 0;
}

//int main()
//{
////    int ar [5] = {6, 7, 8, 9, 10};
//    int arr[3][4] = {{1,2,3,4},{2,3,4,5},{3,4,5,6}};
////    int* par = ar;
//    int(*parr)[4] = arr;
////    printf("%d", par);
//    printf("%d", *(*parr));//*parr解引用找到的是1的地址所以在*解引用下才能打印1
//  总结
//int arr[10] = [int,int...];"数组：arr是五个整形元素的数组"
//int *parr1[10] ={p,p...};"指针数组：parr1是十个(int*)类型的数组"
//int (*parr2)[10] = {arr};"数组指针：parr2是指向十个int类型的数组"
//int (*parr3[10])[5];
//"数组,有十个数组,每个数组又是指针数组,每个指针指向数组5个元素,每个元素为int"
//    return 0;
//}

