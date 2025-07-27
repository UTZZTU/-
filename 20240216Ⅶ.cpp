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
#define debug(x) cout<<"x"<<endl
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define Mem(x) memset(x,0,sizeof x)
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
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

int n,k,vis[200010];
multiset<int> st1,st2;
string s,a="backspace",b="delete",c="<-",d="->",u;
void solve()
{
	cin>>n>>k;
	cin>>s;
	int pos=s.find("I");
	int l=pos-1,r=pos+1;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='I')
		{
			st1.is(i);
			st2.insert(-i);
		}
	}
	while(k--)
	{
		cin>>u;
		if(u==c)
		{
			if(l>=0) 
			{
				r=l;
				if(st2.lower_bound(-l+1)==st2.ed()) l=-1;
				else	l=-(*st2.lower_bound(-l+1));
			}
		}
		else if(u==d)
		{
			if(r<n)
			{
				l=r;
				if(st1.lower_bound(r+1)==st1.ed()) r=n+1;
				else	r=(*st1.lower_bound(r+1));
			}
		}
		else if(u==a)
		{
			if(l>=0&&r<n)
			{
				if(s[l]=='('&&s[r]==')')
				{
					int ll,rr;
					if()
				}
				else
				{
					int pre=vec[l];
					vec.erase(lower_bound(vec.bg(),vec.ed(),pre));
					l--;
					r=l+1;
				}
			}
			else if(l>=0)
			{
				int pre=vec[l];
				vec.erase(lower_bound(vec.bg(),vec.ed(),pre));
				l--;
				r=l+1;
			}
			else if(r<n)
			{
				;
			}
			else
			{
				;
			}
		}
		else if(u==b)
		{
			if(r<n)
			{
				int post=vec[r];
				vec.erase(lower_bound(vec.bg(),vec.ed(),post));
			}
		}
	}
	for(int i=0;i<=l&&i<n;i++)
	{
		if(!vis[i]) cout<<s[i];
	}
	cout<<"I";
	if(r>=0)
	for(int i=r;i<n;i++)
	{
		if(!vis[i]) cout<<s[i];
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