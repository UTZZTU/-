#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll n,a[1000010],pp[1000010],qq[1000010],ans;
ll MOD=998244353;
//ll n,a[1000010],jl[1000010],res;
//void cl(int i,int j,int k)
//{
//	if(k==1) 
//	{
//		res+=a[i];
//		jl[i]++;
//	}
//	else if(k==2)
//	{
//		res+=a[j];
//		jl[j]++;
//	}
//	else
//	{
//		cl(i,j,k-2);
//		cl(i,j,k-1);
//	}
//}
void solve()
{
//	res=0;
//	cin>>n;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		jl[i]=0;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i;j<=n;j++)
//		{
//			cl(i,j,j-i+1);
//		}
//	}
////	cout<<res<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<jl[i]<<" ";
//	}
//	cout<<endl;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=(ans+a[i]*pp[n-i+1])%MOD;
		ans=(ans+a[i]*qq[i])%MOD;
	}
	cout<<ans<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	pp[1]=1;
	pp[2]=0;
	qq[1]=0;
	qq[2]=1;
	for(int i=3;i<=1000000;i++)
	{
		pp[i]=(pp[i-1]+pp[i-2])%MOD;
		qq[i]=(qq[i-1]+qq[i-2])%MOD;
	}
	for(int i=1;i<=1000000;i++)
	{
		pp[i]=(pp[i]+pp[i-1])%MOD;
		qq[i]=(qq[i]+qq[i-1])%MOD;
	}
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}