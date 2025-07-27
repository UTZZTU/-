#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int maxx=0,minn=0x3f3f3f3f,primes[1010],cnt;
bool st[1010];
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
int main ()
{
	init(1000);
	string u;
	cin>>u;
	for(int i=0;i<u.size();i++)
	mp[u[i]]++;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		maxx=max(maxx,it->second);
		minn=min(minn,it->second);
	}
	if(!st[maxx-minn])
	cout<<"Lucky Word"<<endl<<maxx-minn;
	else
	cout<<"No Answer"<<endl<<0;
	return 0;
}