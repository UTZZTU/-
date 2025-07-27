#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p[4]={1,1,1,0},k;
ll A[4][4]={
	{0,1,0,0},
	{1,1,1,0},
	{0,0,1,1},
	{0,0,0,1}
};
void mul(ll c[], ll a[], ll b[][4]){
	ll temp[4]={0};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		temp[i]=(temp[i]+a[j]*b[j][i])%m;
	}
	memcpy(c,temp,sizeof(temp));
}

void mul(ll c[][4], ll a[][4], ll b[][4]){
	ll temp[4][4]={0};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%m;
		}
	}
	memcpy(c,temp,sizeof(temp));
}
int main ()
{
	cin>>n>>m;
	k=n-1;
	while(k)
	{
		if(k&1) mul(p, p, A);
		mul(A, A, A);
		k>>=1;
	}
	cout<<((n*p[2]-p[3])%m+m)%m;
	return 0;
}