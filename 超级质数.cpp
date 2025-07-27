#include <bits/stdc++.h>
using namespace std;
int f[5]={0,2,3,5,7},maxx,primes[100010],cnt;
bool st[100010];
void init(int x)
{
	st[1]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}
	}
}
bool judge(int x,int pos)
{
	string u=to_string(x);
	int k=2;
	while(k<=pos)
	{
		for(int i=0;i<u.size();i++)
		{
			int res=0;
			for(int j=i;j<=i+k-1&&j<u.size();j++)
			{
				res=res*10+(u[j]-'0');
			}
			if(st[res]) return false;
		}
		k++;
	}
	return true;
}
void dfs(int x,int pos)
{
	maxx=max(maxx,x);
	for(int i=1;i<=4;i++)
	{
		int ans=x*10+f[i];
		if(judge(ans,pos+1))
		{
			dfs(ans,pos+1);
		}
	}
}
int main ()
{
	init(100000);
	dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);
	cout<<maxx;
	return 0;
}