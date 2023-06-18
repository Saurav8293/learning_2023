#include<stdio.h>
int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    int big_num=(num1>num2)?num1:num2;
    printf("%d is the biggest number",big_num);
    return 0;
}