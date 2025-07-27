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
char c;
string u="12345678",v;
unordered_map<string,int> mp1;
unordered_map<string,pair<char,string>> mp2;
string get_str(int pos,string s)
{
	if(pos==0)
	{
		for(int i=0;i<4;i++)
		{
			swap(s[i],s[7-i]);
		}
	}
	else if(pos==1)
	{
		string l;
		l+=s[3];
		l+=s[0];
		l+=s[1];
		l+=s[2];
		l+=s[5];
		l+=s[6];
		l+=s[7];
		l+=s[4];
		s=l;
	}
	else
	{
		string l;
		l+=s[0];
		l+=s[6];
		l+=s[1];
		l+=s[3];
		l+=s[4];
		l+=s[2];
		l+=s[5];
		l+=s[7];
		s=l;
	}
	return s;
}
void bfs()
{
	mp1[u]=0;
	queue<string> q;
	q.push(u);
	while(!q.empty())
	{
		string x=q.front();
		q.pop();
		if(x==v) break;
		for(int i=0;i<3;i++)
		{
			string p=get_str(i,x);
			if(mp1.count(p)==0)
			{
				mp1[p]=mp1[x]+1;
				mp2[p]={'A'+i,x};
				q.push(p);
			}
		}
	}
	pr(mp1[v]);
	string t;
	while(v!=u)
	{
		t+=mp2[v].fi;
		v=mp2[v].se;
	}
	reverse(t.bg(),t.ed());
	if(t.sz())
	pr(t);
}
void solve()
{
	for(int i=1;i<=8;i++)
	{
		cin>>c;
		v+=c;
	}
	bfs();
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