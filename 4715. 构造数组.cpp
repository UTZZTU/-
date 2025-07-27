#include <bits/stdc++.h>
using namespace std;
string u;
int n,a[1010],minn=0x3f3f3f3f;
int main ()
{
	cin>>n>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]=='>')
		a[i]=-1;
		else if(u[i]=='=')
		a[i]=0;
		else if(u[i]=='<')
		a[i]=1;
	}
	int ks=1;
	for(int i=0;i<n-1;i++)
	{
		ks+=a[i];
		minn=min(minn,ks);
	}
	if(minn<=0)
	{
		ks=1+(1-minn);
	}
	else
	ks=1;
	cout<<ks;
	for(int i=0;i<n-1;i++)
	{
		ks+=a[i];
		cout<<" "<<ks;
	}
	return 0;
}