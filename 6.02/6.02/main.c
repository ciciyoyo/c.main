//
//  main.c
//  6.02
//
//  Created by Rido on 2022/6/5.
//

#include <stdio.h>
#include <stdlib.h>
//二叉树 前中后序遍历
typedef struct TreeNode{
    char data;
    struct TreeNode* lChild;
    struct TreeNode* rChild;
}TreeNode;

void treeCreat(TreeNode** t) {
    char ch;
    printf("请输入字符数据\n");
    scanf("%c", &ch);
    if (ch == '#'){
        *t = NULL;
    }
    else {
        *t = (TreeNode*)malloc(sizeof(TreeNode));
        (*t)->data = ch;
        treeCreat(&((*t)->lChild));
        treeCreat(&((*t)->rChild));
    }
}
void preTree(TreeNode* t) {
    if (t) {
        printf("%c ", (t->data));
        preTree(t->lChild);
        preTree(t->rChild);
    }
}
void nextTree(TreeNode* t) {
    if (t) {
        nextTree(t->lChild);
        printf("%c ", (t->data));
        nextTree(t->rChild);
    }
    else
        return;
}
int main(int argc, const char * argv[]) {
    TreeNode* tNew = NULL;
    treeCreat(&tNew);
//    preTree(tNew);
    nextTree(tNew);
    return 0;
}
