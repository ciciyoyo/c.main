//
//  contact.h
//  contact
//
//  Created by Rido on 2022/5/14.
//

#ifndef contact_h
#define contact_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CASE break; case
#define NAME_SZ 20
#define TEL_SZ 11
#define SEX_SZ 5
#define ADRS_SZ 20

enum opt//枚举用户输入的选择
{
    eit,
    add,
    search,
    del,
    mod,
    save
};

//个人信息
typedef struct Peoinfo
{
    char name[NAME_SZ];
    int age;
    char sex[SEX_SZ];
    char tel[TEL_SZ];
    char addres[ADRS_SZ];
   
}Peoinfo;

//信息类型
typedef struct Contact
{
    int size;//当前用户个数
    int capacity;//通讯录容量
    Peoinfo* lst;//存放的信息
}Contact;

void Menu(void);//打印菜单
void Init(Contact*);//初始化
void Add(Contact*);//增加
void Search(Contact*);//查看
void Del(Contact*);//删除
void Mod(Contact*);//修改
void Save(Contact*);//保存
void loadContact(Contact*);//加载

#endif /* contact_h */
