#include <bits/stdc++.h>
using namespace std;
int l,n,m,a[50010],ans;
bool check(int s)
{
	int tot=0,i=0,now=0;
	while(i<n+1)
	{
		i++;
		if(a[i]-a[now]<s)
		tot++;
		else
		now=i;
	}
	return tot<=m;
}
int main ()
{
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	a[n+1]=l;
	int le=1,ri=l,mid;
	while(ri>=le)
	{
		mid=(ri+le)/2;
		if(check(mid))
		{
			ans=mid;
			le=mid+1;
		}
		else
		ri=mid-1;
	}
	cout<<ans;
	return 0;
}