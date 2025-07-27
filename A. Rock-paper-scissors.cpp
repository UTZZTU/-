#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);

#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define PI pair<int,int>
#define Um unordered_map
#define Mul multiset
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

string s1,s2,s3,a="rock",b="paper",c="scissors";
void solve()
{
	cin>>s1>>s2>>s3;
	if(s1==a)
	{
		if(s2==a)
		{
			if(s3==a)
			{
				cout<<"?";
			}
			else if(s3==b)
			{
				cout<<"S";
			}
			else
			{
				cout<<"?";
			}
		}
		else if(s2==b)
		{
			if(s3==a)
			{
				cout<<"M";
			}
			else if(s3==b)
			{
				cout<<"?";
			}
			else
			{
				cout<<"?";
			}
		}
		else
		{
			if(s3==a)
			{
				cout<<"?";
			}
			else if(s3==b)
			{
				cout<<"?";
			}
			else
			{
				cout<<"F";
			}
		}
	}
	else if(s1==b)
	{
		if(s2==a)
		{
			if(s3==a)
			{
				cout<<"F";
			}
			else if(s3==b)
			{
				cout<<"?";
			}
			else
			{
				cout<<"?";
			}
		}
		else if(s2==b)
		{
			if(s3==a)
			{
				cout<<"?";
			}
			else if(s3==b)
			{
				cout<<"?";
			}
			else
			{
				cout<<"S";
			}
		}
		else
		{
			if(s3==a)
			{
				cout<<"?";
			}
			else if(s3==b)
			{
				cout<<"M";
			}
			else
			{
				cout<<"?";
			}
		}
	}
	else
	{
		if(s2==a)
		{
			if(s3==a)
			{
				cout<<"?";
			}
			else if(s3==b)
			{
				cout<<"?";
			}
			else
			{
				cout<<"M";
			}
		}
		else if(s2==b)
		{
			if(s3==a)
			{
				cout<<"?";
			}
			else if(s3==b)
			{
				cout<<"F";
			}
			else
			{
				cout<<"?";
			}
		}
		else
		{
			if(s3==a)
			{
				cout<<"S";
			}
			else if(s3==b)
			{
				cout<<"?";
			}
			else
			{
				cout<<"?";
			}
		}
	}
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}