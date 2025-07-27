#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int num[50],m[50];
char sign[50];
int main()
{
int len=1;
scanf("%d",&num[1]);m[1]=num[1];
while(cin>>sign[len])
{
if(sign[len]=='=')break;
len++;
scanf("%d",&num[len]);m[len]=num[len];
}
int min=0,max=1;
for(int i=1;i<len;i++)//small
{
if(sign[i]=='*')
{
m[i+1]=m[i]*m[i+1];
m[i]=0;
}
if(sign[i]=='+')
{
num[i+1]=num[i]+num[i+1];
num[i]=1;
}
}
for(int i=1;i<=len;i++)
{
min+=m[i];
max*=num[i];
}
printf("%d\n%d\n",max,min);
return 0;
}
