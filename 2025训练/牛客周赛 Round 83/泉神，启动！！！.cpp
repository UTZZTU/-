#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
int f[10];
void solve()
{
//	ll x,z,y;
//	bool flag;
////	map<int,bool> mp;
//    for(int i=0;i<10;i++)
//    {
//    	f[i]=0;
//	}
//	cin>>x;
//	z=x;
//	while(z)
//	{
//		f[z%10]=1;
//		z/=10;
//	}
//	for(ll i=2;;i++)
//	{
//		flag=false;
//		y=i*x;
//		while(y!=0)
//		{
//			if(f[y%10]==0)
//			{
//				flag=true;
//				break;
//			}
//			else y/=10;
//		}
//		if(!flag)
//		{
//			cout<<i<<endl;
////			break;
//		}
//	}
	ll n,cnt=-1,m;
	cin>>n;
	m=n;
	while(m!=0)
	{
		m/=10;
		cnt++;
	}
	if(n<=9) cout<<11<<endl;
	else 
	{
		cout<<1;
		for(int i=1;i<=cnt;i++)
		{
			cout<<0;
		}
		cout<<1<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}