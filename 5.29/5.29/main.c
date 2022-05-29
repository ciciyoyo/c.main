//
//  main.c
//  5.29
//
//  Created by Rido on 2022/5/29.
//

#include "stck.h"
//栈结构
void test1(void){
    Stack ps;
    stackInit(&ps);
    stackPush(&ps, 66);
    stackPush(&ps, 55);
    stackPush(&ps, 44);
    stackPush(&ps, 5);
    stackPush(&ps, 4);
    stackPush(&ps, 3);
    stackPush(&ps, 2);
    stackPush(&ps, 1);
    stackPop(&ps);
    stackPrint(&ps);
}
int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
