//
//  main.c
//  4.21
//
//  Created by Rido on 2022/4/21.
//

#include <stdio.h>
//指针笔试题
//NO1:
//int main(int argc, const char * argv[]) {
//
//    int a[5] = {1, 2, 3, 4, 5};
//    int *ptr = (int*)(&a + 1);//跳过数组的地址还是数组的地址，数组的地址不能放到int*里面 所以要把它强转成int*
//    printf("%d,%d\n", *(a+1), *(ptr -1));
//    return 0;
//}
//NO2:
//已知，结构体Test类型的变量大小是20字节
//struct Test{
//    int Num;
//    char * pcName;
//    short sDate;
//    char cha[2];
//    short sBa[4];
//} *p;
////假设p 的值为0x100000.如下表达式的值分别为多少
////指针+- 整数取决于指针的类型
//int main() {
//
//    p = (struct Test*)0x100000;
//    printf("%d\n", sizeof(*p));
//    //p是结构体类型大小是20字节，对它加一跳过20字节16进制表示14
//    printf("%p\n", p + 0x1);//0x100014
//    //强转无符号整型==（long）or（int）整形加1就是1
//    printf("%p\n",(unsigned long)p+0x1);//0x100001
//    //强转无符号整型指针。加一跳过一个整形
//    printf("%p\n",(unsigned int*)p+0x1);//0x100004
//    return 0;
//No3
//int main() {
//    int a[4] = {1, 2, 3, 4};
//    int *ptr1 = (int*)(&a +1);
//    int *ptr2 = (int*)((int)a + 1);
////    printf("%p\n", *ptr2);
////    printf("%p\n", a[0]);
//    printf("%x\n", ptr1[-1]);//0x4
//    printf("%d\n", *ptr2);//0x02000000
//    return 0;
//}
//No4
//int main()
//{
//    int a[3][2] = {(0,1),(2,3),(4,5)};//{1,3,5,0,0,0}逗号表达式取后面的值
//    int *p;
//    p = a[0];
//    printf("%d\n", p[0]);//0
//    return 0;
//}
//No5
//int main()
//{
//    int a[5][5];
//    int (*p)[4];
//    p = a;
//    //p[4]是把指向a[4]的地址向后移动4个int(*)[4]类型的地址
//    printf("%d\n", &p[4][2]-&a[4][2]);//-4
//    //%p把-4的反码直接当成地址打印出来
//    printf("%p\n", &p[4][2]-&a[4][2]);//0xfffffffc
//    return 0;
//}
//No5
//int main() {
//    int arr[2][5] ={1,2,3,4,5,6,7,8,9,10};
//    int *ptr1 = (int*)(&arr+1);
//    int *ptr2 = (int*)(*(arr+1));
//    printf("%d\n", *(ptr1-1));//10
//    printf("%d\n", *(ptr2-1));//5
//    return 0;
//}
//No6
//int main() {
//    char *a[] = {"work", "at", "alibaba"};
//    char ** pa = a;
//    pa++;
//    printf("%s\n", *pa);//at
//    return 0;
//}
//No7
int main() {
    char * c[] = {"ENTER","NEW","POINT","FIRST"};//{"E","N","P","F"}相当于这几个字符的地址
    char **cp[] = {c + 3, c + 2, c + 1, c};//{*first,*point*new,*enter}
    char ***cpp = cp;
    //用%s打印会从当前地址向后找直到找\0停止
    //++相当于+= 所以++后值会变
    printf("%s\n", **++cpp);//point
    printf("%s\n", *--*++cpp + 3);//er
    printf("%s\n", *cpp[-2] + 3);//st
    printf("%s\n", cpp[-1][-1] +1);//ew
    return 0;
}

