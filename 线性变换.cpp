#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,k,b,t,a[1000010],pos,x,f[1000010],num[1000010],loop,val,cs;
int main ()
{
	scanf("%lld%lld%lld%lld%lld",&n,&p,&k,&b,&t);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=t;i++)
	{
		x+=a[p];
		if(f[p])
		{
			loop=i-f[p];
			val=x-num[p];
			x+=(t-i)/loop*val;
			cs=(t-i)%loop;
			for(int j=1;j<=cs;j++)
			{
				p=(k*p+b)%n;
				x+=a[p];
			}
			break;
		}
		else
		{
			f[p]=i;
			num[p]=x;
		}
		p=(k*p+b)%n;
	}
	cout<<x;
	return 0;
}