#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,b,maxx,res,x,y,minn;
ll get_num(ll t1,ll t2)
{
	ll sum=0,tnum=0;
	ll p1=t1,p2=t2;
//	minn=min(p1/2,p2);
//	sum+=minn*a;
//	p1-=2*minn,p2-=minn;
//	minn=min(p1,p2/2);
//	sum+=minn*b;
//	tnum=max(tnum,sum);
	
	sum=0;
	p1=t1,p2=t2;
	minn=min(p1,p2/2);
	sum+=minn*b;
	p1-=minn,p2-=2*minn;
	minn=min(p1/2,p2);
	sum+=minn*a;
	tnum=max(tnum,sum);
	return tnum;
}
ll get_num2(ll t1,ll t2)
{
	ll sum=0,tnum=0;
	ll p1=t1,p2=t2;
	minn=min(p1/2,p2);
	sum+=minn*a;
	p1-=2*minn,p2-=minn;
	minn=min(p1,p2/2);
	sum+=minn*b;
	tnum=max(tnum,sum);
	
//	sum=0;
//	p1=t1,p2=t2;
//	minn=min(p1,p2/2);
//	sum+=minn*b;
//	p1-=minn,p2-=2*minn;
//	minn=min(p1/2,p2);
//	sum+=minn*a;
//	tnum=max(tnum,sum);
	return tnum;
}
int main ()
{
	cin>>n>>m>>a>>b;
//	x=n,y=m;
//	minn=min(x/2,y);
//	res+=minn*a;
//	x-=2*minn,y-=minn;
//	minn=min(x,y/2);
//	res+=minn*b;
//	maxx=max(maxx,res);
//	
//	x=n,y=m,res=0;
//	minn=min(x,y/2);
//	res+=minn*b;
//	x-=minn,y-=2*minn;
//	minn=min(x/2,y);
//	res+=minn*a;
//	maxx=max(maxx,res);
//	
//	x=n,y=m,res=0;
//	minn=min(x/3,y/3);
//	res+=minn*(a+b);
//	x-=3*minn,y-=3*minn;
//	res+=get_num(x,y);
//	maxx=max(maxx,res);
	for(int i=1;i<=1000000;i++)
	{
		if(2*i>n||i>m) break;
		ll pos=a*i+get_num(n-2*i,m-i);
		maxx=max(maxx,pos);
	}
	for(int i=1;i<=1000000;i++)
	{
		if(i>n||2*i>m) break;
		ll pos=b*i+get_num2(n-i,m-2*i);
		maxx=max(maxx,pos);
	}
	cout<<maxx;
	return 0;
}