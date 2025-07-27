#include<iostream>
using namespace std;
typedef long long ll;
int a[1005][1005],s[1005][1005];
int main ()
{
	ll n,m,r,c,i,j,t,mx=0;
	cin>>n>>m>>r>>c;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
			s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
		}
	}
	for(i=r;i<=n;i++)
	{
		for(j=c;j<=m;j++)
		{
			t=s[i][j]-s[i-r][j]-s[i][j-c]+s[i-r][j-c];
			mx=max(mx,t);
		}
	}
	cout<<mx;
	return 0;
}