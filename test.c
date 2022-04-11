//
//  test.c
//  demo
//
//  Created by Rido on 2022/4/6.
//
#include "test.h"
#include <stdio.h>
//结构体练习
typedef struct Sli
{
    int x;
    int y[5];
    char c[5];
    
}S1;

void print(S1 tem)
{
    printf("%d\n", (&tem)->x);
    printf("%d\n", tem.y[3]);
    printf("%s\n", tem.c);
}
void printc(S1* tem)
{
    printf("%d\n", (*tem).x);
    printf("%d\n", tem->y[2]);
    printf("%s\n", tem->c);
}
int main()
{
    S1 li = {20, {1,2,3}, "rido"};
    print(li);
    printc(&li);
    return 0;
}
//struct S1
//{
//    int x[6];
//    char y;
//    double n;
//    char* p;
//};
//struct S2
//{
//    char name[5];
//    struct S1 s;
//    short age;
//};
//int main()
//{
//    char arr[] = "hello rido";
//    struct S2 rido = { "li", {{1,2,3}, 'w', 4.13, arr }, 33};
//    printf("%d\n", rido.age);
//    printf("%p\n", rido.s.p);
//    printf("%d\n", rido.s.x[4]);
//    printf("%s\n", rido.name);
//    printf("%s\n", arr);
//    printf("%c\n", arr[1]);
//    printf("%p\n", arr);
//    return 0;
//}

//int main()
//{
//    int n = 100;
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d\n", i);
//    }
//    return 0;
//}
//int get_strlen(char* arr)
//{
//    int count = 0;
//    while(*arr != '\0'){
//        arr++;
//        count++;
//    }
//    return count;
//}
//void rever( char* arr)
//{
//    int len = get_strlen(arr)-1;
//    char tem = arr[0];
//    arr[0] = arr[len];
//    arr[len] = '\0';
//    if (len >= 2)
//        rever(arr+1);
//    arr[len] = tem;
//}
//int main()
//{
//    char arr[] = "rido is good man";
//    printf("%s\n", arr);
//    rever(arr);
//    printf("%s\n", arr);
//    return 0;
//}
//int get_jie(int n)
//{
//    if (n > 0)
//    {
//        return n * get_jie(n-1);
//    }
//    return 1;
//}
//int main()
//{
//    int n;
//    printf("请输入一个数字");
//    scanf("%d", &n);
//    int ret = get_jie(n);
//    printf("%d", ret);
//    return 0;
//}
//void print(int* p, int sz)
//{
//    int i;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d", p[i]);
//    }
//}
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5};
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    print(arr, sz);
//    return 0;
//}
//int count = 0;
//int get_one(unsigned int num)
//{
//    if (num > 0)
//    {
//        get_one(num/2);
//        if (num % 2 == 1)
//        {
//            return ++count;
//        }
//        printf("%d", num%2);/
//        count += (num % 2 == 1 ? 1 : 0);
//    }
//    return count;
//    int i;
//    for (i = 0; i < 32; i++)
//    {
//        if (((num>>i) & 1) == 1)
//        {
//            count++;
//        }
//    }
//    return count;
//
//}
//int main()
//{
//    int num;
//    int ret;
//    printf("请输入一个数字;");
//    scanf("%d", &num);
//    ret = get_one(num);
//    printf("%d", ret);
//
//    return 0;
//}


//void print(int arr[], int sz)
//{
//    int i;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d", arr[i]);
//    }
//}
//void replace(int* arr1, int* arr2, int sz)
//{
//    int i;
//    for (i = 0; i < sz; i++)
//    {
////        int temp;
////        temp = arr1[i];
////        arr1[i] = arr2[i];
////        arr2[i] = temp;
//        arr1[i] = arr1[i] ^ arr2[i];
//        arr2[i] = arr1[i] ^ arr2[i];
//        arr1[i] = arr1[i] ^ arr2[i];
//    }
//}
//
//int main()
//{
//    int arr1[10] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
//    int arr2[10] = {6, 6, 7, 7, 8, 8, 9 ,9, 0, 0};
//    int sz = sizeof(arr1) / sizeof(arr1[0]);
//    replace(arr1, arr2, sz);
//    print(arr1, sz);
//    printf("\n");
//    print(arr2, sz);
//
//    return 0;
//}
//void init(int arr[], int sz)
//{
//    int i;
//    for (i = 0; i < sz; i++)
//    {
//        arr[i] = 0;
//    }
//}
//void print(int arr[], int sz)
//{
//    int i;
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d\n", arr[i]);
//    }
//}
//void reverse(int arr[], int right)
//{
////    int i;
//    int left;
//    right -= 1;
////    while(left < right)
////    {
////        arr[left] = arr[left] ^ arr[right-1];
////        arr[right-1] = arr[left] ^ arr[right-1];
////        arr[left] = arr[left] ^ arr[right-1];
////        left++;
////        right--;
////    }
//
//    for (left = 0; left < right; left++, right--)
//    {
//        arr[left] = arr[left] ^ arr[right];
//        arr[right] = arr[left] ^ arr[right];
//        arr[left] = arr[left] ^ arr[right];
//    }
//}
//
//int main()
//{
//    int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11};
//    int sz = sizeof(arr) / sizeof(arr[0]);
////    sr -= 1;
////    printf("%d\n", sz);
////    init(arr, sz);//初始化数组
//
//    reverse(arr, sz);//反转数组
//    print(arr, sz);//打印数组
//
//
////    int sz = sizeof(arr) / sizeof(arr[0]);
//
////    for (i = 0; i < sz; i++)
////    {
////        int j;
////        for (j = i+1; j < sz; j++)
////        {
////            if (arr[i] > arr[j])
////            {
////                arr[i] = arr[i] ^ arr[j];
////                arr[j] = arr[i] ^ arr[j];
////                arr[i] = arr[i] ^ arr[j];
////            }
////        }
////    }
////    for (i = 0; i < sz; i++)
////    {
////        printf("%d\n", arr[i]);
////    }
//    return 0;
//}
//void reverse(int* x, int sz)
//{
//    int i;
//    int left = 0;
//    int right = ;
//    for (i = 0; i < sz; i++)
//    {
//        int j;
//
//        for (j = 0; j < i; j++)
//        {
////            int temp;
////            temp = x[i];
////            x[i] = x[j];
////            x[j] = temp;
//            x[i] = x[i] ^ x[j];
//            x[j] = x[i] ^ x[j];
//            x[i] = x[i] ^ x[j];
//
//        }
//    }
////    reverse(x);
//}
//
//int main()
//{
//    int i;
//    int arr[10] = { 0 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    for (i = 0; i < sz; i++)
//    {
//        arr[i] = i+1;
//        printf("%d\n", arr[i]);
//    }
//    reverse(arr, sz);
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d\n", arr[i]);
//    }
//    return 0;
//}
