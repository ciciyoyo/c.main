//
//  text.h
//  5.27
//
//  Created by Rido on 2022/5/28.
//

#ifndef text_h
#define text_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;

typedef struct SListNode {
    SLTDateType data;
    struct SListNode* next;
} SLTNode;

void SListInit(SLTNode**);
//打印链表
void SListPrint(SLTNode*);
//尾插
void SListPushBack(SLTNode**, SLTDateType);
//头插
void SListPushFront(SLTNode**, SLTDateType);
//头删
void SListPopFront(SLTNode**);
//尾删
void SListPopBack(SLTNode**);
//查找
SLTNode* SListFindNode(SLTNode*, SLTDateType);
//指定位置插入
void SListInsertNode(SLTNode**, SLTNode*, SLTDateType);
//释放指定节点空间
void SListEase(SLTNode*, SLTNode*, SLTDateType);
//释放全部空间
void SlistDestroy(SLTNode**);

#endif /* text_h */
