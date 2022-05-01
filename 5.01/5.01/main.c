//
//  main.c
//  5.01
//
//  Created by Rido on 2022/5/1.
//

#include <stdio.h>
//一、动态内存管理 malloc  free  callor  realloc 四个函数
//栈区存放：局部变量，局部数组，函数的形参，
//堆区存放：动态内存分配 malloc  free  callor  realloc
//静态区：全局变量，全局数组，静态变量：（static创建的变量）

//二、为什么存在动态内存跟配
//  int val = 20；在栈上开辟四个字节
//  char arr[10] = {0};在栈上开辟是个字节的连续空间
//上述开辟空间有两个特点
//  1.空间开辟大小是固定的
//  2.数组在申明的时候必须指定数组的长度，它所需要的内存在编译时分配
//但是对开空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，数组的方式就不能满足了。这时候就只能试试动态内存开辟

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
