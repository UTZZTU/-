#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,mid,n,m,res,k,f[100010],width,fib[1010],sum_fib[1010],cnt,num;
bool check(ll x)
{
	k=x;
	res=0;
	for(int i=1;i<=n;i++)
	{
		res+=k;
		if(res>m)
		return false;
		k=res;
	}
	return true;
}
int main ()
{
	fib[1]=sum_fib[1]=1;
	for(int i=2;;i++)
	{
		fib[i]=sum_fib[i-1];
		sum_fib[i]=sum_fib[i-1]+fib[i];
		if(sum_fib[i]>1e15)
		{
			cnt=i;
			break;
		}
	}
	cin>>n>>m;
	l=0,r=m;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))
		l=mid;
		else
		r=mid-1;
	}
	if(l==0)
	cout<<-1;
	else
	{
		res=0;
		k=l;
		for(int i=1;i<=n;i++)
		{
			
			f[i]=k;
			res+=k;
			k=res;
		}
		res=m-res;
		while(res)
		{
			ll x=upper_bound(sum_fib+1,sum_fib+51,res)-sum_fib;
			x--;
			num=1;
			for(int i=n-x+1;i<=n;i++)
			{
				f[i]+=fib[num];
				num++;
			}
			res-=sum_fib[x];
		}
		for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	}
	return 0;
}