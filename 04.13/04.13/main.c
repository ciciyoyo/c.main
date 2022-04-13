//
//  main.c
//  04.13
//
//  Created by Rido on 2022/4/13.
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    int i = -20;
//    //10000000 00000000 00000000 00010100 i 源
//    //11111111 11111111 11111111 11101011 i 反
//    //11111111 11111111 11111111 11101100 i 补
//    unsigned int j = -10; //无符号数 源 反 补相同
//    //10000000 00000000 00000000 00001010 j 源
//    //11111111 11111111 11111111 11110101 j 反
//    //11111111 11111111 11111111 11110110 j 补
//    //01111111 11111111 11111111 11100010 j+i 补
//    //11111111 11111111 11111111 11100001 j+i 反
//    //10000000 00000000 00000000 00011110 j+i 源
//    //第一个操作数为int型，第二个操作数为unsigned int型，两者类型不一致，根据C语言的usual arithmetic conversion规则，在做运算前需要将两者类型统一。由于两者都是整数类型，直接适用integer promotion规则，第一个操作数m被提升为unsigned int型，-13对应的无符号值是4,294,967,283。现在两个操作数均为unsigned int型，执行加法得4294967283+10=4294967293。
//    printf("%d\n", i+j);
//    printf("%u", j);
//    return 0;
//}
//int main()
//{
//    unsigned int i;
//    for (i = 9; i >= 0; i--)//死循环
//        //00000000 00000000 00000000 0000000
//        printf("%d\n", i);
//    sleep(5);
//
//    return 0;
//}

//int main()
//{
//    char a[1000];
//    int i;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1-i;
//        //11111111 11111111 11111111 11111111
//        //00000000 00000000 00000000 00000000
//        printf("%d\n", a[i]);
//    }
//    printf("%d\n",strlen(a));//255
//    printf("%s", a);//
//    return 0;
//}
unsigned char i = 0;
int main()
{
    for (i = 0; i <255; i++)
    {
        printf("hello rido%d\n",i);
    }
    
    return 0;
}
