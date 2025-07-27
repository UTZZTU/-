#include <bits/stdc++.h>
using namespace std;
int primes[10010],cnt,n;
bool st[10010];
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
	init(10000);
	cin>>n;
	for(int i=1;i<=(n-2)/2;i++)
	{
		cout<<(2*i+2)<<"=";
		for(int j=2;j<=2*i+2;j++)
		{
			if(!st[j]&&!st[2*i+2-j])
			{
				cout<<j<<"+"<<(2*i+2-j)<<endl;
				break;
			}
		}
	}
	return 0;
}