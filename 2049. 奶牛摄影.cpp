#include <bits/stdc++.h>
using namespace std;
int f[10][20010],ans,a[20010],n;
bool cmp(int x,int y)
{
	ans=0;
	for(int i=1;i<=5;i++)
	ans+=f[i][x]<f[i][y];
	return ans>2;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=5;i++)
	{
		for(int j=1,x;j<=n;j++)
		{
			scanf("%d",&x);
			f[i][x]=j;
		}
	}
	for(int i=1;i<=n;i++)
	a[i]=i;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	cout<<a[i]<<endl;
	return 0;
}