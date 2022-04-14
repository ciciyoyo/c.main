//
//  main.c
//  04.14
//
//  Created by Rido on 2022/4/14.
//

#include <stdio.h>
//浮点数
//根据国际标准IEEE(电气和电子工程协会) 754，任意一个二进制浮点数v可以表现成下面形式；（科学计数法）
    //(-1)^s * M * 2^E
    //(-1)^s表示符号位,当s=0，v为正数，s=1，v为负数
    //M表示有效数字，大于等于1，小于2
    //2^E表示指数位
//例；
    //十进制5.0，写成二进制是101.0，相当于1.01 * 2^2 ,按照上面的公式可以得出 S=0， M=1.01， E=2；
    //代入公式 (-1)^0 * 1.01 * 2^2
    //内存中存的是。S  E  M
//IEEE 754规定：
// 对于32位浮点数，最高的一位是符号位S，接着8位是指数位E，剩下的23位为有效数字M（单精度浮点数）
//          对于64位浮点数，最高的一位是符号位S，接着11位是指数位E，剩下的52位为有效数字M （双精度浮点数）
//IEEE 754对有效数字M和指数E还有一些特别的规定：
    //有效数字M；在计算机内部保存M时，默认这个数的第一位总是以，因此可以被舍去，只保存后面的xxxxx部分，比如保存1.01的时候只保存01，等到读取的时候在把1加上去，这样做的目的是节省一位空间
    //指数E；首先E为一个无符号数但是我们知道，科学计数法中E是可以出现负数的，所以规定，存入内存中的真实值必须在加上一个中间数，对于8位的E，中间数的127，对于11位的E，中间数是1023比如  2^10的E值是10，所以保存32位浮点数时，必须存成10 + 127 = 137， 即10001001，
//然后指数E从内存中取出还可以在分成三种情况：
//E不全为0或不全为1:
// 即指数E的计算值减去127（1023），得到真实值，再将有效数字M前加上第一位的1，比如：0.5的二进制形式为0.1，由于规定正数部分必须为1，即将小数点右移1位，则为1.0 *2^-1,其阶码为-1+127=126，表示01111110，而尾数1.0去掉整数部分为0，补齐0到23位 00000000000000000000000其二进制表示为
    //0 01111110 00000000000000000000000
//E全为0:
    //这是，浮点数的指数E等于1-127（1023）即为真实值，有效数字M不再加上第一位的1，而是还原为0.xxxxxx的小数，这样做是为了表示+-0，以及接近于0的很小的数字
//E全为1:
    //这时如果有效数字M全为1，表示+-无穷大（正负取决于符号位）

//int main(int argc, const char * argv[]) {
////    十进制转二进制小数点前除2取余小数点后乘2取整
//    // insert code here...
//    float a = 0.25;
////    char *a = (char*) &a;
////    printf("ox%p")
////    int c = 4;
//    //(-1)^0 * 1 * 2-2^
//    // 0 01111100 00000000000000000000000
//
//    //    long long b = 10;
//    //    printf("%d", sizeof(b));
//    printf("%lf", a);
//    printf("Hello, World!\n");
//    return 0;
//}

int main()
{
    int n = 9;
//    00000000 00000000 00000000 00001001
    float* pf = (float *)&n;
    printf("n值%d\n", n);
//    0 00000000 0000000 00000000 00001001
    printf("pf值为%f\n", *pf);
    *pf = 9.0;
    printf("n值%d", n);
//    0 10000010 00100000000000000000000
//    01000001 00010000 00000000 00000000
    printf("pf值为%f", *pf);
    return 0;
}
