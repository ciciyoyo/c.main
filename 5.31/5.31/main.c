//
//  main.c
//  5.31
//
//  Created by Rido on 2022/5/31.
//

#include <stdio.h>
#include <stdlib.h>
//KMP算法实现字符串匹配
typedef struct String{
    char * data;
    int len;
}String;

String* initStr(void){
    String* pcr = (String*)malloc(sizeof(String));
    if (!pcr){
        printf("开辟失败");
        exit(-1);
    }
    pcr->data = NULL;
    pcr->len = 0;
    return pcr;
}
void assign(String* pcr, char * data){
    if (pcr->data){
        free(pcr->data);
    }
    int len = 0;
    char* tmp = data;
    while (*tmp) {
        len++;
        tmp++;
    }
    if (len == 0) {
        pcr->data = NULL;
        pcr->len = 0;
    }
    else {
        tmp = data;
        pcr->len = len;
        pcr->data = (char*) malloc(sizeof(char) * (len+1));
        for (int i = 0; i < len; i++, tmp++) {
            pcr->data[i] = *tmp;
        }
    }
}
void printStr(String* pcr) {
    for (int i = 0; i < pcr->len; i++) {
        printf(i == 0 ? "%c ": "-> %c " , pcr->data[i]);
    }
    printf("\n");
}
int * getNext(String* pcr) {
    int* next = (int*)malloc(sizeof(int) * pcr->len);
    int i = 0;
    int j = -1;
    next[i] = j;
    while(i < pcr->len-1) {
        if (j == -1 || pcr->data[i] == pcr->data[j]) next[++i] = ++j;

        else j = next[j];
    }
    return next;
}
void printNext(int* next, int len){
    for (int i = 0; i < len; i++) {
        printf(i == 0 ? "%d ": "-> %d " , next[i]+1);
    }
    printf("\n");
}
void KMPMatch(String* pcr , String* car, int* next) {
    int i = 0;
    int j = 0;
    while(i < pcr->len && j < car->len) {
        if (j == -1 ||pcr->data[i] == car->data[j]){
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j == car->len) {
        printf("KMP Match success\n");
    }
    else {
        printf("KMP Match fail\n");
    }
    
}
int main(int argc, char * argv[]) {
//    String* pcr = initStr();
//
//    char car[20] = "abcadabcdgeaabcde";
//    char car1[5] = "ababc";
    String* pcr = initStr();
    String* tcr = initStr();
    assign(pcr, argv[1]);
    printStr(pcr);
    assign(tcr, argv[2]);
    printStr(tcr);
    int* next = getNext(tcr);
    printNext(next, tcr->len);
    KMPMatch(pcr, tcr, next);
    return 0;
}
