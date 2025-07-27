#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;
int vis[100000000];
int n,flag;
long long a[100005];
char s[400];
int chang(char x)
{
    if (x>='0'&&x<='9') 
    {
        int tmp=x-'0';
        return tmp;
    }
    if (x>='A'&&x<='C') return 2;
    if (x>='D'&&x<='F') return 3;
    if (x>='G'&&x<='I') return 4;
    if (x>='J'&&x<='L') return 5;
    if (x>='M'&&x<='O') return 6;
    if (x>='P'&&x<='S') return 7;
    if (x>='T'&&x<='V') return 8;
    if (x>='W'&&x<='Y') return 9;
}
int main()
{
    scanf("%d",&n);flag=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        long long tmp=0;
        for (int j=0;s[j];j++)//居然有这种操作吗！
        if (s[j]=='-') continue;
        else tmp=tmp*10+chang(s[j]);
        vis[tmp]++;a[i]=tmp;
        if (vis[tmp]>=2) flag=1;
    }
    if (!flag) 
    {
        printf("No duplicates.\n");
        return 0; 
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
    if (vis[a[i]]>=2)
    {
        int kk=1000000;int ans=a[i];
        for (int j=1;j<=7;j++)
        {
            int tmp=ans/kk;ans%=kk;kk/=10;
            printf("%d",tmp);
            if (j==3) printf("-");
        }
        printf(" %d\n",vis[a[i]]);
        vis[a[i]]=0;
    }
}