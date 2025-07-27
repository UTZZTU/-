#include <bits/stdc++.h>
using namespace std;
int n,res1,res2;
string u,v;
void solve()
{
	cin>>n;
	res1=res2=0;
	cin>>u>>v;
	for(int i=0;i<n;i++)
	{
		if(u[i]=='1') res1++;
		if(v[i]=='1') res2++;
	}
	if(res1==res2)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(u[i]=='1'&&v[i]=='1') sum++;
		}
		cout<<res2-sum<<endl;
	}
	else if(res1>res2)
	{
		int sum=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(u[i]=='1'&&v[i]=='1') sum++;
			else if(u[i]=='1'&&v[i]=='0') cnt++;
		}
		cout<<cnt<<endl;
	}
	else if(res1<res2)
	{
		int sum=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(u[i]=='1'&&v[i]=='1') sum++;
			else if(u[i]=='1'&&v[i]=='0') cnt++;
		}
		cout<<cnt+(res2-res1)<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}