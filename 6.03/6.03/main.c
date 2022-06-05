//
//  main.c
//  6.03
//
//  Created by Rido on 2022/6/5.
//

#include <stdio.h>
#include <stdlib.h>
//二叉树层次遍历（用队列来实现）
//树结构
typedef struct TreeNode{
    int data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

//队列结构
typedef struct QueueNode{
    TreeNode* data;
    struct QueueNode* prev;
    struct QueueNode* next;
}QueueNode;

//创建树
void creatTree(TreeNode** pt) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *pt = NULL;
    }
    else {
        *pt = (TreeNode*)malloc(sizeof(TreeNode));
        (*pt)->data = ch;
        creatTree(&(*pt)->lchild);
        creatTree(&(*pt)->rchild);
    }
}

//打印树
void printTree(TreeNode* pt) {
    if (pt == NULL) {
        return;
    }
    else {
        printf("%c ", pt->data);
        printTree(pt->lchild);
        printTree(pt->rchild);
    }
}

//创建队列
QueueNode* creatQueue(void) {
    QueueNode* pq = (QueueNode*)malloc(sizeof(QueueNode));
    pq->next = pq;
    pq->prev = pq;
    return pq;
}

//判断队是否为空
int isEmpty(QueueNode* pq) {
    if (pq->next == pq) {
        return 1;
    }
    else {
        return 0;
    }
}

//入队
void pushQueue(QueueNode* pq, TreeNode* pt) {
    QueueNode* newPQ = (QueueNode*)malloc(sizeof(QueueNode));
    newPQ->data = pt;
    newPQ->next = pq;
    newPQ->prev = pq->prev;
    pq->prev->next = newPQ;
    pq->prev = newPQ;
}

//出队
QueueNode* popQueue(QueueNode* pq) {
    if(isEmpty(pq)) {
        return NULL;
    }
    else {
        QueueNode* tmp = pq->next;
        tmp->next->prev = pq;
        pq->next = tmp->next;
        return tmp;
    }
}
//打印队列
void printQueue(QueueNode* pq) {
    QueueNode* tmp = pq->next;
    while(tmp != pq) {
        printf("%c \n", tmp->data->data);
        tmp = tmp->next;
    }
}

//层次遍历
void levelTra(TreeNode* pt, QueueNode* pq){
    
    if (!pt){
        return;
    }
    else {
        pushQueue(pq, pt);
        while(!isEmpty(pq)) {
            QueueNode* ret = popQueue(pq);
            printf("%c ", ret->data->data);
            if (ret->data->lchild) {
                pushQueue(pq, ret->data->lchild);
            }
            if (ret->data->rchild) {
                pushQueue(pq, ret->data->rchild);
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    QueueNode* pq = creatQueue();
    TreeNode* pt;
    creatTree(&pt);
//    printTree(pt);
    levelTra(pt, pq);
//    printQueue(pq);
    return 0;
}
