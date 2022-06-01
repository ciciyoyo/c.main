//
//  queue.h
//  5.30
//
//  Created by Rido on 2022/6/1.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int TypeData;

typedef struct QueueNode{
    TypeData data;
    struct QueueNode* next;
}QNode;

typedef struct Queue{
    QNode* Qhead;
    QNode* Qtail;
}Queue;


void dataInit(Queue*);

void pushQueue(QNode*, TypeData);

void popQueue();

void queueFront();

void queueBack();

void queueSize();

bool queueEmpty();

void queueDestroy();


#endif /* queue_h */
