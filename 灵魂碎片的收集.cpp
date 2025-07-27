#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,x,primes[1000010],cnt,flag;
bool st[1000010];
void init(int x)
{
	st[1]=st[0]=true;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init(1000000);
	cin>>t;
	while(t--)
	{
		flag=0;
		cin>>x;
		if(x&1)
		{
			if(x==3)
			cout<<4<<endl;
			else if(x==1)
			cout<<2<<endl;
			else if(x==7)
			cout<<8<<endl;
			else
			{
				for(int i=0;i<cnt&&primes[i]<=x-1;i++)
				{
					if(!st[x-1-primes[i]]&&primes[i]*2!=x-1&&(ll)primes[i]*(x-1-primes[i])<=1e12)
					{
						cout<<(ll)primes[i]*(x-1-primes[i])<<endl;
						flag=1;
						break;
					}
				}
				if(!flag)
				cout<<-1<<endl;
			}
		}
		else
		{
			if(!st[x-1])
			cout<<(ll)(x-1)*(x-1)<<endl;
			else
			cout<<(x-3)*2<<endl;
		}
	}
	return 0;
}