//
//  main.c
//  5.13
//
//  Created by Rido on 2022/5/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Lesson1--数据结构
//什么是数据结构：
    //数据结构（DataStructure）是计算机存储、组织互相之间存在一种或多种特定关系的数据元素的集合
//什么是算法
    //算法（Algorithm）：就是定义良好的计算过程，它取一个或一组的值为输入，并产生出一个或一组作为输出，简单来说算法就是一系列的计算步骤，用来将输入数据转化成输出结果

//Lesson2--时间复杂度--空间复杂度
    //分析算法效率有两种：一、时间复杂度，主要衡量算法的运行速度。二、空间复杂度，主要衡量算法所需的额外空间，现在计算机的容量已经达到了很高的程度，所以我们不怎么关系空间复杂度（摩尔定律，硬件每十八个月就会翻一倍）
    //一、时间复杂度
        //概念：在计算机中，算法的时间复杂度是一个数学函数，描述该算法所需时间（大概次数）。（算法基本操作的执行次数，为算法时间复杂度）
        //大O渐进表示法（
            //1、用常熟1取代运行时间中的所有加法常数
            //2、在修改后的运行次数函数中，只保留最高阶项
            //3、如果最高阶项存在且不是1，则去除愚者项目相乘的常数，得到的结果就是大O阶
//struct S {
//    char c;
//    int b;
//    double d;
//};
//
//int main(int argc, const char * argv[]) {
//    char arr[4] = {0};
//    struct S* s = (struct S *)arr;
//    printf("%d", );
//    return 0;
//}

//int searchInsert(int* nums, int numsSize, int target){
//    int left = 0,rigt = numsSize, adn = numsSize;
//    while (left <= rigt) {
//        int mid = ((rigt-left)>>1) + left;
//        if (target >= nums[mid]){
//            adn = left;
//            left = mid+1;
//        }else {
//            rigt = mid-1;
//        }
//    }
//    return adn;
//}
//int main()
//{
//    int nums[]={1,2,3,4,6,7,8};
//    int target = 9;
//    int numsz = sizeof(nums)/sizeof(nums[0]);
//    int ret = searchInsert(nums, numsz, target);
//    printf("%d", ret);
//    return 0;
//}

//时间复杂度练习 给定一个数组但是缺少一个数要求在O(N)时间复杂度内完成
//int deficiency (int* nums, int sz)
//{
//    int i;
//    int ret = 0;
//    for (i = 0; i < sz; i++) {
//        ret ^= i;
//        ret ^= nums[i];
//    }
//    ret = ret ^ sz;
//    return ret;
//
//}
//int main()
//{
//    int nums[]={2,0,1,3,4,6,8,5};
//    int sz = sizeof(nums)/sizeof(nums[0]);
//    int ret = deficiency(nums, sz);
//    printf("%d" , ret);
//    return 0;
//}
//

//Lesson--3顺序表和链表
    //一、线性表
        //概念：线性表（linear list）是N个具有相同特性的数据元素的有限序列，线性表是一种在实际中广泛使用的数据结构，常见的线性表：顺序表、链表、栈、队列、字符串...
        //线性表在逻辑上是线性结构，也就是说是连续的一条直线。但是在物理结构上并不一定是连续的，线性表在物理上存储时，通常以数组和链式结构的形式存储。
    //二、顺序表
        //概念：顺序表是用一段物理地址连续的存储单元一次存储数据元素的线性结构，一般情况下采用数组存储。在数组上完成数据的增删查改。
        
    //三、链表
    //四、顺序表和链表的区别和联系
//int cmp (char* a, char* b)
// {
//    return ((*(int*)a) -(*(int*)b));
// }
//int* sortedSquares(int* nums, int numsSize, int* returnSize){
//    (*returnSize) = numsSize;
//    int* parr=malloc(sizeof(int)* numsSize);
//    int i;
//
//    for (i = 0; i < numsSize; i++) {
//       parr[i] = nums[i] *nums[i];
//    //    unsigned int temp = parr[i];
//    }
//
//    qsort(parr, numsSize, sizeof(int), cmp);
//    return parr;
//}
//void reverse (int* nums, int start, int end)
//{
//    while(start < end)
//    {
//        int tmp = nums[start];
//        nums[start] = nums[end];
//        nums[end] = tmp;
//        ++start;
//        --end;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k){
//    int start = 0;
//    int end = numsSize-k;
//    reverse(nums, start, end-1 );
//    reverse(nums, end, numsSize-1);
//    reverse( nums, start, numsSize-1);
//}
//typedef struct Slist{
//    int a;
//    struct Slist * next;
//} Sit;
//
//void test(Sit** ptr)
//{
//    Sit* pct = (Sit*)malloc(sizeof(Sit));
//    pct->next = NULL;
//    pct->a = 10;
//    if (*ptr == NULL) {
//        *ptr = pct;
//    }
//}
//void test2(Sit* ptr)
//{
//    Sit* tmp = (Sit*)malloc(sizeof(Sit));
//    tmp->a = 69;
//    tmp->next = NULL;
//    ptr->next = tmp;
//}
//int main()
//{
//    Sit* p = NULL;
//    test(&p);
//    test2(p);
//    printf("%d", p->next->a);
////    printf("%d\n", *(s1.a));
////    printf("%p\n", s2.a);
////    printf("%p\n", s1.a);
//    free(p);
//    p = NULL;
//    return 0;
//}
//void reverse(char* ptr, int head, int after) {
//
//}
//
//char * reverseWords(char * s){
//    int count = 0;
//    while(s[count]) {
//        if (s[count] == ' ') {
//            printf("%d", count);
//        }
//        count++;
//    }
//    return s;
//}
//int main()
//{
//    char* ptr = "rido is good man";
//    char* p = "lidong";
////    reverseWords(ptr);
////    if (ptr[4] == ' ') {
////        printf("%c", ptr[2]);
////    }
////    char tmp = ptr[0];
////    ptr[0] = ptr[1];
////    ptr[1] = tmp;
//
//    printf("%s", pptr);
//    return 0;
//}



//char* reverseWords(char* s) {
//    int left =0;
//    int rigt = 0;
//    int lenght = strlen(s)-1;
//    while(rigt <= lenght) {
//        if (s[rigt] == ' '|| rigt== lenght) {
//            int r = rigt;
//            while(left< r){
//                char tmp = s[left];
//                if(r == lenght) {
//                    s[left] = s[r];
//                    s[r] = tmp;
//                    left++;
//                    r--;
//                }else{
//                    s[left] = s[r-1];
//                    s[r-1] = tmp;
//                    left++;
//                    r--;
//                }
//            }
//            left = rigt+1;
//        }
//        rigt++;
//    }
//    return s;
//}
//int main() {
//
//    char ptr[] = {"rido is good man"};
//    char* ret = reverseWords(ptr);
//    printf("%s", ret);
//    return 0;
//}

//int lengthOfLongestSubstring(char * s){
//
//    int lenght = strlen(s);
//    int i, j;
//    int max = 0;
//    // if (!*s){
//    //     return 0;
//    // }
//    // if (lenght == 1) {
//    //     return 1;
//    // }
//    for (i = 0; i < lenght; i++) {
//        int tmp = 1;
//        for (j = i+1; j < lenght; j++) {
//            if (s[i] != s[j]){
//                tmp++;
//            } else {
//                break;
//            }
//        }
//        max = tmp> max? tmp:max;
//    }
//    return max;
//}
int main() {
//    char c[] = {"abcabcbb"};
//
//    int ret = lengthOfLongestSubstring(c);
    int arr[6] = {1,2,3,4,5,6};
    int ret = arr[2]++;
    printf("%d", arr[2]);
    printf("%d", ret);
    return 0;
    
}
