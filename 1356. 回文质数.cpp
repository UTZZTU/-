#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int primes[N],cnt,a,b;
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
bool is_huiwen(int x)
{
	int t=x,tt=0;
	while(t)
	{
		tt=tt*10+t%10;
		t/=10;
	}
	return tt==x;
}
int main ()
{
	init(N-10);
	cin>>a>>b;
	int pos=lower_bound(primes,primes+cnt,a)-primes;
	if(pos>=cnt)
	return 0;
	for(pos;pos<cnt;pos++)
	{
		if(primes[pos]>b)
		break;
		if(is_huiwen(primes[pos]))
		cout<<primes[pos]<<endl;
	}
	return 0;
}