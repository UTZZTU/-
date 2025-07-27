#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll sum[1000005],gra[1000005],a[1000005],maxn;
int main()
{
	int flag=0;
 
	ll n,p;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum[1]=a[1];
	gra[1]=a[1];
	maxn=gra[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=max(sum[i-1]+a[i],a[i]);
	}
	for(int i=2;i<=n;i++)
		{
			sum[i]=max(sum[i],sum[i-1]);
		}
		
		
	gra[2]=gra[1]+sum[1];
	for(int i=3;i<=n;i++)
	{
		if(gra[i-1]+sum[i-1]<0&&gra[i-1]>0)
		flag=1;
		if(flag)
		gra[i]=(gra[i-1]%p+sum[i-1])%p;
		else
		gra[i]=max(gra[i-1]+sum[i-1],gra[i-1]);
		maxn=max(gra[i],maxn);
	}
	 if(flag==1) 
	cout<<gra[n]%p<<endl;
    else 
	cout<<maxn%p<<endl;
	return 0;
	
}