#include <bits/stdc++.h>
using namespace std;
int n,k,p,pp;
void solve()
{
	cin>>n>>k;
	p=n;
	pp=0;
	if(k==0)
	{
		cout<<0<<endl;
		return;
	}
	if(k<=p)
	{
		cout<<1<<endl;
		return;
	}
	pp=1;
	for(int i=n-1;i>=1;i--)
	{
		p+=i;
		pp++;
		if(k<=p)
		{
			cout<<pp<<endl;
			return;
		}
		p+=i;
		pp++;
		if(k<=p)
		{
			cout<<pp<<endl;
			return;
		}
	}
}
int main ()
{
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}