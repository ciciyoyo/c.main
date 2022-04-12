//
//  c_0410.c
//  demo
//
//  Created by Rido on 2022/4/11.
//

#include "c_0410.h"
#include <string.h>
#include <stdio.h>
////写一个字符串拷贝将cost修饰
//void my_strcpy(char* arr1,char* arr2)
//{
//    while(*arr1 != '\0')
//    {
//        *arr1++ = *arr2++;
//    }
//
//}
//int main()
//{
//    char arr1[] = "Rido is good man";
//    char arr2[] = "hello lidong";
//    my_strcpy(arr1, arr2);
//    printf("%s", arr1);
//    return 0;
//
//}
int main()
{
    int arr[] = {3, 7, 13, 19};
    int* p = arr;
    int a = *p++;
    int b = *p;
    int c = ++*p;
    
    printf("arr[2] = %p\n", &arr[1]);
    printf("%d\n", *p);
    printf("p = %p\n", p);
    int d = (*p)++;
    int e = *(p++);
    int f = *p;
    int g = *++p;
    printf("a = %d\n b = %d\nc = %d\nd = %d\ne = %d\nf = %d\ng = %d\n",a, b, c, d, e, f,g);
    printf("%d\n%d\n%d\n%d\n", arr[0], arr[1], arr[2],arr[3]);
    return 0;
    
}
