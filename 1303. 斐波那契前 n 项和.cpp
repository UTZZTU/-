#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
void mul(ll c[],ll a[],ll b[][3])
{
	ll temp[3]={0};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		temp[i]=(temp[i]+a[j]*b[j][i])%m;
	}
	memcpy(c,temp,sizeof(temp));
}
void mul(ll c[][3],ll a[][3],ll b[][3])
{
	ll temp[3][3]={0};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%m;
		}
	}
	memcpy(c,temp,sizeof(temp));
}
int main ()
{
	cin>>n>>m;
	ll f1[3]={1,1,1};
	ll a[3][3]={
		{0,1,0},
		{1,1,1},
		{0,0,1}
	};
	n--;
	while(n)
	{
		if(n&1) mul(f1,f1,a);
		mul(a,a,a);
		n>>=1;
	}
	cout<<f1[2];
	return 0;
}