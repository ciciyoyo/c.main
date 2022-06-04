//
//  main.c
//  6.01
//
//  Created by Rido on 2022/6/4.
//

#include <stdio.h>
#include <stdlib.h>
//typedef struct StackNode {
//    int top;
//    int capacity;
//    int* lst;
//}StackNode;
//
//StackNode* stackGrate (void) {
//    StackNode* newNode = malloc(sizeof(StackNode));
//    newNode->lst = NULL;
//    newNode->top = 0;
//    newNode->capacity = 0;
//    return newNode;
//}
//void pushStack(StackNode* sn, int x) {
//    if (sn->top == sn->capacity) {
//        sn->capacity = sn->capacity == 0? 5: sn->capacity*2;
//        sn->lst = realloc(sn->lst, sizeof(int) * sn->capacity);
//    }
//    sn->lst[sn->top] = x;
//    sn->top++;
//
//}
//int getStack(StackNode* sn) {
//    if (sn->top) {
//        int tmp = sn->lst[sn->top-1];
//        sn->top--;
//        return tmp;
//    }
//    return -1;
//}
//
//typedef struct {
//    StackNode* qHead;
//    StackNode* qtail;
//} CQueue;
//
//CQueue* cQueueCreate(void) {
//    CQueue* queueNode = malloc(sizeof(CQueue));
//    queueNode->qHead = stackGrate();
//    queueNode->qtail = stackGrate();
//    return queueNode;
//}
//
//void cQueueAppendTail(CQueue* obj, int value) {
//    pushStack(obj->qHead, value);
//}
//
//int cQueueDeleteHead(CQueue* obj) {
//    if (!obj->qHead->top && !obj->qtail->top) {
//        return -1;
//    }
//    else if (!obj->qHead->top){
//        while(obj->qHead->top) {
//            int tmp = getStack(obj->qHead);
//            pushStack(obj->qtail, tmp);
//        }
//    }
//    return getStack(obj->qtail);
//}
//
//void cQueueFree(CQueue* obj) {
//    free(obj->qHead->lst);
//    free(obj->qtail->lst);
//    free(obj->qtail);
//    free(obj->qHead);
//    free(obj);
//    obj = NULL;
//}
//
//int main(int argc, const char * argv[]) {
//    CQueue* qNode = cQueueCreate();
//    cQueueAppendTail(qNode, 3);
//    int ret = cQueueDeleteHead(qNode);
//    printf("%d", ret);
//    cQueueFree(qNode);
//    return 0;
//}

typedef struct {
    int top;
    int minTop;
    int capacity;
    int* lst;
    int* min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate(void) {
    MinStack* StackNode = malloc(sizeof(MinStack));
    StackNode->top = 0;
    StackNode->minTop = 0;
    StackNode->capacity = 0;
    StackNode->lst = NULL;
    StackNode->min = NULL;
    return StackNode;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top == obj->capacity){
        obj->capacity = obj->capacity == 0? 5: obj->capacity* 2;
        obj->lst = realloc(obj->lst, sizeof(int) * obj->capacity);
        obj->min = realloc(obj->min,sizeof(int) * obj->capacity);
    }
    if (!obj->top) {
        obj->lst[obj->top] = x;
        obj->min[obj->top] = x;
        obj->top++;
        obj->minTop++;
    }
    else {
        obj->lst[obj->top] = x;
        if (x < obj->lst[obj->top-1]){
            obj->min[obj->minTop] = x;
            obj->minTop++;
        }
        obj->top++;
    }
    
}

void minStackPop(MinStack* obj) {
    if (obj->top) {
        if (obj->lst[obj->top-1] == obj->min[obj->minTop-1]){
            obj->minTop--;
        }
        obj->top--;
    }
   return;
}

int minStackTop(MinStack* obj) {
    if (obj->top) {
        return obj->lst[obj->top-1];
    }
    return -1;
}

int minStackMin(MinStack* obj) {
    if(obj->top) {
        return obj->min[obj->minTop-1];
    }
    return -1;
}

void minStackFree(MinStack* obj) {
    free(obj->lst);
    free(obj->min);
    free(obj);
    obj= NULL;
}
int main() {
    
    MinStack* Node = minStackCreate();
    minStackPush(Node, -2);
    minStackPush(Node, 0);
    minStackPush(Node, -1);
    int y = minStackMin(Node);
    int s = minStackTop(Node);
    minStackPop(Node);
    int z = minStackMin(Node);
    
//    minStackPop();
    printf("%d %d %d", y , s, z);
    minStackFree(Node);
    return 0;
    
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/
