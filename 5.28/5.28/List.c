//
//  List.c
//  5.28
//
//  Created by Rido on 2022/5/28.
//

#include "List.h"
LTNode* LTGreat(LTDATA x) {
    LTNode* newNode;
    newNode =(LTNode*)malloc(sizeof(LTNode));
    if (!newNode) {
        perror("开辟空间失败");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//初始化
LTNode* ListInit(void){
    LTNode* plist = NULL;
    plist = (LTNode*)malloc(sizeof(LTNode));
    plist->next = plist;
    plist->prev = plist;
    return plist;
}
//打印
void ListPrint(LTNode* plist) {
    assert(plist);
    LTNode* cur = plist->next;
    while(cur != plist) {
        
        printf("%d\t", cur->data);
        cur = cur->next;
    }
}
//头插
void ListPushFront(LTNode* plist, LTDATA x){
//    assert(plist);
//    LTNode* newNode = LTGreat(x);
//    LTNode* front = plist->next;
//    newNode->next = front;
//    front->prev = newNode;
//    plist->next = newNode;
//    newNode -> prev = plist;
    ListInsertNode(plist->next, x);
}
//尾插
void ListPushBack(LTNode* plist, LTDATA x) {
    assert(plist);
    LTNode* newNode = LTGreat(x);
    LTNode* tail = plist->prev;
    plist->prev = newNode;
    newNode->next = plist;
    newNode->prev = tail;
    tail->next = newNode;
    
//    ListInsertNode(plist, x);
}
//头删
void ListPopFront(LTNode* plist) {
    assert(plist);
    assert(plist->next != plist);
//    LTNode* head = plist->next;
//    plist->next = head->next;
//    head->next->prev = plist;
//    free(head);
//    head = NULL;
    ListEraseNode(plist->next);
}
//尾删
void ListPopBack(LTNode* plist) {
    assert(plist);
    assert(plist->next != plist);
//    LTNode* tail = plist->prev;
//    tail -> prev ->next  = plist;
//    plist->prev = tail -> prev;
//    free(tail);
//    tail = NULL;
    ListEraseNode(plist->prev);
}
//查找
LTNode* ListFindNode(LTNode* plist, LTDATA x){
    assert(plist);
    assert(plist->next != plist);
    LTNode* search = plist->next;
    while(search != plist){
        if (search->data == x){
            return search;
        }
        else {
            search = search -> next;
        }
    }
    return NULL;
}
//指定位置插入
void ListInsertNode(LTNode* pos, LTDATA x){
    assert(pos);
    LTNode* newNode = LTGreat(x);
    pos->prev->next = newNode;
    newNode ->prev = pos ->prev;
    newNode->next = pos;
    pos->prev = newNode;
    
}
void ListEraseNode(LTNode* pos){
    assert(pos);
    LTNode* posPrev = pos->prev;
    LTNode* posNext = pos->next;
    posPrev->next = posNext;
    posNext->prev = posPrev;
    free(pos);
}
//释放
void ListDestroy(LTNode* plist){
    LTNode* head = plist->next;
    LTNode* tmp = NULL;
    while(head != plist){
        tmp = head->next;
        free(head);
        head = tmp;
    }
    free(plist);
}
