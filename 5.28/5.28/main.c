//
//  main.c
//  5.28
//
//  Created by Rido on 2022/5/28.
//
//双向带头链表
#include "List.h"
void test1(void){
    LTNode* plist = NULL;
    plist = ListInit();
    //尾插
    ListPushBack(plist, 66);
    ListPushBack(plist, 55);
    ListPushBack(plist, 44);
    ListPushBack(plist, 33);
    //头插
//    ListPushFront(plist, 22);
//    ListPushFront(plist, 77);
//    ListPushFront(plist, 44);
//    ListPushFront(plist, 33);
    //尾删
//    ListPopBack(plist);
//    ListPopBack(plist);
//    ListPopBack(plist);
//    ListPopBack(plist);
//    ListPopBack(plist);
    //头删
    ListPopFront(plist);
    ListPopFront(plist);
//    ListPopFront(plist);
//    ListPopFront(plist);
//    ListPopFront(plist);
//    LTNode* result = ListFindNode(plist, 44);
//    ListInsertNode(result, 40);
//    LTNode* pos = ListFindNode(plist, 66);
//    ListEraseNode(pos);
    
    ListPrint(plist);
    
    ListDestroy(plist);
    plist = NULL;
}

void test2(void) {
    
}
int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
