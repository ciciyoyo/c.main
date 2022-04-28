//
//  main.c
//  4.26
//
//  Created by Rido on 2022/4/26.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
//字符函数和字符串函数还有内存函数
//前言：c语言中没有字符串类型的，字符串通常放在常量字符串中或者字符数组中，
//字符串常量 适用于那些对它不做修改的字符串函数

//一、求字符串长度 strlen 返回size_t无符号整型
//size_t就是无符号数重新命名得来的
//int main(int argc, const char * argv[]) {
//    int len = strlen("abcdef");//找'\0'计数器++
//    printf("%d", len);
//    return 0;
//}

//二、长度不受限值的字符串函数'\0'作为结束标志（不够安全）
//strcpy strcat strcmp
//1、strcpy(目的地, 源) 字符串拷贝
//源字符串必须是以\0结束的，目标空间足够大，目标空间必须可变
//char * my_strcpy(char* dest, const char* src){
//    assert(dest!= NULL);
//    assert(src!= NULL);
//    char* ret = dest;
//    while(*dest++ = *src++);
//    return ret;
//}
//int main() {
//    char arr1[] = "abcdefghi";
//    char arr2[] = "bit";
//    my_strcpy(arr1, arr2);
//    arr1[3] = 'r';
//    printf("%s\n", arr1);
//    return 0;
//}
//2、strcat(目的地, 源)字符串追加
//源字符串和目的地字符串必须是以\0结束的, 目标空间足够大，目标空间必须可变
//
//char * my_strcat(char* s1, char* s2) {
//    assert(s1 && s2);
//    char* ret = s1;
//    while(*s1) {
//        s1++;
//    }
//    while(*s1++ = *s2++)
//        ;
//    return ret;
//}
//int main() {
//    char arr1[30] = "hello";
//    char arr2[] = "word";
//    strcat(arr1, arr2);
//    printf("arr1=%s", arr1);
//    return 0;
//}
//3、strcmp(s1, s2)比较字符对应的ascii值
//字符串比较,如果s1<s2返回一个>0的数字，相等返回0...
//long my_strcmp(const char* s1, const char* s2) {
//    assert(s1 && s2);
//    while(*s1||*s2) {
//        while(*s1 != *s2 ) {
//            return *s1-*s2;
//        }
//        s1++;
//        s2++;
//    }
//    return  0;
//}
//int main() {
//    char* p1 = "kcllo";
//    char* p2 = "kcllk";
//    long ret = my_strcmp(p1, p2);
//    printf("%ld", ret);
//}

//三、长度受限制的字符串函数（有个数限制）(不关心'\0')
//strncpy strncat strncmp
//strncpy(s1, s2, 3) strncat(s1, s2, 2) strncmp(s1, s2, 3)

//四、字符串查找 strstr  strtok
//strstr(s1,s2)在s1里面查找子串s2是否存在，找到返回地址，否则返回NULL
//库方法：
//char* my_strstr(const char* p1, const char* p2) {
//    assert(p1 && p2);
//    char *s1, *s2;
//    char* cp = (char*)p1;
//    if(!*p2) {
//        return (char*) p1;
//    }
//    while(*cp)
//    {
//        s1 = cp;
//        s2 = (char*)p2;
//        while(*s1 && *s2 && !(*s1-*s2))
//            s1++, s2++;
//        if (!(*s2))
//            return cp;
//        cp++;
//    }
//    return NULL;
//}KMP算法//
//char* my_strstr(const char* p1, const char* p2) {
//    //buhui
//}
//int main() {
//    char* p1 = "asaaadzxc";
//    char* p2 = "aad";
//    char* ret = my_strstr(p1, p2);
//    printf("%s", ret);
//    return 0;
//}
//strtok(str,sep)分割字符串
//第一个参数指定一个字符串，它包含了0个或者多个有sep字符串中的一个或者多个分隔符分割的标记
//strtok函数找到str中的下一个标记，并将其用\0改掉，返回指向这个标记的指针（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且修改）
//strtok函数的第一个参数不为NULL时，函数将找到str中的第一个标记，strtok函数将保存它在字符串中的位置。
//strtok函数的第一个参数为NULL时，函数将在同一个字符串中被保存的位置开始，查找下一个标记
//如果字符串中不存在更多的标记，则返回NULL指针
//int main() {
//    char arr[] = "rido~@.qq.com";
//    char *p = "@~";
//    char *b = ".";
//    char cpy[255] = {0};
//    strcpy(cpy, arr);
//    char *ret = NULL;
//    for(ret=strtok(cpy, p); ret != NULL;ret= strtok(NULL, b))
//    {
//        printf("%s\n",ret);
//    }
////    char* ret1 = strtok(arr, p);
////    char* ret2 = strtok(NULL, p);
////    char* ret3 = strtok(NULL, p);
////    printf("%s",ret3);
//    return 0;
//}

//五、错误信息报告 strerror 返回错误吗，所对应的错误信息。
//#include <errno.h>
//int main()
//{
    //错误码   错误信息
    //0--     未定义的错误 Undefined error
    //1--     peration not permitted
    //2--     No such file or directory
    //...
    //errno   是一个全局的错误码的变量（需要引用头文件
    //当c语言的库函数在执行中，发生错误，就会把对应的错误码赋值到errno中
//    char* str0 =strerror(0);
//    char* str1 = strerror(1);
//    char* str2 = strerror(2);
//    printf("%s\n",str1);
//    FILE* pf = fopen("rido.txt", "r");
//    if (pf == NULL)
//        printf("%s\n", strerror(errno));//没有找到文件
//    else{
//        printf("open file success\n" );
//    }
//    return 0;
//}
    
//六、字符操作
//字符分类函数
//iscntrl    任何控制字符
//isspace    空白字符空格'',换页\f,换行\n,回车\r,制表符\t垂直制表符\v
//isdigit    十进制数字0-9
//isxdigit   十六进制数字，包括所有十进制数字，小写字母a~f,大写字符A~F
//islower    小写字母a~z
//isupper    大写字母A~Z
//isalpha    字母a~z或A~Z
//isalnum    字母或者数字，a~z, A~Z, 0~9
//ispunct    标点符号，任何不属于数字或者字母的图形字符（可打印）
//isgraph    任何图形字符
//isprint    任何可打印字符，包括图形字符和空白字符
//字符转换 tolower(int c); toupper(int c)
//int main() {
//    char ch = 'w';
//    int ret = islower(ch);
//    printf("%d\n", ret);
//    char a = toupper(ch);
//    printf("%c\n",a);
//    return 0;
//}

//七、内存操作函数。memcpy memmove memset memcmp
//memcpy(void*， void*， num)内存拷贝num单位是字节
//库实现方法，对内存重叠的数据会出问题
//void* my_memcpy(void* des, const void* src, int n) {
//    void* ret = des;
//    while(n--) {
//        *(char*)des = *(char*)src;
//        des = (char*)des +1;
//        src = (char*)src +1;
//    }
//    return ret;
//}
//void* my_memcpy(void* des, const void* src, int n) {
//    void* ret = des;
//    while(n--) {
//        *(char*)des = *(char*)src;
//        des = (char*)des +1;
//        src = (char*)src +1;
//    }
//    return ret;
//}
//int main() {
//    int i;
//    int arr1[] = {1, 2, 3, 4, 5,6,7,8,9,10};
//    int arr2[5] = {0};
//    memcpy(arr2, arr1, 16);
//    struct s arr3[3]={{"rido",12},{"yangyang",13},{"riko", 5}};
//    struct s arr4[3];
//    memcpy(arr1+2, arr1, 20);
//    for (i = 0; i< 10; i++) {
//        printf("%d\n", arr1[i]);
//    }
//    return 0;
//}
//memmove()也是内存拷贝 但是它可以对内存重叠的数据处理
//库函数实现方法
//void* my_memmove(void* des, const void* src, int n) {
//    void* ret = des;
//    if(des < src){
//        //前->后
//        while(n--) {
//            *(char*)des = *(char*)src;
//            des = (char*)des +1;
//            src = (char*)src +1;
//        }
//    }
//    else
//    {
//        //后->前
//        while(n--) {
//            //n刚进来就是19
//        *((char*)des+n) = *((char*)src+n);
//        }
//    }
//        return ret;
//}
//int main() {
//    int i;
//    int arr1[] = {1, 2, 3, 4, 5,6,7,8,9,10};
//    my_memmove(arr1, arr1+2, 20);
//
//    for (i = 0; i< 10; i++) {
//        printf("%d\n", arr1[i]);
//    }
//    return 0;
//}
//memcmp(void1*，void2*，num)内存比较num是个数，如果1*>2*返回大于1
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 5, 4, 3};
    int ret = memcmp(arr1, arr2, 10);
    printf("%d", ret);
    return 0;
}
