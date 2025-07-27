#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int sum;//sum用来记录字符数
char s;
int main()
{
    while(scanf("%c",&s)!=EOF)//循环输入
        if(s!=' '&&s!='\n')//判断是否是有效字符
            sum++;
    printf("%d",sum);//输出统计结果
    return 0;
}