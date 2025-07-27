#include <iostream>
using namespace std;
typedef long long ll;
ll f[5050][5050],m,n;
ll maxsubarray(ll *a,ll len)
{
	ll i,sum=a[0],b=0;
	for(int i=0;i<len;++i)
	{
		if(b>0)
		b+=a[i];
		else
		b=a[i];
		if(b>sum)
		sum=b;
	}
	return sum;
}
ll maxsubmatrix(ll x,ll y,ll array[5050][5050])
{
	ll i,j,h,max,sum=-100000000;
	ll b[100000];
	for(int i=0;i<x;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<x;j++)
		{
			for(h=0;h<y;h++)
			{
				b[h]+=array[j][h];
			}
			max=maxsubarray(b,h);
			if(max>sum)
			sum=max;
		}
	}
	return sum;
}
int main ()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		scanf("%lld",&f[i][j]);
	}
	cout<<maxsubmatrix(m,n,f);
	return 0;
}