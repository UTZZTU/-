#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int ans;
int main ()
{
	int n;
	cin>>n;
	for(int i=1,x,y;i<=n;i++)
	{
		cin>>x>>y;
		if(!mp.count(x))
		mp[x]=y;
		else
		{
			if(mp[x]!=y)
			ans++;
			mp[x]=y;
		}
	}
	cout<<ans;
	return 0;
}