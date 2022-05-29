//
//  stck.c
//  5.29
//
//  Created by Rido on 2022/5/29.
//

#include "stck.h"
//创建
Stack* greatStack(Stack* ps){
    int newCapacity = ps->capacity == 0? 4: ps->capacity*2;
    DAT* p = realloc(ps->pList, sizeof(int)*newCapacity);
    if (!p){
        perror("开辟失败");
        exit(-1);
    }
    ps->capacity = newCapacity;
    ps->pList = p;
    return ps;
}
//初始化
void stackInit(Stack* ps){
    assert(ps);
    ps->capacity = 0;
    ps->current = 0;
    ps->pList = NULL;
}
//压栈
void stackPush(Stack* ps, int x){
    assert(ps);
    if(ps->current == ps->capacity){
        ps = greatStack(ps);
    }
    ps->pList[ps->current] = x;
    ps->current++;
}
//出栈
void stackPop(Stack* ps){
    assert(ps);
    assert(ps->current > 0);
    ps->current--;

}

//打印
void stackPrint(Stack* ps){
    assert(ps);
    assert(ps->current > 0);
    int tmp = ps->current;
    while(tmp){
        printf("%d \t", ps->pList[tmp-1]);
        tmp--;
    }
}
