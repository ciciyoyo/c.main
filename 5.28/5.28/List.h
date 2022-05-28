//
//  List.h
//  5.28
//
//  Created by Rido on 2022/5/28.
//

#ifndef List_h
#define List_h
#include <stdlib.h>
#include <stdio.h>
typedef int LTDATA;
typedef struct LTNode{
    struct LTNode* next;
    struct LTNode* prev;
    LTDATA data;
}LTNode;

//链表初始化
LTNode* ListInit();
//头插
//尾插
void ListPushBack(LTNode*);
//头删
//尾删
//查找
//指定位置插入

#endif /* List_h */
