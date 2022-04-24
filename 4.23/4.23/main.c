//
//  main.c
//  4.23
//
//  Created by Rido on 2022/4/23.
//

#include <stdio.h>
#include <string.h>

//struct S {
//    int a;
//    int b;
//};
//int main(int argc, const char * argv[]) {
//    struct S a , *p = &a;
//    a.a = 99;
//    printf("%d\n", (*p).a);//A,a.a B,*p.a C,p->a D,(*p).a
//    return 0;
//}
//struct stu {
//    int num;
//    char name[10];
//    int age;
//
//};
//
//void fun(struct stu *p) {
//    printf("%s", (*p).name);
//}
//int main() {
//    struct stu students[3] = { {9801, "zhang", 20},
//        {9802, "wang", 19},
//        {9803, "zhao", 18}
//    };
//    fun(students + 1);
//    return 0;
//}
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 20元可以喝多少汽水
//int total( int x) {
//    if (x > 1) {
//        int y = x/2 +  x%2;
//       return x +  total(y);
//    }
//    return x;
//
//}
//int main() {
//    int maney = 20;
////    int total = 0;
////    int empty = 0;
////    scanf("%d", &maney);
////    total = maney;
////    empty = total;
////    while (empty >= 2) {
////        total += empty / 2;
////        empty = empty / 2 + empty % 2;
////    }
//    //用递归写
//    int ret = total(maney);
//    printf("%d", ret);
//    return 0;
//}
//int main() {
//    int i;
//    int arr[10] = {1,5,3, 7, 5, 3, 7, 8, 9, 10};
//    int sz = sizeof(arr)/ sizeof(arr[0]);
//    int left = 0;
//    int right = sz-1;
//    while(left < right) {
//        if (arr[left] % 2) {
//            int tmp = arr[left];
//            arr[left] = arr[right];
//            arr[right] = tmp;
//            right --;
//        }
//        else {
//            left++;
//        }
//    }
//    for (i = 0; i< sz; i++) {
//        printf("%d\n", arr[i]);
//    }
//    return 0;
//}
//int main() {
//    unsigned char a = 200;
//    unsigned char b = 100;
//    unsigned char c = 0;
//    c = a+b;
//    printf("%d,%d", a+b, c);//a+b会整型提升而c会切掉
//    return 0;
//}
//int main() {
//    char a[1000] = {0};
//    int i;
//    for (i = 0; i < 1000; i++) {
//
//        a[i] = -1-i;
//    }
//    printf("%d", strlen(a));/求字符长度找到0 就停止所以255
//    return 0;
//}
//屏幕打印杨辉三角
//void print(int (*p)[10]) {
//    int i;
//    int j;
//    for (i = 0; i < 10; i++) {
//        int l;
//        for (l = 0; l < 10-i; l++) {
//            printf("  ");
//        }
//        for (j = 0; j <= i; j++){
//            printf("%4d", p[i][j]);
//        }
//        printf("\n");
//    }
//}
//void ret(int(*p)[10]) {
//    int i;
//    int j;
//    for (i = 0; i < 10; i++) {
//        for (j = 0; j <= i; j++){
//            if (j == 0) {
//                p[i][j] = 1;
//            }
//            if (j == i) {
//                p[i][j] = 1;
//            }
//            if (i >= 2&& j >=1)
//            p[i][j] = p[i-1][j-1] + p[i-1][j];
//        }
//    }
//}
//int main() {
//    int arr[10][10] = {0};
//    ret(arr);
//    print(arr);
//    printf("**************\n");
//    return 0;
//}
//猜凶手
//线索 A说不是我。B说是C。 C说是D。D说C在胡说
//已知3个人说了真话，1个人说的是假话， 根据这些信息写一个程序来确定谁是凶手
//int main() {
//    char k;
//    for (k = 'a'; k < 'd'; k++) {
//        if (('a' != k )+( k == 'c')+(k == 'd')+(k != 'd') ==3){
//            printf("%c\n", k);
//        }
//    }
//    return 0;
//}
//5位运动元比赛预测结果
//A 说：B第二，A第三
//B 说：B第二，E第四
//C 说：C第一，D第二
//D 说：C第五，D第三
//E 说：E第四，A第一
//已知他们都说对了一半
int main() {
    int a, b, c, d, e = 0;
    for (a = 1; a <= 5; a++) {
        for (b = 1; b <= 5; b++) {
            for (c = 1; c <= 5; c++) {
                for (d = 1; d <= 5; d++) {
                    for (e = 1; e <= 5; e++) {
                       if((((b == 2)+(a == 3)) == 1)
                          &&(((b == 2)+(e == 4)) == 1)
                          &&(((c == 1)+(d == 2)) == 1)
                          &&(((c == 5)+(d == 3)) == 1)
                          &&(((e == 4)+(a == 1)) == 1))
                       {
                           if(a*b*c*d*e==120){
                               printf("a=%d b=%dc =%d d=%d e=%d\n", a,b,c,d,e);
                           }
                       }
                    }
                }
            }
        }
    }
    
    return 0;
}
