#include <bits/stdc++.h>
using namespace std;
const double Eps = 1e-8;
const double PI = atan(-1.0);
const int N = 1e5+5;
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
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define pr(x) cout<<x<<endl

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

int n,flag,f[4]={0,1,2,3};
struct Node
{
	int x,y,z;
}s[110];
void solve()
{
	flag=0;
	f[1]=1;
	f[2]=2;
	f[3]=3;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].x>>s[i].y>>s[i].z;
	}
	do{
		int i=1;
		for(i;i<=n;i++)
		{
			if(s[i].x==s[i].y&&s[i].z==1) break;
			if(s[i].x==s[i].y) continue;
			if(s[i].z==0)
			{
				if(f[s[i].x]<=f[s[i].y]) ;
				else
				{
					break;
				}
			}
			else
			{
				if(f[s[i].x]>f[s[i].y]) ;
				else 
				{
					break;
				}
			} 
		}
		if(i==n+1)
		{
			flag=1;
			break;
		}
	}while(next_permutation(f+1,f+1+3));
	f[1]=1;
	f[2]=1;
	f[3]=2;
	do{
		int i=1;
		for(i;i<=n;i++)
		{
			if(s[i].x==s[i].y&&s[i].z==1) break;
			if(s[i].x==s[i].y) continue;
			if(s[i].z==0)
			{
				if(f[s[i].x]<=f[s[i].y]) ;
				else
				{
					break;
				}
			}
			else
			{
				if(f[s[i].x]>f[s[i].y]) ;
				else 
				{
					break;
				}
			} 
		}
		if(i==n+1)
		{
			flag=1;
			break;
		}
	}while(next_permutation(f+1,f+1+3));
	f[1]=1;
	f[2]=2;
	f[3]=2;
	do{
		int i=1;
		for(i;i<=n;i++)
		{
			if(s[i].x==s[i].y&&s[i].z==1) break;
			if(s[i].x==s[i].y) continue;
			if(s[i].z==0)
			{
				if(f[s[i].x]<=f[s[i].y]) ;
				else
				{
					break;
				}
			}
			else
			{
				if(f[s[i].x]>f[s[i].y]) ;
				else 
				{
					break;
				}
			} 
		}
		if(i==n+1)
		{
			flag=1;
			break;
		}
	}while(next_permutation(f+1,f+1+3));
	f[1]=1;
	f[2]=1;
	f[3]=1;
	do{
		int i=1;
		for(i;i<=n;i++)
		{
			if(s[i].x==s[i].y&&s[i].z==1) break;
			if(s[i].x==s[i].y) continue;
			if(s[i].z==0)
			{
				if(f[s[i].x]<=f[s[i].y]) ;
				else
				{
					break;
				}
			}
			else
			{
				if(f[s[i].x]>f[s[i].y]) ;
				else 
				{
					break;
				}
			} 
		}
		if(i==n+1)
		{
			flag=1;
			break;
		}
	}while(next_permutation(f+1,f+1+3));
	if(flag) yes;
	else no;
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	IOS;
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}