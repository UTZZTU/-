#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010],b[100010],c[100010],n,res1,res2;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		c[i]=b[i]-a[i];
		if(c[i]<0)
		{
			res1-=c[i];
		}
		else res2+=c[i];
	}
	if(res1==res2)
	{
		cout<<res1;
	}
	else cout<<-1;
	return 0;
}