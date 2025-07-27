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
string u,v="12345678x";
char c;
int nx,dirx[4]={-1,0,1,0},diry[4]={0,1,0,-1};
string l="urdl";

int f(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i ++ )
        if (s[i] != 'x')
        {
            int t = s[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    return res;
}
void bfs()
{
	unordered_map<string,pair<char,string>> mp1;
	unordered_map<string,int> mp2;
	priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> q;
	q.push({f(u),u});
	mp2[u]=0;
	while(!q.empty())
	{
		auto p=q.top();
		string s=p.se;
		q.pop();
		if(s==v) break;
		string t=s;
		int x,y;
		for(int i=0;i<9;i++)
		{
			if(s[i]=='x')
			{
				x=i/3,y=i%3;
				break;
			}
		}
		for(int i=0;i<4;i++)
		{
			int xx=dirx[i]+x,yy=diry[i]+y;
			if(xx>=0&&xx<3&&yy>=0&&yy<3)
			{
				swap(s[x*3+y],s[xx*3+yy]);
				if(mp2.count(s)==0||mp2[s]>mp2[t]+1)
				{
					mp2[s]=mp2[t]+1;
					mp1[s]={l[i],t};
					q.push({mp2[s]+f(s),s});
				}
				swap(s[x*3+y],s[xx*3+yy]);
			}	
		}
	}
	string ss;
	while(v!=u)
	{
		ss+=mp1[v].fi;
		v=mp1[v].se;
	}
	reverse(ss.bg(),ss.ed());
	pr(ss);
}
void solve()
{
	for(int i=1;i<=9;i++)
	{
		cin>>c;
		u+=c;
	}
	for(int i=0;i<=8;i++)
	{
		if(u[i]=='x') continue;
		for(int j=i+1;j<=8;j++)
		{
			if(u[j]=='x') continue;
			if(u[i]>u[j]) nx++;		
		}
	}
	if(nx&1)
	{
		pr("unsolvable");
	}
	else
	{
		bfs();
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