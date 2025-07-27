#include <bits/stdc++.h>
using namespace std;
set<int> p;
int f[1010],n,ans;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		p.insert(f[i]);
	}
	for(auto it=p.begin();it!=p.end();it++)
	{
		int js=0,sc=-1;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==*it)
			continue;
			if(sc==-1)
			{
			sc=f[i];
			js++;
			}
			else
			{
				if(f[i]!=sc)
				{
					ans=max(ans,js);
					js=1;
					sc=f[i];
				}
				else
				{
					js++;
				}
			}
		}
		ans=max(ans,js);
	}
	cout<<ans;
	return 0;
}