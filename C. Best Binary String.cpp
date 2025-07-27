#include <bits/stdc++.h>
using namespace std;
string u;
void solve()
{
	cin>>u;
	for(int i=0;i<u.size();i++)
	{
		if(u[i]!='?')
		{
			int j=i-1;
			for(j;j>=0;j--)
			{
				if(u[j]=='?') u[j]=u[i];
				else break;
			}
			j=i+1;
			for(j;j<u.size();j++)
			{
				if(u[j]=='?') u[j]=u[i];
				else break;
			}
		}
	}
	if(u[0]=='?')
	{
		for(int i=0;i<u.size();i++) cout<<0;
		cout<<endl;
	}
	else cout<<u<<endl;
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