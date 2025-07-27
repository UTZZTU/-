#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 110
using namespace std;
int n,m,a[N],f[10010];
int main()
{
   //freopen(".in","r",stdin);
   //freopen(".out","w",stdout);
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
     scanf("%d",&a[i]);
   f[0]=1;
   for(int i=1;i<=n;i++)
     for(int j=m;j>=a[i];j--)
     	  f[j]=f[j]+f[j-a[i]];
   cout<<f[m];
   return 0;
}

