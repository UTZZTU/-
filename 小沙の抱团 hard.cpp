#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b[510],x[510],f[100010],minn,num;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=100000;i++)
	{
		f[i]=1000000000000000;
	}
	f[n]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i]>>x[i];
	}
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=n;j>x[i];j--)
//		{
//			f[j-j%x[i]]=min(f[j-j%x[i]],f[j]+b[i]);
//		}
//	}
	for(int j=n;j>=1;j--)
	{
		for(int i=1;i<=m;i++)
		{
			if(j<=x[i])
			continue;
			f[j-j%x[i]]=min(f[j-j%x[i]],f[j]+b[i]);
		}
	}
	num=0;
	for(int i=n-1;i>=1;i--)
	{
		if(f[i]!=1000000000000000)
		num=f[i];
	}
	cout<<num;
	return 0;
}