//
//  List.c
//  5.28
//
//  Created by Rido on 2022/5/28.
//

#include "List.h"
//SLNode* SLGreat(LTATA x) {
//    SLNode* newNode;
//    newNode = malloc(sizeof(SLNode*));
//    newNode->data = x;
//    newNode->next = NULL;
//    newNode->prev = NULL;
//    return newNode;
//}

LTNode* ListInit(void){
    LTNode* plist = NULL;
    plist = (LTNode*)malloc(sizeof(LTNode*));
    plist->next = plist;
    plist->prev = plist;
    return plist;
}

void ListPushBack(LTNode* plist) {
    
    
}
