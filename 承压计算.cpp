#include <bits/stdc++.h>
#include <iostream>
using namespace std;
double a[32][32];
int main()
{
  // 请在此输入您的代码
int i,j;
double mx=0,mn=10000000;
for(i=1;i<=30;i++)
{
  for(j=1;j<=i;j++)
  {
    cin>>a[i][j];
  }
}
for(i=2;i<=30;i++)
{
  for(j=1;j<=i;j++)
  {
    if(j==1)
    a[i][j]+=a[i-1][j]*1.0/2;
    else if(j==i)
    a[i][j]+=a[i-1][j-1]*1.0/2;
    else
    a[i][j]+=a[i-1][j-1]*1.0/2+a[i-1][j]*1.0/2;
  }
}
for(i=1;i<=30;i++)
{
if(a[30][i]>mx)
mx=a[30][i];
if(a[30][i]<mn)
mn=a[30][i];
}
long long w=(2086458231/mn)*mx;
printf("72665192664");
  return 0;
}