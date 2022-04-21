//
//  main.c
//  4.20
//
//  Created by Rido on 2022/4/19.
//

#include <stdio.h>
#include <string.h>
//经典笔试题
int main(int argc, const char * argv[]) {
    //整型数组大小
    int a[] = {1, 2, 3, 4};
    printf("%lu\n", sizeof(a));//16
    printf("%lu\n", sizeof(a+0));//4/8首元素地址加0还是首元素地址
    printf("%lu\n", sizeof(*a));//4 a首元素地址*a时首元素
    printf("%lu\n", sizeof(a+1));//4/8 首元素地址加1下个元素地址
    printf("%lu\n", sizeof(a[1]));//4第二个元素大小
    printf("%lu\n", sizeof(&a));//4/8&a取出数组的地址，
    printf("%lu\n", sizeof(*&a));//16对数组的地址解引用找到数组的大小
    printf("%lu\n", sizeof(&a+1));//4/8越界的地址
    printf("%lu\n", sizeof(&a[0]));//4/8取首元素地址
    printf("%lu\n", sizeof(&a[0]+1));//4/8取第二个元素的地址
    printf("*****************\n");
    //字符数组大小
    char car[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%lu\n", sizeof(car));//6
    printf("%lu\n", sizeof(car+0));//4/8
    printf("%lu\n", sizeof(*car));//1
    printf("%lu\n", sizeof(car[1]));//1
    printf("%lu\n", sizeof(&car));//4/8
    printf("%lu\n", sizeof(&car+1));//4/8
    printf("%lu\n", sizeof(&car[0]+1));//4/8
    printf("*****************\n");
    //字符串长度
    printf("%lu\n", strlen(car));//随机
    printf("%lu\n", strlen(car + 0));//随机
    //'a'/97 而strlen需要传指针，而你把97作为地址向后找\0时非法访问
//    printf("%lu\n", strlen(*car));//报错
//    printf("%lu\n", strlen(car[1]));//err
    printf("%lu\n", strlen(&car));//随机
    printf("%lu\n", strlen(&car+1));//也是随机和上个随机值差6
    printf("%lu\n", strlen(&car[0]+1));//也是随机和上个随机差1
    printf("*****************\n");
    //字符数组
    char sar[] = "asdzxc";
    printf("%lu\n", sizeof(sar));//7
    printf("%lu\n", sizeof(sar + 0));//4/8
    printf("%lu\n", sizeof(*sar));//1
    printf("%lu\n", sizeof(sar[1]));//1
    printf("%lu\n", sizeof(&sar));//4/8
    printf("%lu\n", sizeof(&sar+1));//4/8
    printf("%lu\n", sizeof(&sar[0]+1));//4/8
    printf("*****************\n");
    printf("%lu\n", strlen(sar));//6
    printf("%lu\n", strlen(sar + 0));//6
//    printf("%lu\n", strlen(*sar));//err
//    printf("%lu\n", strlen(sar[1]));//err
    //警告char (*)[7]与const char*类型不一样
    printf("%lu\n", strlen(&sar));//6
    //警告char (*)[7]跳过这个数组还是一个数组
    printf("%lu\n", strlen(&sar+1));//随机
    printf("%lu\n", strlen(&sar[0]+1));//5
    printf("*****************\n");
    //字符指针pointer
    char *p = "asdzxc";//常量字符串不可以改的，而字符数组时可以改的
    printf("%lu\n", sizeof(p));//4/8
    printf("%lu\n", sizeof(p + 1));//4/8
    printf("%lu\n", sizeof(*p));//1
    //arr[0] == *(arr+0) 等价的 p[0] == *(p+0)
    printf("%lu\n", sizeof(p[0]));//1
    printf("%lu\n", sizeof(&p));//8
    printf("%lu\n", sizeof(&p+1));//4/8
    printf("%lu\n", sizeof(&p[0]+1));//4/8
    printf("*****************\n");
    
    printf("%p\n", strlen(p));//6
    printf("%lu\n", strlen(p + 1));//5
//    printf("%lu\n", strlen(*p));//err
//    printf("%lu\n", strlen(p[0]));//err
    printf("%lu\n", strlen(&p));//随机
    printf("%lu\n", strlen(&p+1));//随机
    printf("%lu\n", strlen(&p[0]+1));//5
    printf("*****************\n");
    //二维数组大小
    int er[3][4] = {0};
    printf("%lu\n", sizeof(er));//48这里计算整个数组三行四列
    printf("%lu\n", sizeof(er[0][0]));//4
    //er[0]是第一行的数组名sizeof(er[0])把数组名单独放在sizeof内，计算数组的大小
    printf("%lu\n", sizeof(er[0]));//16,
    //er[0]是第一行数组名 把数组名放到表达式内则改数组名表示此时时首元素地址
    printf("%lu\n", sizeof(er[0]+1));//4/8
    printf("%lu\n", sizeof(*(er[0]+1)));//4
    //er是二维数组名加1进行运算时它此时则表示首元素地址加1跳过第一行
    printf("%lu\n", sizeof(er +1));//4/8第二行的地址数组的地址
    printf("%lu\n", sizeof(*(er+1)));//16等价于sizeof(a[1])
    printf("%lu\n", sizeof(&er[0]+1));//4/8第二行地址先取地址在加一
    printf("%lu\n", sizeof(*(&er[0]+1)));//16第二行数组的大小
    printf("%lu\n", sizeof(*er));//16第一行数组的大小
    //sizeof内部的表达式是不参与真是的运算的，只是根据它的类型来计算它的大小
    printf("%lu\n", sizeof(er[3]));//16他不会真的去访问，
    printf("*****************\n");

    return 0;
}
