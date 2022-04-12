//
//  c_0410.c
//  demo
//
//  Created by Rido on 2022/4/11.
//

#include "c_0410.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

//练习2
int main()
{
    char a = -128;
    //10000000 00000000 00000000 10000000 源码
    //11111111 11111111 11111111 01111111 反码
    //11111111 11111111 11111111 10000000 补码
    //取10000000放到 a里面
    printf("%u\n", a);
    char b = (char)128;
    //00000000 00000000 00000000 10000000 源码
    //10000000
    //11111111 11111111 11111111 10000000 提升
    
    printf("%u\n", b);
    return 0;
}
//练习1
//int main()
//{
//    char a = 1;
//    signed char b = -1;
//    unsigned char c = -1;
//    printf("a=%d\nb=%d\nc=%d\n", a, b, c);//-1-1255
//
//    return 0;
//}
////写一个字符串拷贝将cost修饰
///assert断言
//char* my_strcpy(char* arr1,const char* arr2)
//{
//    char* ret = arr1;
//    assert(arr1 != NULL);
//    assert(arr2 != NULL);
//    while(*arr1++ = *arr2++)
//    {
//    }
//    return ret;
//}
//int main()
//{
//    char arr1[] = "Rido is good man";
//    char arr2[] = "hello lidong";
//    my_strcpy(arr1, arr2);
//    printf("%s\n", arr1);
//    return 0;
//
//}

//* 和++的结合运算
//int main()
//{
//    int arr[] = {3, 7, 13, 19};
//    int* p = arr;//指针p指向数组的第一个元素
//    //*优先高于++，所以*p取值1，按照++结合性会对指针p进行加1，指向下一个地址
//    int a = *p++;
//    //由于此时p指向了第二个元素的地址，所以取值是7
//    int b = *p;
//    //先对*p取值为7 ，再自加结果为 8
//    int c = ++*p;
//    //先对*p取值为8 ，下一个表达式再使用自加结果9
//    int d = (*p)++;
//    //++是在后面，所以先算*p取值为9，指针p加1，下一表达式用p时已指向下个元素
//    int e = *(p++);
//    //此时指针指向第三个元素，取值为13
//    int f = *p;
//    //先对指针p加1，在解引用
//    int g = *++p;
//    printf("a = %d\n b = %d\nc = %d\nd = %d\ne = %d\nf = %d\ng = %d\n",a, b, c, d, e, f,g);
//    printf("%d\n%d\n%d\n%d\n", arr[0], arr[1], arr[2],arr[3]);
//
//    return 0;
//
//}
