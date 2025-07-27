#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[100010],b[100010],k;
int poww(int a,int b)
{
	int res=1;
	for(int i=1;i<=b;i++)
	{
		res=res*a;
	}
	return res;
}
int num(int pos)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if((b[i]>>pos)&1) ;
		else
		{
			int tt=(int)poww((int)2,pos);
			int cnt=b[i]%tt;
			int qs=tt-cnt;
			if(sum+qs>k) return 2e18;
			sum+=qs;
//			cout<<i<<" "<<pos<<" "<<qs<<endl;
		}	
//		cout<<sum<<endl;
	}
	if(sum>k) return 2e18;
	for(int i=1;i<=n;i++)
	{
		if((b[i]>>pos)&1) ;
		else
		{
			int tt=(int)poww((int)2,pos);
			int cnt=b[i]%tt;
			int qs=tt-cnt;
			b[i]+=qs;
		}	
	}
	return sum;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=a[i];
		}
		cin>>k;
		int res=0;
		for(int i=62;i>=0;i--)
		{
			int x=num(i);
			if(x<=k)
			{
				res+=(int)poww((int)2,i);
				k-=x;
			}
//			cout<<res<<endl;
		}
		cout<<res<<endl;
	}
}
signed main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}