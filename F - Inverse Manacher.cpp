#include <bits/stdc++.h>
using namespace std;
int n,f[2000010],pre[2000010];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n+2;i++)
	{
		scanf("%d",&f[i]);
	}
	if(n&1)
	{
		pre[3]=1;
		for(int i=5;i<=2*n+2;i+=4)
		{
			if(f[i]>=3) pre[i+2]=pre[i-2];
			else
			{
				if(pre[i-2]==1) pre[i+2]=2;
				else pre[i+2]=1;
			}
		}
		for(int i=2*n;i>=3;i-=4)
		{
			if(f[i]>=2) pre[i-1]=pre[i+1];
			else
			{
				if(pre[i+1]==1) pre[i-1]=2;
				else pre[i-1]=1;
			}
		}
	}
	else
	{
		pre[5]=1;
		for(int i=7;i<=2*n+2;i+=4)
		{
			if(f[i]>=3) pre[i+2]=pre[i-2];
			else
			{
				if(pre[i-2]==1) pre[i+2]=2;
				else pre[i+2]=1;
			}
		}
		for(int i=2*n;i>=3;i-=4)
		{
			if(f[i]>=2) pre[i-1]=pre[i+1];
			else
			{
				if(pre[i+1]==1) pre[i-1]=2;
				else pre[i-1]=1;
			}
		}
	}
	string u;
	for(int i=3;i<=2*n+2;i+=2)
	{
		if(pre[i]==1) u+='a';
		else u+='b';
	}
	cout<<u;
	return 0;
}