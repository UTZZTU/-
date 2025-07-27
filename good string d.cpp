#include<iostream>
#include<cstdio>
using namespace std;
char c[202000];
int main()
{
    int n,x,i,sum=0;
    scanf("%d",&n);
    scanf("%s",c+1);
    for(i=n;i>1;)
    {
        if(c[i]==c[i-1])
        c[i]='0',i=i-1,sum++;//相同使c[i]为'0',sum++，记录删除的次数；
        else
        i=i-2;//如果不同的话，i直接减两个单位；
    }
    if((n-sum)%2==0)//n-sum为剩下的字符串长度，判断是否为偶数
    {
        printf("%d\n",sum);
        for(i=1;i<=n;i++)
        if(c[i]!='0')
        printf("%c",c[i]);
    }
    else//如果不为偶数，就删除第一个字符，从第二个字符开始输出
    {
        printf("%d\n",sum+1);
        for(i=2;i<=n;i++)
        if(c[i]!='0')
        printf("%c",c[i]);
    }
    return 0;
}
