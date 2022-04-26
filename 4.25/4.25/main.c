//
//  main.c
//  4.25
//
//  Created by Rido on 2022/4/25.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
//左旋字符串函数实现
//暴力求解法
//void left(char *car, int num) {
//    assert(car);
//    int i;
//    int len = strlen(car)-1;
//    for (i = 0; i < num; i++) {
//        char tmp = *car;
//        while (*(car+1)) {
//            *car = *(car+1);
//            car++;
//        }
//        *car = tmp;
//        car -= len;
//    }
//}
//三步反转法 一、先把药左旋个数的字符反转，二、在把剩余的反转，三、最后把所有都反转
//void reverse(char* left, char* right)
//{
//    assert(left);
//    assert(right);
//    while(left < right) {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//void left_move(char* arr, int k) {
//    assert(arr);
//    long len = strlen(arr);
//    assert(k<=len);
//    reverse(arr, arr+k-1);//逆序左边
//    reverse(arr+k, arr+len-1);//逆序右边
//    reverse(arr, arr+len-1);//逆序整体
//}
////int main(int argc, const char * argv[]) {
////    char arr[] = "RidoIsGoodMan";
//////    left(arr, 3);
////    left_move(arr, 3);
////    printf("%s\n", arr);
////    return 0;
////}
////题目给定二个字符串判断是否为另一个左旋得来的
//int is_str(char * s1, char* s2) {
//    long s1len = strlen(s1);
//    long s2len = strlen(s2);
//    int i;
//    for (i = 0; i < s2len; i++) {
//        left_move(s2, 1);
//        if (strcmp(s1,s2) == 0) {
//            return 1;
//        }
//    }
//    return 0;
//}
//int main() {
//    char arr1[] = "abcdef";
//    char arr2[] = "fabcde";
//    int ret = is_str(arr1, arr2);
//    printf("%d", ret);
//
//    return 0;
//}
//用库函数解决
//strcat(s1,s2)追加，在s1后面追加s2串遇到\0停止（的保证s1的空间够大）
//strcat(s1,s2,count)追加，在s1后面追加s2，追加count个数的字符
//strstr函数用于判断字符串s2是否为字符串s1的子串，是函数返回s2在s1中首次出现的地址，否则返回NULL。
//int is_move_str(char* s1, char* s2)
//{
//    int len = strlen(s1);
//    strncat(s1, s1, 5);
//    char* ret = strstr(s1, s2);
////    printf("%s", s1);
//    if( ret == NULL) {
//        return 0;
//    } else {
//        return 1;
//    }
//}
//int main() {
//    char arr1[30]= "abcdef";
//    char arr2[]= "cdefab";
//    int ret = is_move_str(arr1, arr2);
//    if(ret == 0) {
//        printf("不是");
//    } else {
//        printf("是");
//    }
//    return 0;
//}
//杨氏矩阵：矩阵每行从左到右是递增的，矩阵从上到下是递增的
//编写一个程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于o(N);（意思是不润许遍历整个数组）
//int is_in(int(*p)[4], int k, int x, int y) {
//    int j = x;
//    while (y-1 >= 0 && x >= 1 ) {
//        if(k > *(*p)+y-1) {
//            p++;
//            x--;
//        }else if(k < *(*p)+y-1 ) {
//            y--;
//        }else {
//            printf("%d %d\n", j-x+1, y);//在哪行哪列
//            return *(*p)+y-1;
//        }
//    }
//    return 0;
//}
int findName (int(*p)[4], int k, int* px, int* py) {
    int x = 0;
    int y = *py -1;
    while(x < *px && y >= 0) {
        if (p[x][y] < k) {
            x++;
        } else if(p[x][y] > k) {
            y--;
        } else {
            *px = x;
            *py = y;
            return 1;
        }
    }
    return 0;
}
int main() {
    int arr[3][4] ={0,1,2,3, 4,5,6,7, 8,9,10,11};
    int k = 11;
    //这种叫做返回型参数
    int x = 3;//
    int y = 4;
//    int ret = is_in(arr, k, 3, 4);//自己写的
    int ret = findName(arr, k, &x, &y);
    if (ret != 0) {
        printf("在里面\n");
        printf("%d %d", x, y);
    } else {
        printf("不在");
    }
    return 0;
}
