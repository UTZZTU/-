#include <bits/stdc++.h>
using namespace std;
int n,cnt;
map<string,int> mp;
string u,a[1010];
int main ()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>u;
		if(!mp.count(u))
		{
			a[++cnt]=u;
			mp[u]=1;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(i!=1)
		cout<<endl;
		cout<<a[i];
	}
	return 0;
}