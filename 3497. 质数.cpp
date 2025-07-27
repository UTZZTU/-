#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int primes[N],cnt,k;
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
			if(i%primes[j]==0) break;
		}
	}
}
int main ()
{
	init(1e6);
	while(cin>>k)
	{
		cout<<primes[k-1]<<endl;
	}
	return 0;
}