//
//  main.c
//  04.16
//
//  Created by Rido on 2022/4/16.
//

#include <stdio.h>
////一维数组传参，指针传参
//void test(int arr[])//ok
//{}
//void test(int arr[10])//ok这个10没有意义写错了也可以
//{}
//void test(int *arr)//ok用指针来接收arr首元素的地址
//{}
//void test2(int *arr[20])//ok有20个元素每个元素是int*
//{}
//void test2(int **arr)//ok意思是用二级指针来接收*arr2里面的首元素
//{}
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    int arr[10] = {0};
//    int *arr2[20] = {0};
//    test(arr);
//    test(arr2);
//    return 0;
//}
//err一个一级整形指针的变量接受不了一个数组指针
//void test(int *arr)
//{}
////ok行可以省略，但是列省略却不可以
//void test(int arr[][5])
//{}
////no 表示5个指针数组表示不了一个二维的
//void test(int* arr[5])
//{}
////ok 传过来第一行的地址，五个整形元素的一维元素地址
//void test(int (*arr)[5])
//{}
////err二级指针接收不了一个指针数组只能接收一级指针的变量
//void test(int **arr)
//{}
////总结到一起就是指针类型不一样
//int main()
//{
//    int arr[3][5] = {0};
//    test(arr);
//    return 0;
//}
void test(int** p)
{}
int main()
{
    int *ptr;
    int* arr[10];
    int** arrr = &arr;
    test(arr);//都是可以的，这里是取arr的首地址，即int*地址
    test(&ptr);//ok
    test(arrr);
    return 0;
}
