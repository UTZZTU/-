#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,x,q,y,res,k,minn=0x3f3f3f3f3f3f3f3f,t,sum,t1,t2,ys,judge;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    else
    {
    	ll d=exgcd(b,a%b,y,x);
	    y-=a/b*x;
	    return d;
	}
}
int main ()
{
	cin>>n>>p>>x>>q>>y;
	for(int i=1;i<=n;i++) cin>>k,res+=k;
	if(res%n==0)
	{
		printf("0");
		return 0;
	}
	else
	{
		if(x%n==0&&y%n==0)
		{
			printf("-1");
			return 0;
		}
		else
		{
			res%=n;
			for(int i=0;i<n;i++)
			{
				ll tt=(n-(res-i*y)%n+n)%n;  //k*x=tt(mod n)  =>  k*x+y*n==n-res
				ys=exgcd(x,n,t1,t2);
				if(tt%ys!=0) continue;
				judge=1;
				t1*=tt/ys;
				t1=(t1%(n/ys)+(n/ys))%(n/ys);
//				cout<<t1<<" "<<res<<endl;
				minn=min(minn,i*q+(t1*p));
			}
			if(!judge) printf("-1");
			else
			printf("%lld",minn);
		}
	}
	return 0;
}