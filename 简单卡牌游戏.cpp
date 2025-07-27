#include <bits/stdc++.h>
using namespace std;
map<int,int> mp1,mp2;
int n,a[1000100],b[1000100],minn=0x3f3f3f3f;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		mp2[a[i]]++;
		if(a[i]!=b[i])
		{
			mp1[a[i]]++;
			mp1[b[i]]++;
		}
		else
		mp1[a[i]]++;
	}
	for(auto it=mp1.begin();it!=mp1.end();it++)
	{
		if(it->second>=ceil(n*1.0/2))
		{
			minn=min(minn,int(ceil(n*1.0/2))-mp2[it->first]);
		}
	}
	if(minn==0x3f3f3f3f)
	cout<<"Impossible";
	else
	cout<<max(minn,0);
	return 0;
}