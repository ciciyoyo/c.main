//
//  main.c
//  4.20
//
//  Created by Rido on 2022/4/19.
//

#include <stdio.h>
//经典笔试题
int main(int argc, const char * argv[]) {
    int a[] = {1, 2, 3, 4};
    printf("%lu\n", sizeof(a));//16
    printf("%lu\n", sizeof(a+0));//4/8首元素地址加0还是首元素地址
    printf("%lu\n", sizeof(*a));//4 a首元素地址*a时首元素
    printf("%lu\n", sizeof(a+1));//4/8 首元素地址加1下个元素地址
    printf("%lu\n", sizeof(a[1]));//4第二个元素大小
    printf("%lu\n", sizeof(&a));//4/8&a取出数组的地址，
    printf("%lu\n", sizeof(*&a));//16
    printf("%lu\n", sizeof(&a+1));//8
    printf("%lu\n", sizeof(&a[0]));//8
    printf("%lu\n", sizeof(&a[0]+1));//8
    return 0;
}
