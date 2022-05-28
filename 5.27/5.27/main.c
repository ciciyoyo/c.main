//
//  main.c
//  5.27
//
//  Created by Rido on 2022/5/27.
//

#include "text.h"
//数据结构练习
//单链表
void demo1(void){
    struct SListNode* Plist = NULL;
//    SListInit(&Plist);
    //尾插
//    SListPushBack(&Plist, 1);
//    SListPushBack(&Plist, 2);
//    SListPushBack(&Plist, 3);
//    SListPushBack(&Plist, 4);
    //头插
    SListPushFront(&Plist, 1);
    SListPushFront(&Plist, 2);
    SListPushFront(&Plist, 3);
    SListPushFront(&Plist, 4);
    //头删
//    SListPopFront(&Plist);
//    SListPopFront(&Plist);
//    SListPopFront(&Plist);
//    SListPopFront(&Plist);
    
    //尾删
//    SListPopBack(&Plist);
//    SListPopBack(&Plist);
//    SListPopBack(&Plist);
//    SListPopBack(&Plist);
//    SListPopBack(&Plist);
   
}

void demo2(void) {
    
    //头插
//    struct SListNode* Plist = NULL;
    
//    SLTNode* findOut = SListFindNode(Plist, 3);
//    SListPrint(findOut);
}
//void demoe(void) {
//    SListPushFront(Plist, 1);
//}
void demo3(void) {
    SLTNode* Plist = NULL;
    //查找
//    SListPushFront(&Plist, 1);
//    SListPushFront(&Plist, 2);
    SListPushFront(&Plist, 3);
    //查找
    SLTNode* ret = SListFindNode(Plist, 3);
    SListInsertNode(&Plist, ret, 30);
//    int i= 1;
//    while(ret) {
//        printf("第%d个 %p pos—>%d\n", i++, ret, ret->data);
//        ret = SListFindNode(ret->next, 3);
//
//    }
    SListPrint(Plist);
}
void demo4(void) {
    SLTNode* Plist = NULL;
    SListPushFront(&Plist, 1);
    SListPushFront(&Plist, 2);
    SListPushFront(&Plist, 3);
    SListPushFront(&Plist, 4);
//    SListPrint(Plist);
    SlistDestroy(&Plist);
    SListPrint(Plist);
}
int main(int argc, const char * argv[]) {
//    demo1();
//    demo2();
//    demo3();
    demo4();
    return 0;
}
