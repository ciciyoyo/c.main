//
//  main.c
//  contact
//
//  Created by Rido on 2022/5/14.
//

#include "contact.h"
int main(int argc, const char * argv[]) {
    int input;
    Contact con;//创建通讯录
    Init(&con);//初始化通讯录
    do{
        //打印菜单
        Menu();
        printf("请输入你的选择：\n");
        scanf("%d", &input);
        switch (input) {
            CASE eit:
                printf("程序退出\n");
            CASE add:
                Add(&con);
            CASE search:
                Search(&con);
            CASE del:
                Del(&con);
            CASE mod:
                printf("hehe3\n");
            CASE save:
                printf("hehe5\n");
            default:
                printf("你输入有误请重新输入\n");
        }
    }while (input);
    return 0;
}
