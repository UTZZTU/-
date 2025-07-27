#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7+10;
ll q,primes[N],cnt,tt;
int main ()
{
	cin>>q;
	tt=q;
	for(ll i=2;i*i<=q;i++)
	{
		if(tt%i==0)
		{
			while(tt%i==0)
			{
				tt/=i;
				primes[cnt++]=i;
			} 
		}
	}
	if(tt>1)
	primes[cnt++]=tt;
	if(cnt==1)
	cout<<1<<endl<<0;
	else if(cnt==2)
	cout<<2;
	else
	cout<<1<<endl<<primes[0]*primes[1];
	return 0;
}