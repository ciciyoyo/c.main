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
#include <assert.h>
typedef int LTDATA;
typedef struct LTNode{
    LTDATA data;
    struct LTNode* next;
    struct LTNode* prev;
}LTNode;

//链表初始化
LTNode* ListInit(void);
//打印链表
void ListPrint(LTNode*);
//头插
void ListPushFront(LTNode*, LTDATA);
//尾插
void ListPushBack(LTNode*, LTDATA);
//头删
void ListPopFront(LTNode*);
//尾删
void ListPopBack(LTNode*);
//查找
LTNode* ListFindNode(LTNode*, LTDATA);
//指定位置插入
void ListInsertNode(LTNode*, LTDATA);
//指定位置删除
void ListEraseNode(LTNode*);
//释放空间
void ListDestroy(LTNode*);
#endif /* List_h */
