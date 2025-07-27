#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,res1,res2,tt,sum;
int main ()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		res1=0,res2=0;
		tt=n;
		while(tt%2==0)
		{
			tt/=2;
			res1++;
		}
		while(tt%5==0)
		{
			tt/=5;
			res2++;
		}
		sum=1;
		while(res1>res2&&sum*5<=m)
		{
			res2++;
			sum*=5;
		}
		while(res1<res2&&sum*2<=m)
		{
			res1++;
			sum*=2;
		}
		while(sum*10<=m)
		{
			res1++;
			res2++;
			sum*=10;
		}
		sum*=m/sum;
		if(res1==0||res2==0)
		cout<<n*m<<endl;
		else
		cout<<n*sum<<endl;
	}
	return 0;
}