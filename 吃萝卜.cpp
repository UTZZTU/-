#include<bits/stdc++.h>
using namespace std;
int m,n,a[100005];
int check(int mid)
{
	int sum=0,num=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>mid)
		{
			num++;sum=a[i];
		}
	}
	num++;
	if(num>m)return 0;
	else return 1;
}
int main()
{
	cin>>n>>m;
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=max(l,a[i]);
		r+=a[i];
	}
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
} 
