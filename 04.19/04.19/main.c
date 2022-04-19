//
//  main.c
//  04.19
//
//  Created by Rido on 2022/4/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//qsort库函数用法
//第一个参数 待排序数组的首元素地址
//第二个参数 待排序数组的个数
//第三个参数 待排序数组的每个元素的大小-单位是字节
//第四个参数 是函数指针，比较两个元素的所用函数的地址-这个函数使用者自己实现
//           函数指针的两个参数时：待比较两个元素的地址
//struct stu {
//    char name[20];
//    int age;
//};
//int cmp_arr_int(const void* e1, const void* e2)
//{
//    return *(int*)e2 - *(int*)e1;
//
//}
//int cmp_stu_str(const void* e1, const void* e2)
//{
//    return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//void test(void)
//{
//    int i;
//    int arr[10] = {2, 3, 1, 5, 4, 6, 9, 8, 7, 10};
//    int sz = sizeof(arr)/sizeof(arr[0]);
//    qsort(arr, sz, sizeof(arr[0]), cmp_arr_int);
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d\n",arr[i]);
//    }
//}
//void test1(void)
//{
//    struct stu sdd[3] = {{"rido", 32},{"lier", 10},{"maomao", 31}};
//    int sz = sizeof(sdd)/ sizeof(sdd[0]);
//    qsort(sdd, sz, sizeof(sdd[0]), cmp_stu_str);
//}
//int main(int argc, const char * argv[]) {
//
////    test();
//    test1();
//    return 0;
//}
//自己实现一个qsort函数的用法
void swap(char* x, char* y, int sz)
{
    int tmp;
    int i;
    for (i = 0; i < sz; i++)
    {
        tmp = *x;
        *x= *y;
        *y = tmp;
        x++;
        y++;
    }
}
int cmp_all(void *e1,void *e2)
{
    return (*(int*)e1) - (*(int*)e2) ;
}
void bubble_sort(void* base,int num,int sz ,int(*cmp)(void *, void *))
{
    int i;
    for (i = 0; i < num-1; i++)
    {
        int j;
        for (j = 0; j < num-1-i; j++)
        {
            if(cmp((char*)base+j*sz,(char*)base+(j+1)*sz)>0)
            {
                swap((char*)base+j*sz,(char*)base+(j+1)*sz, sz);
            }
        }
    }
}

void test(void)
{
    int arr[10] = {2, 4, 3, 1, 5, 8, 7, 6, 10,9};
    int num = sizeof(arr) /sizeof(arr[0]);
    bubble_sort(arr, num, sizeof(arr[0]), cmp_all);
    int i;
    for (i = 0; i < num ; i++)
    {
        printf("%d\n", arr[i]);
    }
}
//测试自己做的
int cmp_fall(void*e1, void*e2)
{
   return (int)(*(float*)e1 - *(float*)e2);
}
void test1(void)
{
    float farr[10] = {4.3,2.2,5.4,6.5,7.6,6.3,2.7,3.8,1.5,4.9};
    int sz = sizeof(farr)/sizeof(farr[0]);
    bubble_sort(farr, sz, sizeof(farr[0]), cmp_fall);
    int i;
    for (i = 0; i < sz ; i++)
    {
        printf("%lf\n", farr[i]);
    }
    
}
int main()
{
    test();
    test1();
    return 0;
}
