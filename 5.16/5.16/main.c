//
//  main.c
//  5.16
//
//  Created by Rido on 2022/5/16.
//

#include <stdio.h>

int Serch(int* arr , int targe,int sz )
{
    int left = 0;
    int rigt = sz-1;
    while(left <= rigt)
    {
        int avg = (rigt + left)/2;
        if (targe > arr[avg])
            left = avg+1;
        else if (targe < arr[avg])
            rigt = avg-1;
        else
            return avg;
    }
    return -1;
}
int main (){
    int arr[] = {-1,0,3,5,9,12};
    int targe = 9;
    int sz = sizeof(arr)/sizeof(arr[0]);
    int ret = Serch(arr, targe,sz);
    printf("%d", ret);
    return 0;
}

//int get_er(int* a, int x, int l)
//{
//    int left = 0;
//    int right = l/sizeof(a[0])-1;
//    while(left<right)
//    {
//        int mid = (left +right)/2;
//        if(a[mid]<x)
//            left = mid+1;
//        else if(a[mid]>x)
//            right = mid-1;
//        else
//            return mid;
//    }
//    return -1;
//}
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int num;
//    int length = sizeof(arr);
//    printf("请输入1-10之间的数字");
//    scanf("%d", &num);
//    int ret = get_er(arr, num, length);
//    if(ret == -1)
//        printf("没有找到你输入的数字");
//    else
//        printf("你输入的数字在%d下标的位置", ret);
//    printf("结果是%d",ret);
//    return 0;
//}

//冒泡排序把大的放到后面
//int main()
//{
//    int arr[] = {11,3, 5, 6, 2, 4,10 ,9,7, 8};
//    int i;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    for (i = 0; i < sz-1; i++)
//    {
//        int j;
//        for (j = 0; j < sz-i-1; j++)
//        {
//            if (arr[j] > arr[j+1])
//            {
//                arr[j] = arr[j] ^ arr[j+1];
//                arr[j+1] = arr[j] ^ arr[j+1];
//                arr[j] = arr[j] ^ arr[j+1];
//            }
//        }
//    }
//    for (i = 0; i < sz; i++)
//    {
//        printf("%d\n", arr[i]);
//    }
//    return 0;
//}
