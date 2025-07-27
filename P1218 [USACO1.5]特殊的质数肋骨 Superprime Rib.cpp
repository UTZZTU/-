#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+10;
int primes[N],cnt,n,a[4]={2,3,5,7};
bool st[N];
void init(int x)
{
	st[0]=true;
	st[1]=true;
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
void dfs(int level,int sum)
{
	if(level>n)
	{
		if(!st[sum])
		cout<<sum<<endl;
		return;
	}
	if(level==1)
	{
		for(int i=0;i<4;i++)
		{
			sum=sum*10+a[i];
			if(!st[sum])
			dfs(level+1,sum);
			sum/=10;
		}
	}
	else
	{
		for(int i=1;i<=9;i++)
		{
			sum=sum*10+i;
			if(!st[sum])
			dfs(level+1,sum);
			sum/=10;
		}
	}
}
int main ()
{
	cin>>n;
	init(pow(10,n));
	dfs(1,0);
	return 0;
}