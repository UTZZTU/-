#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,k,n,cz;
string u,v;
bool check(string a)
{
	sum=0;
	cz=0;
	k=1;
	for(int i=a.size()-1;i>=0;i--)
	{
		sum+=k*(a[i]-'0');
		k*=2;
	}
	n=sum;
	string b;
	while(n)
	{
		b+=n%3+'0';
		n/=3;
	}
	reverse(b.begin(),b.end());
	if(b.size()!=v.size())
	return false;
	for(int i=0;i<b.size();i++)
	{
		if(b[i]!=v[i])
		cz++;
		if(cz>1)
		return false;
	}
	return true;
}
int main ()
{
	cin>>u>>v;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='0')
		{
			u[i]='1';
			if(check(u))
			{
				cout<<sum;
				return 0;
			}
			u[i]='0';
		}
		else
		{
			u[i]='0';
			if(check(u))
			{
				cout<<sum;
				return 0;
			}
			u[i]='1';
		}
	}
	return 0;
}