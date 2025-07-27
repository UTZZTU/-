#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e6+5;
const int MOD = 1e9+7;

#define pb push_back
#define pf push_front
#define cl clear
#define fi first
#define se second
#define bg begin
#define ed end
#define sz size
#define fd find
#define is insert
#define PI pair<int,int>
#define PS pair<string,string>
#define Um unordered_map
#define Us unordered_set
#define Mul multiset<int>
#define VI vector<int>
#define VII vector< vector<int> > 
#define VS vector<string>
#define VN vector<node>
#define VP vector< pair<int,int> >
#define debug(x) cout<<"x"<<'\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<'\n'
#define yes cout<<"YES"<<'\n'
#define pr(x) cout<<x<<'\n'

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

struct node
{
	int num,pos;
}S[N];

bool cmp(node x,node y)
{
	return x.num<y.num;
}

int qmi(int a,int b,int mod)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

int qmi(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
ll n,a[100010],sum,b[100010],ksum;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		ksum+=a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]>0&&a[i]>0)
		{
			sum+=abs(a[i-1]-a[i]);
		}
	}
	if(sum>1) 
	{
		pr(-1);
		return;
	}
	if(sum==0)
	{
		if(ksum==0)
		{
			cout<<1<<" ";
			for(int i=2;i<=n;i++)
			{
				cout<<2<<" ";
			}
			return;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				int j=i+1;
				while(j<=n&&a[j]==a[i])
				{
					j++;
				}
				j--;
				if(i-1<=0)
				{
					for(int k=i;k<=j;k++)
					{
						a[k]=a[j+1];
					}
				}
				else if(j+1>=n+1)
				{
					for(int k=i;k<=j;k++)
					{
						a[k]=a[i-1];
					}
				}
				else
				{
					sum+=abs(a[i-1]-a[j+1]);
					if(sum>1)
					{
						pr(-1);
						return;
					}
					a[i]=a[i-1];
					for(int k=i+1;k<=j;k++)
					{
						a[k]=a[j+1];
					}
				}
				i=j;
			}
		}
		if(sum==0)
		{
			if(b[1]==0)
			{
				a[1]++;
			}
			else if(b[n]==0)
			{
				a[n]++;
			}
			else
			{
				pr(-1);
				return;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				int j=i+1;
				while(j<=n&&a[j]==a[i])
				{
					j++;
				}
				j--;
				if(i-1<=0||j+1>=n+1)
				{
					;
				}
				else
				{
					if(a[i-1]!=a[j+1])
					{
						pr(-1);
						return;
					}
				}
				int x;
				if(i-1>=1) x=a[i-1];
				if(j+1<=n) x=a[j+1];
				for(int k=i;k<=j;k++)
				{
					a[k]=x;
				}
				i=j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}
	}
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	IOS;
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