#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int primes[N],cnt,f[N],t,n,k;
bool st[N];
void init(int x)
{
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
int main ()
{
	init(1000);
	for(int i=1;i<cnt;i++)
	{
		if(!st[primes[i]+1+primes[i-1]])
		f[primes[i]+1+primes[i-1]]=1;
	}
	for(int i=3;i<=1000;i++)
	{
		f[i]+=f[i-1];
	}
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(f[n]>=k)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}