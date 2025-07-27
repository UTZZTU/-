#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll a,ll b)
{
	int c,x,y;
	x=max(a,b);
	y=min(a,b);
	while(y)
	{
		c=x%y;
		x=y;
		y=c;
	}
	return x;
}
int main ()
{
	ll n,fz1,fm1,fz2=0,fm2=1,zsbf;
	cin>>n;
	scanf("%lld/%lld",&fz1,&fm1);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld/%lld",&fz2,&fm2);
		ll maxx=fm2*fm1/fun(fm2,fm1);
		fz1=maxx/fm1*fz1+maxx/fm2*fz2;
		fm1=maxx;
		if(fz1!=0)
		{
			maxx=fun(fz1,fm1);
		fz1/=maxx;
		fm1/=maxx;
		}
	}
	zsbf=fz1/fm1;
	fz1%=fm1;
	if(fz1!=0)
	{
		ll maxx=fun(fz1,fm1);
	fz1/=maxx;
	fm1/=maxx;
	}
	if(zsbf!=0)
	cout<<zsbf;
	if(fz1==0&&zsbf==0)
	cout<<0;
	else if(fz1!=0)
	{
		if(zsbf!=0)
		cout<<" "<<fz1<<"/"<<fm1;
		else
		cout<<fz1<<"/"<<fm1;
	}
	return 0;
}