//
//  text.c
//  5.27
//
//  Created by Rido on 2022/5/28.
//
#include "text.h"

void SListInit(SLTNode** Plist){
    SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode*));
    if (!tmp){
        perror("maclloc开辟空间失败");
        exit(-1);//退出程序
    }
    *Plist = tmp;
}
SLTNode* buyNode(SLTDateType x){
    SLTNode* new = malloc(sizeof(SLTNode*));
    new->data = x;
    new->next = NULL;
    return new;
}

void SListPrint(SLTNode* Plist) {
    assert(Plist);
    SLTNode* cur = Plist;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
//尾插
void SListPushBack(SLTNode** Plist, SLTDateType x){
    SLTNode* tail = *Plist;
    SLTNode* newNode = buyNode(x);
    if (!*Plist) {
        *Plist = newNode;
    }
    else {
        while(tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}
//头插
void SListPushFront(SLTNode** Plist, SLTDateType x){
    //开辟一个新的空间
    SLTNode* newNode = buyNode(x);
    newNode->next = *Plist;
    *Plist = newNode;
}
//头删
void SListPopFront(SLTNode** Plist){
    assert(*Plist);
    SLTNode* tmp = (*Plist)->next;
    free(*Plist);
    *Plist= tmp;
}
//尾删
void SListPopBack(SLTNode** Plist){
    assert(*Plist);
    SLTNode* tail = *Plist;
    SLTNode* prev = NULL;
    if(!(*Plist)->next){
        free(*Plist);
        *Plist = NULL;
    }
    else{
        while(tail->next){
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;
    }
}
//查找
SLTNode* SListFindNode(SLTNode* Plist, SLTDateType x) {
    assert(Plist);
    SLTNode* cur = Plist;
    while(cur){
        if (cur->data == x) {
            return cur;
        }
        else {
            cur= cur->next;
        }
    }
    return NULL;
}
//下标节点插入
void SListInsertNode(SLTNode** Plist, SLTNode* pos, SLTDateType x){
    assert(pos);
    SLTNode* new = buyNode(x);
    SLTNode* cur = *Plist;
    if (*Plist == pos) {
        new->next = cur;
        *Plist = new;
    }
    else {
        while(cur->next != pos) {
            cur = cur->next;
        }
        new->next = cur->next;
        cur->next = new;
    }
}

//释放空间
void SlistDestroy(SLTNode** Plist) {
    SLTNode* cur = *Plist;
    SLTNode* tmp = NULL;
    while(cur) {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    *Plist = NULL;
}
