#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],minn,l,r;
unordered_map<int,int> mp;
struct node
{
	int x,s;
}s[100010][2];
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	if(n==1||m>=n-1)
	{
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	minn=a[n]-a[1];
	for(int i=1;i<=m;i++)
	{
		if(i==1)
		{
			l=mp[a[1]],r=mp[a[n]];
			if()
		}
		else
		{
			
		}
	}
	cout<<max(minn,0);
	return 0;
}