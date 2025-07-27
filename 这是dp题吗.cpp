#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[310][1010],n,k,maxx=-0x3f3f3f3f3f3f3f3f;
int main ()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2*i-1;j++)
		{
//			cout<<i<<" "<<j<<endl;
			scanf("%lld",&f[i][j]);
			if(i==1) continue;
			ll p1=-0x3f3f3f3f3f3f3f3f,p2=-0x3f3f3f3f3f3f3f3f,p3=-0x3f3f3f3f3f3f3f3f;
			ll pos=j;
			if(pos>=1&&pos<=(2*i-3))
			{
				p1=f[i-1][pos];
			}
			pos=j-1;
			if(pos>=1&&pos<=(2*i-3))
			{
				p2=f[i-1][pos];
			}
			pos=j-2;
			if(pos>=1&&pos<=(2*i-3))
			{
				p3=f[i-1][pos];
			}
//			cout<<p1<<" "<<p2<<" "<<p3<<endl;
			f[i][j]+=(ll)max(p1,max(p2,p3));
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=2*i-1;j++)
//		{
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-i-1;j++)
		{
			int kk=n-1-i-j,pos=n+kk-j;
			if(kk>=0&&abs(kk-j)<=k&&pos>=1&&pos<=2*n-1)
			{
				maxx=max(maxx,f[n][pos]);
//				cout<<pos<<endl;
			}
		}
	}
	cout<<maxx;
	return 0;
}