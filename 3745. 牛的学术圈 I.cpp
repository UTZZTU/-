#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int n,l,ans,k;
map<int,int> mp;
bool check(int x)
{
	int wz=lower_bound(a+1,a+1+k,x)-a;
	wz--;
	int rs=n-b[wz];
	if(rs>=x)
	return true;
	int u=l;
	if(wz==0||a[wz]+1<x)
	return false;
	if(wz-1>=0)
	{
		int p=min(u,b[wz]-b[wz-1]);
		u-=p;
		rs+=p;
		wz--;
	}
	return rs>=x;
}
int main ()
{
	int le=100010,ri=0;
	cin>>n>>l;
		for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		mp[x]++;
		le=min(le,x);
		ri=max(ri,x);
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		ans+=it->second;
		a[++k]=it->first;
		b[k]=ans;
	}
	if(le==ri)
	{
		ri++;
	}
	while(le<ri)
	{
		int mid=(le+ri+1)/2;
		if(check(mid))
		le=mid;
		else
		ri=mid-1;
	}
	cout<<le;
	return 0;
}