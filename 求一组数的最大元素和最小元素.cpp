#include <bits/stdc++.h>
using namespace std;
int n,f[1010];
int minn(int left, int right)
{
	if(left==right)
	{
		return f[left];
	}
	else if(right==left+1)
	{
		return min(f[left],f[right]);
	}
	else
	{
		int mid=(left+right)/2;
		int le=minn(left,mid),ri=minn(mid+1,right);
		return min(le,ri);
	}
}
int maxx(int left, int right)
{
	if(left==right)
	{
		return f[left];
	}
	else if(right==left+1)
	{
		return max(f[left],f[right]);
	}
	else
	{
		int mid=(left+right)/2;
		int le=maxx(left,mid),ri=maxx(mid+1,right);
		return max(le,ri);
	}
}
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
	cout<<minn(1,n)<<" "<<maxx(1,n);
	return 0;
}