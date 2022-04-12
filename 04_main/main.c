//
//  main.c
//  demo
//
//  Created by Rido on 2022/3/23.
//
//system是系统命令   strcmp是比较两个字符串是否相等返回1或0
#include <stdio.h>
#include <string.h>
//#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h> //sqrt开平方函数
#include "Add.h"


//什么是大端 小端字节存储模式
//大端，是指数据的低位保存在内存的高地址中，数据的高位保存在内存的低地址中
//小端，是指数据的低位保存在内存的低地址中，数据的高位保存在内存的高地址中
//int get_bit(void)
//{
//    int a = 1;
//    return *(char*)&a;
//}
//int main()
//{
//    int ret = get_bit();
//    if (ret == 1)
//        printf("小端");
//    else
//        printf("大端");
//    return 0;
//}
//结构体 2
//typedef struct std//typedef重新定义
//{
//    char name[10];
//    short age;
//    char tel[12];
//    char sex[5];
//} Std; //Std从新定义之后的名字 是类型
////结构体 1
//struct tag//struct结构体关键字  tag结构体标签   组合一起叫结构体类型
//{
//   char member_list[10];//成员变量
//}variable_list;//变量列表 结构体全局变量,声明类型的同时定义变量S1
//int main()
//{
//    struct tag s;//定义结构体变量S
//    s.member_list = "rido";
//    struct std s1 = { "rido", 33, "16604312111", "man" };//初始化：定义变量的同时赋初值
//    Std s4;
//    return 0;
//}

//指针类型的定义
//1指针类型剧定了指针解引用能访问几个字节
//2指针类型决定了指针加1减1加减几个字节

//指针数组
//int main()
//{
//    int i = 0;
//    int a = 10;
//    int b = 20;
//    int c = 30;
//    int* arr[3] = {&a, &b, &c};
//    for (i = 0; i < 3; i++)
//    {
//        printf("%d\n", *(arr[i]));
//    }
//    return 0;
//}
//        
//二级指针
//int main()
//{
//    int a = 10;
//    int* p = &a;
//    int* * pa = &p;
//    int** * paa = &pa;
//    printf("%p\n%p\n%p\n",p, *pa,**paa);
//    return 0;
//}
////数组只有两个情况下数组名代表整个数组&数组名，sizeof（数组名）
//int main()
//{
//    int a,b,c;
//    int arr[3]= { 0 };
//    printf("%d\n%d\n%d\n%d\n",a , b, c, arr[1]);
//    int arr1[10] = { 0 };
//    printf("%p\n", arr);
//    printf("%p\n", &arr[0]);
//    printf("%p\n", &arr);
//
//    return 0;
//}
//野指针
//int* test()
//{
//    int a = 10;
//    return &a;
//}
//int main()
//{
//    int i;
//    int *p = NULL;//为初始化的指针变量
//    int a[10] = { 0 };
//    int* pa = a;
//    for (i = 0; i < 11; i++)
//    {
//        *pa++ = i;//越界访问野指针
//    }
//    int* pt = test();//变量销毁成野指针
//    printf("%d", *pt);
//    return 0;
//}
//int main()
//{
//    int arr[10] = { 0 };
//    char* pi = arr;
//    int i;
//    int j;
//    for (i = 0; i < 10; i++)
//    {
//        *(pi + i) = 1;
////        printf("%d\n", arr[i]);
//    }
//    for (j = 0; j < 10; j++)
//    {
//        printf("第%d个元素%d\n", j, arr[j]);
//    }
//    printf("第1个元素%d\n", arr[0]);
//    return 0;
//}
//指针操作
//int main()
//{
//    int a = 0x11223344;
//    int* pa = &a;
//    char* pc = &a;
//    printf("%p\n", *pa);
//    printf("%p\n", *(pa+1));
//    printf("%p\n", *pc);
//    printf("%p\n", *(pc+1));
//
//
//    return 0;
//
//}

//算术提升是把字节小的类型转换成字节大的类型在运算
//整形提升
//有符号数整形提升在高位补符号位
//无符号数整形提升在高位补0
//int main()
//{
//    char a = 128;
////    a = 10000000
//    char b = 28;
////    b = 00011100;
////    c = 10011100
////    c = 10011011 反码
////    c = 11100100 源码 所以等余-100
//    char c = a + b;
//    printf("%d", c);
//    return 0;
//}



//结构体->变量
//struct Std {
//    char name[10];
//    int age;
//    char id[10];
//};
//int main()
//{
////    int arr[] = {1, 2, 3, 4, 5, 6};
//    struct Std li = {"rido", 32, "20220402"};
//    struct Std* pt = &li;
//    printf("age=%d\n", (*pt).age);
//    printf("name=%s\n", li.name);
//    printf("地址=%p\n", pt);
//    printf("id=%s\n", pt->id);
//    return 0;
//}
////(类型) 强制类型转换
//int main()
//{
//    int a = (int)3.741592;
//    printf("%d", a);
//    return 0;
//}
////按位取反
//int main()
//{
//    int a = 13;
////    00000000000000000000000000001101 源码
////    11111111111111111111111111110010 补码
////    11111111111111111111111111110001 反码
////    10000000000000000000000000001110 源码
//
//    int b = ~a;
//    int c = a+ b;
//    printf("%d\n%d", b,c);
//    return 0;
//
//}
//求一个二进制数在内存中有多少个1
//%d 有符号10进制整数
//%i 有符号10进制整数
//%o 无符号8进制整数
//%u无符号10进制整数
//%x 无符号的16进制数字，此时是以小写abcdef表示
//%X 无符号的16进制数字，此时是以大写ABCDEF表示的 x X 大小写对应的哦
//无二进制哦
//int main()
//{
//    int num = 0;
//    int i;
//    int count = 0;
//    printf("请输入数字");
//    scanf("%d", &num);
//    for (i = 0; i < 32; i++)
//    {
//       if (((num >> i) & 1) == 1)
//       {
//           count ++;
//       }
//    }
//    int c = 77;
//    printf("%i\n", count);
//    printf("%o\n", c);
//    return 0;
//}
//左移操作符右边去除左边补0
//int main()
//{
//    int a = 5;
//    int b = a << 1;
//    printf("%d", b);
//    return 0;
//
//}
//右移操作符右边去除左边补符号位
//int main()
//{
//    int a = -19;
////    10000000000000000000000000010001
////    11111111111111111111111111101110
////    11111111111111111111111111101111
////    11111111111111111111111111110111
////    11111111111111111111111111110110
////    00000000000000000000000000001001
//    int b = a>>1;
//
//    printf("%d ", b);
//    return 0;
//}
//按位异或操作可以实现无变量替换两个整数
//int main()
//{
//    int a = 77;
//    int b = 1001;
//    a = a ^ b;
//    b = a ^ b;
//    a = a ^ b;
//    printf("a=%d, b=%d", a, b);
//    return 0;
//}

//void menu()
//{
//    printf("****************************\n");
//    printf("**** 1.play      0.exit ****\n");
//    printf("****************************\n");
//}
//
//void test()
//{
//    int input;
//    menu();
//
//    do {
//        scanf("%d", &input);
//        switch (input) {
//            case 1:
//                printf("三子棋");
//                break;
//            case 0:
//                printf("退出游戏");
//                break;
//            default:
//                printf("输入错误请重新输入");
//                break;
//        }
//    } while (input);
//
//}
//int main()
//{
//    test();
//    return 0;
//}
//数组排序
//void px(int* arr, int lg)
//{
//    int i;
//    for(i=0; i<lg; i++)
//    {
//        int flag = 1;
//        int j;
//        for(j=0; j<lg-i; j++)
//        {
//            if(arr[0] < arr[j+1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = tmp;
//                flag = 0;
//            }
//        }
//        if(flag == 1)
//        {
//            break;
//        }
//    }
//}
//
//int main()
//{
//    int arr[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int i;
//    int sz = sizeof(arr)/sizeof(arr[0]);
//    px(arr, sz);
//    for(i=0; i<sz; i++)
//    {
//        printf("我是%d",arr[i]);
//    }
//    return 0;
//}


//用迭代循环求斐波那契数列
//int Fib(int n)
//{
//    int x= 1;
//    int y = 1;
//    int r= 1;
//    while(n>2)
//    {
//            r = x+y;
//            x = y;
//            y = r;
//            n--;
//    }
//    return r;
//}
//
//int main()
//{
//    int num;
//    int ret;
//    printf("请输入查询的位数：\n");
//    scanf("%d", &num);
//    ret = Fib(num);
//    printf("结果是%d\n", ret);
//    return 0;
//}
////递归求斐波那契数列
//int fb(int n)
//{
//    if(n<2)
//        return 1;
//    else
//    {
//        return fb(n-1) + fb(n-2);
//    }
//}
//int main()
//{
//    int num;
//    int rt;
//    printf("请输入查询的位数：");
//    scanf("%d", &num);
//    rt = fb(num);
//    printf("结果是%d", rt);
//    return 0;
//}
//递归求阶乘
//int Fac1(int n)
//{
//   return  n<=1 ? 1 : n * Fac1(n-1);
//
//}
//
//int main()
//{
//    int n = 0;
//    int set = 0;
//    printf("请输入一个数字：");
//    scanf("%d", &n);
//    set = Fac1(n);
//    printf("结果是%d", set);
//    return 0;
//
//}

//递归求字符串长度
//int len(char* n)
//{
//    if(*n != '\0')
//    {
//       return 1 + len(++n);
//    }
//    return 0;
//}
//
//int main()
//{
//    char arr[]= "rido is super man:";
//    int sum = len(arr);
//    printf("%d", sum);
//    return 0;
//}
//递归n的k次方
//int get_fan(int n, int k)
//{
//    if (k != 0)
//    {
//        return n * get_fan(n , k-1);
//    }
//    return 1;
//}
//
//int main()
//{
//    int n = 2;
//    int k = 5;
//    int ret = get_fan(n, k);
//    printf("%d", ret);
//    return 0;
//}
//递归实现字符串反转
//int get_strlen(char* arr)
//    {
//        int count = 0;
//        while(*arr != '\0'){
//            arr++;
//            count++;
//        }
//        return count;
//    }
//    void rever( char* arr)
//    {
//        int len = get_strlen(arr)-1;
//        char tem = arr[0];
//        arr[0] = arr[len];
//        arr[len] = '\0';
//        if (len >= 2)
//            rever(arr+1);
//        arr[len] = tem;
//    }
//    int main()
//    {
//        char arr[] = "ridogoodman";
//        printf("%s\n", arr);
//        rever(arr);
//        printf("%s\n", arr);
//        return 0;
//    }

//递归
//void print(int n)
//{
//    if(n>9)
//    {
//        print(n/10);
//    }
//    printf("%d",n%10);
//
//}
//int main()
//{
//    int num;
//    printf("请输入一个数字");
//    scanf("%d",&num);
//    print(num);
//    return 0;
//}
//每次调用函数就加一
//void j_num(int* x)
//{
//     (*x)++;
//}
//
//int main()
//{
//    int num = 1;
//    j_num(&num);
//    j_num(&num);
//    j_num(&num);
//    printf("%d", num);
//    return 0;
//}

//二分查找函数
//int get_er(int* a, int x, int l)
//{
//    int left = 0;
//    int right = l/sizeof(a[0])-1;
////    printf("%p\n", a[]);
//
//    while(left<right)
//    {
//        int mid = (left +right)/2;
//        if(a[mid]<x)
//        {
//            left = mid+1;
//        }
//        else if(a[mid]>x)
//        {
//            right = mid-1;
//        }
//        else
//        {
//            return mid;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int num;
//    int length = sizeof(arr);
//    printf("请输入1-10之间的数字");
//    scanf("%d", &num);
//    int ret = get_er(arr, num, length);
//    if(ret == -1)
//    {
//        printf("没有找到你输入的数字");
//    }
//    else
//    {
//        printf("你输入的数字在%d下标的位置", ret);
//    }
//
//    printf("结果是%d",ret);
//    return 0;
//}
//冒泡排序把大的放到后面
//int main()
//{
//    int arr[] = {11,3, 5, 6, 2, 4,10 ,9,7, 8};
//    int i;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    for (i = 0; i < sz-1; i++)
//    {
//        int j;
//        for (j = 0; j < sz-i-1; j++)
//        {
//            if (arr[j] > arr[j+1])
//            {
//                arr[j] = arr[j] ^ arr[j+1];
//                arr[j+1] = arr[j] ^ arr[j+1];
//                arr[j] = arr[j] ^ arr[j+1];
//            }
//        }
//    }
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d\n", arr[i]);
//    }
//    return 0;
//}
//冒泡排序把小的放到前面
//int main()
//{
//    int arr[] = {11 ,3, 5, 6, 2, 4,10 ,9,7, 8};
//    int i;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    for (i = 0; i < sz; i++)
//    {
//        int j;
//        for (j = i+1; j < sz; j++)
//        {
//            if (arr[i] > arr[j])
//            {
//                arr[i] = arr[i] ^ arr[j];
//                arr[j] = arr[i] ^ arr[j];
//                arr[i] = arr[i] ^ arr[j];
//            }
//        }
//    }
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d\n", arr[i]);
//    }
//    return 0;
//}

//判断闰年函数
//int get_run(int x)
//{
//    if((x%4==0 && x%100!=0) || x%400==0)
//        return 1;
//    return 0;
//}
//
//int main()
//{
//    printf("请输入要判断的年份：");
//    int year;
//    scanf("%d", &year);
//    get_run(year) ? printf("shi"): printf("fou");
//
//
//    return 0;
//}

//求这个数是否为素数
//int get_zhi(int x)
//{
//    int i;
//    for(i=2; i<x/2; i++)
//    {
//        if(x%i == 0)
//            return 0;
//    }
//    return 1;
//}
//
//int main()
//{
//    int num;
//    printf("请输入你要判断的数字:");
//    scanf("%d", &num);
//    int ret = get_zhi(num);
//    if(ret == 0)
//    {
//        printf("%d这个数不是素数", num);
//    }
//    else{
//        printf("%d这个数是素数", num);
//    }
//
//    return 0;
//}

//传址操作
//void get_Max(int* x, int* y)
//{
//    int temp = 0;
//    temp = *x;
//    *x = *y;
//    *y = temp;
//}
//
//int main()
//{
//    int a = 10;
//    int* p = &a;
//    int b = 20;
//    get_Max(&a, &b);
//    printf("%d%d%d\n", a, b, *p);
//    return 0;
//}
//三元表达式
//int getMax(int a, int b)
//{
//    return a>b? a:b;
//}
//
//int main()
//{
//    int a;
//    int b;
//    scanf("%d%d", &a, &b);
//    int ret = getMax(a, b);
//    printf("%d", ret);
//    return 0;
//}



//int main()
//{
//    char arr[] = "hellow rido";
//    memset(arr, '$', 3);
//    printf("%s", arr);
//
//    return 0;
//}
//int main()
//{
//    char arr1[] = "rido";
//    char arr2[20] = "###############";
//    strcpy(arr2, arr1);
//    arr2[4] = 'a';
//    printf("%s", arr2);
//
//    return 0;
//}

//goto 语句
//int main()
//{
//again:
//    printf("nihao");
//    goto again;
//    system("sudo shutdown -h +10");
//
//    return 0;
//}


//乘法表
//int main()
//{
//    int i;
//    int j;
//    for(i=1; i<10; i++)
//    {
//        for(j=1; j<=i; j++)
//        {
//            printf("%dx%d=%-2d ", j,i,j*i);
//
//        }
//        printf("\n");
//    }
//    return 0;
//}




//课题1/1-1/2+3/1.....
//int main()
//{
//    int i;
//    double sum = 0.0;
//    int flag = 1;
//    for(i=1;i<=100;i++)
//    {
//        sum += flag * 1.0/i;
//        flag = -flag;
//    }
//    printf("rulst%lf", sum);
//    return 0;
//}


//求100 -200 间的素数
//试除法
//sqrt()开平方函数
//int main()
//{
//    int i;
//    for(i=2; i<=20; i++)
//    {
//        int j;
//        for(j=2;j<sqrt(i);j++) {
//            if(i%j == 0) break;
//        }
//
//    if(j>sqrt(i))
////        printf("hahahah%lf\n", sqrt(16));
//        printf("%d是素数\n", i);
//    }
//    return 0;
//}

//求两个数最大公约数；
//int main()
//{
//    int m;
//    int n;
//    int r;
//    scanf("%d%d", &m, &n);
//    while (m%n)
//    {
//        r = m%n;
//        m = n;
//        n = r;
//    }
//    printf("%d是最大的公约数", n);
//    return 0;
//}

//打印1000-2000年的闰年；
//闰年条件能被4整除但不能被100整除或者能被400整除
//int main()
//{
//    int i;
//    int count = 0;
//    for(i=1000; i<=2000; i++)
//    {
//        if((i%4==0 && i%100 !=0) || i%400 ==0)
//        {
//            count++;
//            printf("%d是闰年一共%d个\n", i, count);
//
//        }
//    }
//    return 0;
//}


//算法二分法
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int left = 0;
//    int k = 6;
//    int rt= sizeof(arr)/sizeof(arr[0]);
//    int right = rt-1;
//
//    while(left <= right)
//    {
//        int mid = (left + right)/2;
//        if(arr[mid]<k)
//        {
//            left = mid + 1;
//        }
//        else if(arr[mid]>k)
//        {
//            right = mid-1;
//        }
//        else{
//            printf("找到了下表为：%d", mid);
//            break;
//        }
//    }
//    if(right < left)
//    {
//        printf("里面没有想要的数");
//    }
//    return 0;
//}



//课题2 计算1！+2！ +3！。。。。。+10！
//int main()
//{
//    int i;
//    int sum = 1;
//    int ret = 0;
//    for(i=1; i<=10; i++)
//    {
//        sum *= i;
//        ret += sum;
//    }
//    printf("%d\n%d\n", sum, ret);
//    return 0;
//}



//课题2 提示登录密码错误三次推出
//int main()
//{
//    int i;
//    char pasw[20] = {0};
//    for(i=0; i<3; i++)
//    {
//        printf("请输入密码：");
//        scanf("%s", pasw);
//        if(strcmp(pasw, "123456") == 0)
//        {
//            printf("登陆成功：\n");
//            break;
//        }
//        else
//        {
//            printf("密码错误请重新输入\n");
//        }
//    }
//    if(i == 3) {
//        printf("失败次数过多稍后再试\n");
//    }
//    return 0;
//
//}



//课题3 演示字符从两端移动向中间汇聚
//int main()
//{
//    char arr1[] = "welcome to rido";
//    char arr2[] = "###############";
//    int left = 0;
//    long right = strlen(arr1)-1;
//    while (left <=right) {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[left];
//        left++;
//        right--;
//        printf("%s\n", arr2);
//        sleep(1);
//        system("clear");
//    }
//
////    printf("%d", right);
//
//    return 0;
//}
