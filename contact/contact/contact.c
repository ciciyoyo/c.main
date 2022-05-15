//
//  contact.c
//  contact
//
//  Created by Rido on 2022/5/14.
//

#include "contact.h"

void Menu(void)
{
    printf("***************************\n");
    printf("****1. add     2.search ***\n");
    printf("****3. del     4.mod    ***\n");
    printf("****5.save      0.exit  ***\n");
    printf("***************************\n");
}
void Init(Contact* con)
{
    con->lst = (Peoinfo*)malloc(sizeof(Peoinfo)*2);
    if(con->lst== NULL)
    {
        perror("开辟空间失败");
    }
    con->size = 0;
    con->capacity = 2;
}
void if_sz(Contact* con)
{
    if (con->size == con->capacity){
        con->capacity += 2;
        Peoinfo* tmp = realloc(con->lst, sizeof(Peoinfo)*con->capacity);
        if(tmp)
        {
            con->lst = tmp;
            printf("增容成功\n");
        }
        else
        {
            printf("增容失败\n");
        }
       
    }
}

void Add(Contact* data)
{
    if_sz(data);
//
    printf("请输入姓名：\n");
    scanf("%s",data->lst[data->size].name);
    printf("请输入年龄：\n");
    scanf("%d", &(data->lst[data->size].age));
    printf("请输入性别：\n");
    scanf("%s", data->lst[data->size].sex);
    printf("请输入电话：\n");
    scanf("%s", data->lst[data->size].tel);
    printf("请输入地址：\n");
    scanf("%s", data->lst[data->size].addres);
    data->size++;
}
void Search(Contact* data)
{
    printf("姓名      年龄       性别       电话         地址\n");
    int i;
    for (i = 0; i< data->size;i++)
    {
        printf("%s       ", data->lst[i].name);
        printf("%d       ", data->lst[i].age);
        printf("%s       ", data->lst[i].sex);
        printf("%s       ", data->lst[i].tel);
        printf("%s\n", data->lst[i].addres);
    }
}
void Del(Contact* pd)
{
    char del_name[NAME_SZ];
    printf("请输入你要删除人的姓名：\n");
    scanf("%s", del_name);
    int i;
    for (i= 0; i < pd->size;i++)
    {
        if (!(strcmp(del_name, pd->lst[i].name)))
        {
            int j;
            for (j = i; j < pd->size; j++)
            {
                pd->lst[j] =  pd->lst[j+1];
            }
            pd->size--;
            printf("删除成功\n");
            return;
        }
    }
    if (i == pd->size)
    {
        printf("没有此人信息\n");
    }
}
