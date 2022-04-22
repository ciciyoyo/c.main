//
//  main.c
//  4.22
//
//  Created by Rido on 2022/4/22.
//

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
//作业讲解
//int main(int argc, const char * argv[]) {
//    unsigned long pulArray[] = {6,7,8,9,10};
//    unsigned long *pulPtr;
//    pulPtr = pulArray;
//    *(pulPtr + 3) += 3;
//    printf("%d,%d\n", *pulPtr, *(pulPtr+3));
//    return 0;
//}
//写一个函数将字符串逆序
//void reverse (char * Str) {
//    assert(Str);
//    char* left = Str;
//    char* right = Str + (strlen(Str))-1;
//    printf("%p\n", left);
//    printf("%p\n", right);
//    while(left < right) {//这里是一个地址可以比较大小
//        char tem = *left;
//        *left = *right;
//        *right = tem;
//        left ++;
//        right--;
//    }
//}
//int main() {
//    char arr[256] = { 0 };
////    scanf("%s", arr);
//    gets(arr);//读取一行
//    reverse(arr);
//    printf("%s", arr);
//    return 0;
//}
//求Sn = a+aa+aaa+aaaa+aaaaa的5项之和其中a是一个数字
//int sub(int a , int n)
//{
//    int sum = 0;
//    int ret = 0;
//    int i;
//    for (i = 0; i < n; i++) {
//        ret  = ret * 10 + a;
//        sum += ret;
//    }
//    return sum;
//}
//
//int main() {
//    int a = 2;
//    int n =4;
//    int ret = sub(a, n);
//    printf("%d", ret);
//    return 0;
//}
//水仙花数(自幂数)求0-100000之间的所有水仙花数打印输出
//int main() {
//    int i;
//    for (i = 0; i < 100000; i++) {
//        int n = 1;
//        int tmp = i;
//        int sum = 0;
//        //求出几位数
//        while (tmp /= 10 ) {
//            n++;
//            }
//        //求出每一位n次方之和
//        tmp = i;
//        while(tmp) {
//            sum += pow(tmp%10, n);
//            tmp/=10;
//        }
//        if (i == sum) {
//            printf("%d\n",i);
//        }
//        //比较
//    }
//    return 0;
//}

//打印菱形图案
int main() {
    int i;
    int line= 9;
    //打印上半部分
    for (i = 0; i < line; i++) {
        int j;
        //打印空格从多到少
        for (j = 0; j < line-i-1; j++) {
            printf(" ");
        }
        //打印星星从少到多
        for (j = 0; j < (2*i)+1; j++) {
            printf("*");
        }
        printf("\n");
    }
    //打印下半部分
    for (i = 0; i < line; i++) {
        //打印空格
        int j;
        for (j = 0; j <= i; j++) {
            printf(" ");
        }
        //打印星星
        for (j = 0; j < (2*(line-i-1)-1); j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
