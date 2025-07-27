#include <bits/stdc++.h>
using namespace std;
int primes[1000010],cnt,n,m,l,r,f[1000010];
bool st[1000010];
void init(int x)
{
	st[0]=st[1]=true;
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
	cin>>n>>m;
	init(m);
	for(int i=1;i<=m;i++)
	f[i]=f[i-1]+!st[i];
	while(n--)
	{
		cin>>l>>r;
		if(l>=1&&l<=r&&r<=m)
		cout<<f[r]-f[l-1]<<endl;
		else
		cout<<"Crossing the line"<<endl;
	}
	return 0;
}