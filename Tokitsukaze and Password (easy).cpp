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
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
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

int n,t[10],res,f[10],y;
string s;
bool judge(VI vec)
{
//	for(auto x:vec)
//	{
//		cout<<x<<" ";
//	}
	if((int)vec.sz()>1&&vec[0]==0)
	{
//		cout<<"ok";
		return false;
	}
//	for(auto x:vec)
//	{
//		cout<<x<<" ";
//	}
	int sum=0;
	for(auto x:vec)
	{
		sum=sum*10+x;
	}
	if(sum%8==0&&sum<=y) return true;
	else return false;
}
void dfs(int level,VI vec)
{
	if(level>=n)
	{
//		for(auto x:vec)
//		{
//			cout<<x<<" ";
//		}
//		cout<<endl;
		if(judge(vec))
		{
			res++;
		}
		return;
	}
	if(s[level]>='0'&&s[level]<='9')
	{
		vec.pb(s[level]-'0');
		dfs(level+1,vec);
	}
	else if(s[level]>='a'&&s[level]<='d')
	{
		if(t[s[level]-'a']==-1)
		{
			int f1,f2,f3;
			if(s[level]=='a') f1=1,f2=2,f3=3;
			else if(s[level]=='b') f1=0,f2=2,f3=3;
			else if(s[level]=='c') f1=0,f2=1,f3=3;
			else f1=0,f2=1,f3=2;
			for(int i=0;i<=9;i++)
			{
				if(i==t[f1]||i==t[f2]||i==t[f3]) continue;
				t[s[level]-'a']=i;
				vec.pb(i);
				dfs(level+1,vec);
				vec.pop_back();
				t[s[level]-'a']=-1;
			}
		}
		else
		{
			vec.pb(t[s[level]-'a']);
			dfs(level+1,vec);
		}
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			if(!f[i])
			{
				f[i]=1;
				vec.pb(i);
				dfs(level+1,vec);
				vec.pop_back();
				f[i]=0;
			}
		}
	}
}
void solve()
{
	memset(f,0,sizeof f);
	memset(t,-1,sizeof t);
	res=0;
	cin>>n;
	cin>>s;
	cin>>y;
	VI vec;
	dfs(0,vec);
	pr(res);
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