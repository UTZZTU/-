#include <iostream>
using namespace std;
int a[105][1005],f[105][1005];
int main()
{
  // 请在此输入您的代码
int n,m,k,q1,b,i,j;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
  for(int j=1;j<=m;j++)
  {
    cin>>k;
    a[i][j]=k;
  }
}
f[1][1]=a[1][1];
for(j=2;j<=m;j++)
{
  if(j-3>=1)
  {
  	f[1][j]=max(f[1][j-1],f[1][j-2]);
  	f[1][j]=max(f[1][j],f[1][j-3]);
  }
  else if(j-2>=1)
  {
  	f[1][j]=max(f[1][j-1],f[1][j-2]);
  }
  else if(j-1>=1)
  {
  	f[1][j]=f[1][j-1];
  }
  f[1][j]+=a[1][j];
}
for(i=2;i<=n;i++)
{
  if(i-3>=1)
  {
  	f[i][1]=max(f[i-1][1],f[i-2][1]);
  	f[i][1]=max(f[i][1],f[i-3][1]);
  }
  else if(i-2>=1)
  {
  	f[i][1]=max(f[i-1][1],f[i-2][1]);
  }
  else if(i-1>=1)
  {
  	f[i][1]=f[i-1][1];
  }
  f[i][1]+=a[i][1];
}
for(i=2;i<=n;i++)
{
  for(j=2;j<=m;j++)
  {
    q1=max(f[i-1][j],f[i][j-1]);
    b=max(q1,f[i-1][j-1]);
    f[i][j]=b;
    if(i-2>=1&&j-1>=1)
    {
      f[i][j]=max(f[i][j],f[i-2][j-1]);
      f[i][j]=max(f[i][j],f[i-2][j]);
    }
    if(j-2>=1&&i-1>=1)
    {
      f[i][j]=max(f[i][j],f[i-1][j-2]);
      f[i][j]=max(f[i][j],f[i][j-2]);
    }
    if(i-3>=1)
    f[i][j]=max(f[i][j],f[i-3][j]);
    if(j-3>=1)
    f[i][j]=max(f[i][j],f[i][j-3]);
    f[i][j]+=a[i][j];
  }
}
cout<<f[n][m];
  return 0;
}