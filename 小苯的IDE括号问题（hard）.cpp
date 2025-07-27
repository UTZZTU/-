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

int n,k;
vector<char> vec;
stack<char> st1,st2;
string s,a="backspace",b="delete",c="<-",d="->",u;
void solve()
{
	cin>>n>>k;
	cin>>s;
	int pos=s.find("I");
	for(int i=0;i<pos;i++) st1.push(s[i]);
	for(int i=n-1;i>pos;i--) st2.push(s[i]);
	while(k--)
	{
		cin>>u;
		if(u==a)
		{
			if(st1.sz()&&st2.sz()&&st1.top()=='('&&st2.top()==')')
			{
				st1.pop();
				st2.pop();
			}
			else if(st1.sz())
			{
				st1.pop();
			}
		}
		else if(u==b)
		{
			if(st2.sz()) st2.pop();
		}
		else if(u==c)
		{
			if(st1.sz())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		else
		{
			if(st2.sz())
			{
				st1.push(st2.top());
				st2.pop();
			}
		}
	}
	while(!st1.empty())
	{
		vec.emplace_back(st1.top());
		st1.pop();
	}
	reverse(vec.bg(),vec.ed());
	for(auto c:vec)
	{
		cout<<c;
	}
	cout<<"I";
	while(!st2.empty())
	{
		cout<<st2.top();
		st2.pop();
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