//
//  main.c
//  4.26
//
//  Created by Rido on 2022/4/26.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
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

//二、长度不受限值的字符串函数
//strcpy strcat strcmp
//1、strcpy(目的地, 源) 字符串拷贝
//源字符串必须是以\0结束的，目标空间足够大，目标空间必须可变
//char * my_strcpy(char* dest, const char* src){
//    assert(dest!= NULL);
//    assert(src!= NULL);
//    char* ret = dest;
//    while(*dest++ = *src++) {
//    }
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
char * my_strcat(char* s1, char* s2) {
    assert(s1 && s2);
    char* ret = s1;
    while(*s1) {
        s1++;
    }
    while((*s1++ = *s2++))
        ;
    return ret;
}
int main() {
    char arr1[30] = "hello";
    char arr2[] = "word";
    strcat(arr1, arr2);
    printf("arr1=%s", arr1);
    return 0;
}

//三、长度受限制的字符串函数  strncpy strncat strncmp
//四、字符串查找 strstr  strtok
//五、错误信息报告 strerror
//六、字符操作
//七、内存操作函数。memcpy memmove memset memcmp
