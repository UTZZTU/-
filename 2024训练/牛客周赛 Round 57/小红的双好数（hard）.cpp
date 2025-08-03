#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
ll k1,k2,cs,flag,ss;
bool check(ll x,ll y)
{
	if(x<=2) return false;
	while(x)
	{
		if(x%y>1) return false;
		x/=y;
	}
	return true;
}
void dfs(__int128 x,__int128 sum,__int128 level)
{
	if(flag) return;
	if(sum>1e18) return;
	if(x>cs)
	{
		if(sum>1e18) return;
		ll tt=sum;
		if(check(tt,k1))
		{
			ss=tt;
			flag=1;
		}
		return;
	}
	ll tt=sum;
	if(check(tt,k1))
	{
		ss=tt;
		flag=1;
		return;
	}
	dfs(x+1,sum+level,level*k2);
	dfs(x+1,sum,level*k2);
}
void solve()
{
	cin>>k1>>k2;
//	if(k1==4&&k2==7||k1==5&&k2==7||k1==5&&k2==8||k1==5&&k2==9||k1==6&&k2==8||k1==6&&k2==9||k1==7&&k2==9)
//	{
//		cout<<"NO"<<endl;
//		return;
//	}
	if(k2<7)
	{
		for(ll i=2;;i++)
		{
			if(check(i,k2)&&check(i,k1))
			{
				cout<<"YES"<<endl;
				cout<<i<<endl;
				return;
			}
		}
	}
	else
	{
		cs=(log(1e18*1.0)/log(k2*1.0))+1;
		__int128 p1=1,p2=0,p3=1;
		dfs(p1,p2,p3);
		if(flag) 
		{
			cout<<"YES"<<endl;
			cout<<ss<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}