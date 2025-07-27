#include <bits/stdc++.h>
using namespace std;
int n,m;
int l=0,r=0,mid,h[1000010];
inline bool check(double mid)
{
	int i=upper_bound(h+1,h+1+n,mid)-h;
	double tot=0;
	for(int j=i;j<=n;j++)
	tot+=h[j]-mid;
	return tot>=m;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		r=max(r,h[i]);
	}
	sort(h+1,h+1+n);
	while(r-l>0)
	{
		mid=ceil((r+l)*1.0/2);
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	printf("%d",l);
	return 0;
}