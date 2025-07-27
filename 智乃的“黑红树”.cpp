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

int a,b,cnt1,cnt2,cnt;
VI vec[200010];
//map<int,int> mp1,mp2;
void bfs(int level,int color)
{
	queue<pair<int,int>> q;
	q.push({level,color});
	while(!q.empty())
	{
		auto p=q.front();
		q.pop();
		if(p.se==0)
		{
			if(cnt2<b)
			{
				cnt2+=2;
				vec[p.fi].emplace_back(cnt);
				vec[p.fi].emplace_back(cnt+1);
				q.push({cnt,1});
				q.push({cnt+1,1});
				cnt+=2;
			}
		}
		else
		{
			if(cnt1<a)
			{
				cnt1+=2;
				vec[p.fi].emplace_back(cnt);
				vec[p.fi].emplace_back(cnt+1);
				q.push({cnt,0});
				q.push({cnt+1,0});
				cnt+=2;
			}
		}
	}
}
void solve()
{
	cnt=2;
	cin>>a>>b;
	for(int i=1;i<=a+b;i++) vec[i].cl();
	cnt1=1,cnt2=0;
	bfs(1,0);
	if(cnt1==a&&cnt2==b)
	{
		yes;
		for(int i=1;i<=a+b;i++)
		{
			if(vec[i].sz()==0) cout<<-1<<" "<<-1<<endl;
			else cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
		}
	}
	else
	{
		no;
	}
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