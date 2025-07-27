#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+10;
int primes[N],cnt,a[1010],n,k,sum,ft;
bool st[N];
void init(int x)
{
	st[1]=true;
	st[0]=true;
	for(int i=2;i<=x;i++)
	{
		if(!st[i]) primes[cnt++]=i;
		for(int j=0;primes[j]*i<=x;j++)
		{
			st[primes[j]*i]=true;
			if(i%primes[j]==0)
			break;
		}
	}
}
void dfs(int level,int sum,int pos)
{
	if(pos>=k)
	{
		if(!st[sum])
		ft++;
		return;
	}
	if(level==n)
	return;
	dfs(level+1,sum+a[level+1],pos+1);
	dfs(level+1,sum,pos);
}
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	init(sum+1);
	dfs(0,0,0);
	cout<<ft;
	return 0;
}