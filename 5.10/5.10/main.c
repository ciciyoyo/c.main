//
//  main.c
//  5.10
//
//  Created by Rido on 2022/5/10.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
//文件操作
    //1.什么是文件
        //程序设计中，我们一般谈文件有两种：程序文件，数据文件
        //程序文件：包括源程序文件（后缀为.c），目标文件（windows环境后缀为.obj)，可执行程序（windows环境后缀为.exe)
        //数据文件：文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件

    //2.文件名
        //一个文件要有一个唯一的文件标示，以便用户识别引用
        //文件名包含3部分：文件路径+文件名主干+文件后缀
        //例：c:/code/test.txt
    //3.文件类型
        //根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
        //数据在内存中以二进制的形式存储，如果不加转换的输出到外存，就是二进制文件
        //如果要求在外存上以ascll码的形式存储，则需要在存储前转换，以ascll字符的形式存储的文件就是文本文件
        //字符一律以ascll形式存储，数值型数据即可以用ascii形式存储也可以用二进制形式存储
        //如果有整数10000，如果以ascii码的形式输出到磁盘，则磁盘中占用5个字节（每个字符一个字节），而二进制形式输出，则在磁盘上之战4个字节（vs2013测试）
    //4.文件缓冲区
        //ANSIC 表针采用“缓冲文件系统”处理数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正在使用的文件开辟一块文件缓冲区。从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区）然后在从缓冲区逐个的将数据送到程序数据区（程序变量等）。缓冲区的大小根据c编译系统决定的
    //5.文件指针
        //缓存文件系统中，关键的概念是“文件类型指针”， 简称“文件指针”
        //每个被使用的文件都在内存中开辟了一个响应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）这些信息是保存在一个结构体变量中的。该结构体类型是由系统声明的。取名“ FILE“
        //不同的编译器的FILE类型包含的内容不完全相同，但是大同小异
        //每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量并填充其中的信息
        //一般都是通过一个FILE的指针来维护这个FILE结构的变量，这样使用起来更加方便
        //例：FIlE* fp  文件指针流
        //定义fp是一个指向FILE类型数据的指针变量，可以使fp指向某个文件的文件信息区（是一个结构体变量）通过该文件信息区中的信息就能够访问该文件。也就是说“通过文件指针变量就能找到它关联的文件”
    //6.文件的打开与关闭
        //文件在读写之前应该打开文件，在使用结束后关闭文件
        //在编写程序的时候，再打开文件的同时，都会返回一个FILE*的指针变量指向该文件，也相当于建立了指针与文件的关系
        //ANSIC 规定使用fopen函数来打开文件，fclose来关闭文件
        //例:FILE*fopen(const char*filename,const char* mode);
        //例:int fclose(FILE * stream);
//文件使用方式                含义              如果指定文件不存在
//”r“（只读）   为了输入数据打开一个已存在的文本文件     出错
//”w“（只写）   为了输出数据，打开一个文本文件（覆盖）    建立一个新文件
//“a”（追加）   向文本文件尾添加数据                  出错
//“rb”（只读）  位了输入数据，打开一个二进制文件        出错
//“wb”（只写）  位了输出数据，打开一个二进制文件        建立一个新文件
//“ab”（追加）  向一个二进制文件尾添加数据             出错
//“r+”（读写）  为了读和写，打开一个文本文件           出错
//“w+”（读写）  为了读和写，建立一个新的文件           建立一个新文件
//“a+”（读写）  打开一个文件，在文件尾进行读写         建立一个新文件
//“rb+”（读写） 为了读和写，打开一个二进制文件         出错
//“wb+”（读写） 为了读和写，建立一个新的文件           建立一个新文件
//“ab+”（读写） 打开一个二进制文件在文件尾进行读和写    建立一个新文件

    //7.文件的顺序读写
//   功能                 函数名                   适用于
//字符输入函数             fgetc                  所有输入流
//字符输出函数             fputc                  所有输出流
//文本行输入函数            fgets                  所有输入流
//文本行输出函数            fputs                  所有输出流
//格式化输入函数            fscanf                 所有输入流
//格式化输出函数            fprintf                所有输出流
//二进制输入               fread                     文件
//二进制输出               fwrite                    文件
//
//键盘&屏幕 标准输入输出设备  是一个程序默认打开的两个流设备
//只要程序运行，就会默认打开三个流：stdin、stdout、stderr（都是FILE*类型）

//键盘&屏幕流输入输出get(目标地址) put(目标地址)
//int main()
//{
//    char arr[1024]= {0};
////    char c = fgetc(stdin);//从键盘获取一个字符
////    fgets(arr, 1024, stdin);//从键盘上获取字符串
////    fputc(arr, stdout);//从屏幕上输出
////    fputs(arr, stdout);
//
//    gets(arr);//从键盘上获取字符串
//    puts(arr);//从屏幕上输出
//    return 0;
//}

//写入文件fputs(字符串, 流)fputc(字符, 流)
//int main(int argc, const char * argv[]) {
//    //打开文件
//    FILE* fwrite =fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt", "w");//打开失败返回NULL指针
//    if (fwrite == NULL) {
//        printf("%s\n", strerror(errno));
//        return 0;
//    }
//    fputc('6', fwrite);//写入一个字符
//    //写入字符串
//    fputs("rido\nhello\n666", fwrite);//fputs(指定字符串, 指定流)
//   //关闭文件
//    fclose(fwrite);
//    fwrite = NULL;
////    system("pwd\n");//查看代码路径
//    return 0;
//}

//读取文件fgets(字符串, 流)fgetc(字符,流)
//int main()
//{
//    FILE* fread = fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt", "r");
//    if (fread ==NULL) {
//        printf("%s", strerror(errno));
//        return 0;
//    }
////    printf("%c", fgetc(fread));//读取一个字符
//    char arr[1024];
//    //读取一行字符串放到指定位置
//    fgets(arr, 1024, fread);//fgets(放到哪, 几个, 从哪)
//    printf("%s", arr);
////    puts(arr);//写一个字符串到标准输出上（读取一行到屏幕）
//    fgets(arr, 1024, fread);
//    printf("%s", arr);
////    puts(arr);//打印完会自动换行
//    fclose(fread);//关闭文件
//    fread = NULL;
//    return 0;
//}

//格式化写入文件fprintf（流，剩下的根printf一样）（可以写所有类型的数据）
//typedef struct Stu
//{
//    char name[20];
//    int age;
//    float fen;
//
//}Stu;
//int main()
//{
//    FILE* fp =  fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt", "w");
//    if (fp == NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    Stu s1 = {"rido", 32, 99.99f};
//    fprintf(fp,"%s %d %lf",s1.name, s1.age,s1.fen );//printf是输出到标准流中
//    fclose(fp);
//    fp = NULL;
//    return 0;
//}

//格式化读取文件fscanf(流，剩下的根scanf一样)(按照某一种格式）
//int main()
//{
//    FILE * pf = fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt","r");
//    if (pf== NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    Stu s2 = {0};
//    Stu *sp = &s2;
//    fscanf(pf, "%s %d %f",sp->name, &(sp->age), &(sp->fen));
//    printf("%s,%d,%.2f", sp->name,sp->age,sp->fen);
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//对比一组函数
//scanf/fscanf/sscanf
//printf/fprintf/sprinf
//printf/scanf :是针对标准输入输出流格式化输入输出语句
//fscanf/fprintf :是针对所有输入输出流的格式化输入输出语句
//sscanf/sprintf :sscanf是从字符串中读取格式化的数据
//               :sprintf是把格式化的数据输出成字符串（存储到字符串中）
//
//案例：sprintf(目标地址, 剩下的根printf一样)sscanf()
//typedef struct Stu
//{
//    char name[20];
//    int age;
//    float score;
//}Stu;
//int main()
//{
//    Stu s1 = {"rido", 32, 88.88f};
//    Stu s2 = {0};
//    char arr[50];
//    sprintf(arr, "%s, %d, %f",s1.name,s1.age,s1.score);
//    printf("%s\n", arr);
//    sscanf(arr, "%s %d %f", s2.name, &(s2.age), &(s2.score));
//    printf("%s\n%d\n%f", s2.name,s2.age,s2.score);
//    return 0;
//}

//二进制读写fread(目标地址,文件大小,几个,文件指针) fwrite()
//typedef struct Stu /
//二进制写入
//int main()
//{
//   FILE* fp =  fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt", "wb");
//    Stu s1 = {"李冬", 32, 88.88};
//    if(fp ==NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    fwrite(&s1, sizeof(Stu), 1, fp);
//    fclose(fp);
//    fp = NULL;
//    return 0;
//}
//二进制读取
//int main()
//{
//    FILE* fp =  fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt", "rb");
//    Stu s2 = {0};
//    if(fp ==NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//   fread(&s2, sizeof(Stu), 1, fp);
//    printf("%s, %d, %f", s2.name,s2.age, s2.score);
//    fclose(fp);
//    fp = NULL;
//    return 0;
//}

    //8.文件的随机读取
//    fseek(文件指针, 偏移量,文件指针的当前位置,)
//    ftell(文件指针) 返回文件指针相对于起始位置的偏移量
//    rewind(文件指针)  让文件指针的位置回到文件的起始位置
//根据文件指针的位置和偏移量来定位文件指针。
//int main()
//{
//    FILE* fp = fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt", "r");
//    if (fp == NULL)
//    {
//        printf("%s", strerror(errno));
//    }
//    fseek(fp, 2, SEEK_CUR);
//    printf("%c\n",fgetc(fp));
//    printf("%c\n",fgetc(fp));
//    long a = ftell(fp);//读取一次之后文件指针就会变化
//    printf("%lu\n", a);
//    rewind(fp);//使文件指针回到起始位置
//    printf("%c\n",fgetc(fp));
//    fclose(fp);
//    fp = NULL;
//    return 0;
//}

//文件结束的判定
    //feof()  文件结束判定（判断文件结束的原因）
    //ferror()  测试给定流的错误标识符
    //牢记：在文件读取过程中，不能用feof函数的返回值直接判断文件是否结束。而是应用于当文件读取结束的时候，判断读取失败结束，还是遇到文件尾结束
        //例
        //1.文本文件读取是否结束，判断返回值是否为EOF (fgetc),或者NULL（fgets）
            
            //。fgetc判断是否为EOF
            //。fgets判断返回值是否为NULL
        //2.二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
            //。fread判断返回值是否小于实际要读的个数
int main()
{
    FILE* pf =  fopen("/Users/lidong/Desktop/demo/5.10/5.10/test.txt", "r");
    if (pf == NULL)
    {
        perror("打开文件出错");//会打印输入的字符串和错误信息
        return 0;
    }
//    printf("%d", fgetc(pf));返回EOF(end of file)文件结束标示-1
    int c;
    while((c=fgetc(pf)) != EOF)
    {
        putchar(c);
    }
    if (feof(pf))//如果是以EOF结束返回非0数字
    {
        printf("文件结束");
    }
    else if (ferror(pf))
    {
        printf("文件读取错误");
    }
    //ferror，函数名，在调用各种输入输出函数（如 putc.getc.fread.fwrite等）时，如果出现错误，除了函数返回值有所反映外，还可以用ferror函数检查。 它的一般调用形式为 ferror(fp)；如果ferror返回值为0（假），表示未出错。如果返回一个非零值，表示出错。应该注意，对同一个文件 每一次调用输入输出函数，均产生一个新的ferror函 数值，因此，应当在调用一个输入输出函数后立即检 查ferror函数的值，否则信息会丢失。在执行fopen函数时，ferror函数的初始值自动置为0。
    fclose(pf);
    pf = NULL;
    return 0;
}
