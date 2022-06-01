//
//  queue.c
//  5.30
//
//  Created by Rido on 2022/6/1.
//

#include "queue.h"
void dataInit(Queue* tt){
    tt->Qhead = NULL;
    tt->Qtail = NULL;
}
void EnQueue(Queue* QLst, TypeData x){
    assert(QLst);
    QNode* tmp = (QNode*)malloc(sizeof(QNode));
    tmp->next = NULL;
    tmp->data = x;
    if (!QLst->Qhead){
        QLst->Qhead = tmp;
        QLst->Qtail = tmp;
    }
    else {
        QLst->Qtail->next = tmp;
        QLst->Qtail = tmp;
    }
}

void DeQueue(void){
    
}
