//
//  contact.c
//  contact
//
//  Created by Rido on 2022/5/14.
//

#include "contact.h"
//打印菜单
void Menu(void)
{
    printf("***************************\n");
    printf("****1. add     2.search ***\n");
    printf("****3. del     4.mod    ***\n");
    printf("****5.save      0.exit  ***\n");
    printf("***************************\n");
}
void if_sz(Contact*);
void loadContact(Contact* con)
{
    Peoinfo tmp = {0};
    FILE* fp = fopen("/Users/lidong/Desktop/demo/contact/contact/contact.txt", "rb");
    if (fp == NULL)
    {
        perror("读取文件失败：");
        return;
    }
    while(fread(&tmp, sizeof(Peoinfo), 1, fp))
    {
        if_sz(con);
        con->lst[con->size] = tmp;
        con->size++;
    }
    fclose(fp);
    fp = NULL;
}
//初始化通讯录
void Init(Contact* con)
{
    con->lst = (Peoinfo*)malloc(sizeof(Peoinfo)*2);
    if(con->lst== NULL)
    {
        perror("开辟空间失败");
    }
    con->size = 0;
    con->capacity = 2;
    //加载通讯录
    loadContact(con);
}
//判断空间
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
//查找name函数
int sea_name(Contact* pr, char * arr)
{
    int i;
    for (i= 0; i < pr->size; i++)
    {
        if (!(strcmp(pr->lst[i].name,arr)))
            return i;
    }
    return -1;
}
//添加函数
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
//查找函数
void Search(Contact* data)
{
    printf("%-20s\t%-4s\t%-5s\t%-13s\t%-20s\t\n","姓名","年龄","性别","电话","地址");
    int i;
    for (i = 0; i< data->size;i++)
    {
        printf("%-20s", data->lst[i].name);
        printf("%-4d", data->lst[i].age);
        printf("%-5s", data->lst[i].sex);
        printf("%-13s", data->lst[i].tel);
        printf("%-20s\n", data->lst[i].addres);
    }
}
//删除函数
void Del(Contact* pd)
{
    char del_name[NAME_SZ];
    printf("请输入你要删除人的姓名：\n");
    scanf("%s", del_name);
    int ret = sea_name(pd, del_name);
    printf("%d",ret);
    if(ret != -1)
    {
        int j;
        for (j = ret; j < pd->size; j++)
        {
            pd->lst[j] =  pd->lst[j+1];
            pd->size--;
            printf("删除成功\n");
        }
    }
    else
    {
        printf("没有找到此人");
    }
}
void Mod(Contact* pm)
{
    char name[NAME_SZ];
    printf("请输入你要修改人的名字");
    scanf("%s", name);
    int ret = sea_name(pm, name);
    if (ret != -1)
    {
        printf("请输入修改后姓名：\n");
        scanf("%s",pm->lst[ret].name);
        printf("请输入修改后年龄：\n");
        scanf("%d", &pm->lst[ret].age);
        printf("请输入修改后性别：\n");
        scanf("%s", pm->lst[ret].sex);
        printf("请输入修改后电话：\n");
        scanf("%s",pm->lst[ret].tel);
        printf("请输入修改后地址：\n");
        scanf("%s", pm->lst[ret].addres);
        printf("修改成功\n");
    }
    else
    {
        printf("未找到此人");
    }
}
//保存函数
void Save(Contact* ps)
{
    FILE* fp= fopen("/Users/lidong/Desktop/demo/contact/contact/contact.txt", "wb");
    if(fp == NULL)
    {
        perror("文件打开失败");
        return;
    }
    int i;
    for (i = 0; i < ps->size; i++)
    {
        fwrite(&(ps->lst[i]), sizeof(Peoinfo), 1, fp);
    }
    fclose(fp);
    fp = NULL;
}
