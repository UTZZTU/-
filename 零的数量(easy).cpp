#include <bits/stdc++.h>
using namespace std;
int a[2000010],cnt0,cnt1,n,l,r,num;
int main ()
{
	cin>>n;
	cin>>cnt0;
	for(int i=1;i<=cnt0;i++)
	cin>>l>>r;
	cin>>cnt1;
	for(int i=1;i<=cnt1;i++)
	{
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		a[j]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		num++;
	}
	cout<<cnt0<<" "<<num;
	return 0;
}