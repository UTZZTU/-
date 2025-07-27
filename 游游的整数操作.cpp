#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI pair<int,int> 
#define fi first
#define se second
#define pb push_back
#define fr front
#define bk back
#define gl getline
const ll mod = 1e9+7;
ll n,k,a[100010],op,x,res;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(k--)
	{
		cin>>op>>x;
		if(op==1)
		{
			for(int i=1;i<=n;i++)
			{
				a[i]+=x;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				a[i]=max((ll)0,a[i]-x);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		res=(res+a[i])%mod;
	}
	cout<<res;
	return 0;
}