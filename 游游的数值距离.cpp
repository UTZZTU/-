#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,fact[100],pos1,pos2,minn,res;
int main ()
{
	fact[1]=1;
	for(ll i=2;i<=15;i++)
	{
		fact[i]=fact[i-1]*i;
	}
	cin>>n;
	minn=n;
//	for(ll i=1;i<=13;i++)
//	{
//		if(i==2) continue;
//		if(fact[i]<=n)
//		{
//			for(ll j=1;j<=1000000;j++)
//			{
//				if(j==2) continue;
//				ll num=(ll)abs(fact[i]*j-j-n);
//				if(num<minn)
//				{
//					minn=num;
//					x=i,y=j;
//					res=1;
//				}
//				else if(num==minn)
//				{
//					res++;
//				}
//			}
//		}
//		else
//		{
//			for(ll j=1;j<=1000000;j++)
//			{
//				if(j==2) continue;
//				ll num=(ll)abs(fact[i]*j-j-n);
//				if(num<minn)
//				{
//					minn=num;
//					x=i,y=j;
//				}
//			}
//		}
//	}
//	cout<<x<<" "<<y<<" "<<minn;
	if(n==1)
	{
		cout<<"1 1";
		return 0;
	}
	else if(n==2)
	{
		cout<<"1 1";
		return 0;
	}
	for(ll i=3;i<=15;i++)
	{
		for(ll ys=0;ys<minn;ys++)
		{
			if((ys+n)%(fact[i]-1)==0&&(ys+n)/(fact[i]-1)!=2)
			{
				minn=ys;
				x=i,y=(ys+n)/(fact[i]-1);
			}
			else if((-ys+n)%(fact[i]-1)==0&&(-ys+n)/(fact[i]-1)!=2)
			{
				minn=ys;
				x=i,y=(-ys+n)/(fact[i]-1);
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}