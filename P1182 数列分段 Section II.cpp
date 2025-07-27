#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100010],l=0,r=0,mid,ans=0;
bool check(int x)
{
	int i=0,j=1;
	for(int k=1;k<=n;k++)
	{
		if(i+a[k]>x)
		{
			i=0;
			j++;
		}
		i+=a[k];
	}
	return j<=m;
}
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l=max(l,a[i]);
		r+=a[i];
	}
	while(r>=l)
	{
		mid=(r+l)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		l=mid+1;
	}
	printf("%d",ans);
	return 0;
}