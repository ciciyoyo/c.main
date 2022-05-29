//
//  stck.h
//  5.29
//
//  Created by Rido on 2022/5/29.
//

#ifndef stck_h
#define stck_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define BIG 5
typedef int DAT;
typedef struct Stack{
    int current;
    int capacity;
    DAT* pList;
}Stack;
//初始化
void stackInit(Stack*);
//压栈
void stackPush(Stack*,int);
//出栈
void stackPop(Stack*);
//打印
void stackPrint(Stack*);
//释放
void stacDestroy(Stack*);
//取栈顶数据
DAT stackTop(Stack*);
//栈大小
void stackSize(Stack);
//栈是否为空
bool stackEmpry(Stack*);
#endif /* stck_h */
