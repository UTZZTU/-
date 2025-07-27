#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,a,c,x0,n,g,s[2],z[2][2];
ll qui(ll a,ll b)
{
	ll res=0;
	while(b)
	{
		if(b&1)
		res=(res+a)%m;
		a=(a+a)%m;
		b>>=1;
	}
	return res;
}
void qmi(ll c[],ll a[],ll b[][2])
{
	ll tt[2]={0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		tt[i]=(tt[i]+qui(a[j],b[j][i])%m)%m;
	}
	memcpy(c,tt,sizeof(tt));
}
void qmi(ll c[][2],ll a[][2],ll b[][2])
{
	ll tt[2][2]={0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			tt[i][j]=(tt[i][j]+qui(a[i][k],b[k][j])%m)%m;
		}
	}
	memcpy(c,tt,sizeof(tt));
}
int main ()
{
	cin>>m>>a>>c>>x0>>n>>g;
	s[0]=x0,s[1]=c;
	z[0][0]=a,z[1][0]=1,z[1][1]=1;
	while(n)
	{
		if(n&1)
		qmi(s,s,z);
		qmi(z,z,z);
		n>>=1;
	}
	cout<<s[0]%g;
	return 0;
}