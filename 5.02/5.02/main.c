//
//  main.c
//  5.02
//
//  Created by Rido on 2022/5/2.
//

#include <stdio.h>
struct S
{
    int a;
    char c;
    double;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    struct S s1 = {0};
    struct S s2 = {4, 'r',3.14};
    s1 = s2;
    printf("%d", s1.a);
    return 0;
}
