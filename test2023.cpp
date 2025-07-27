#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,k,b,t,a[1000010],pos,x,f[1000010],num[1000010],cnt=1,loop,val,cs;
int main ()
{
	cin>>n>>p>>k>>b>>t;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=t;i++)
	{
		
		x+=a[p];
		p=(k*p+b)%n;
	}
	cout<<x;
	return 0;
}