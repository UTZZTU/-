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

ll f[2][2][2][2][2][2],vis[2][2][2][2][2][2],pos;
string u,v;
struct Node
{
	VI vec;
	int cnt;
	inline bool operator<(const Node &x)const{
		return cnt>x.cnt;
	}
};
/*
1
000000
111111
*/
void solve()
{
	priority_queue<Node> p;
	cin>>u>>v;
	memset(vis,0,sizeof vis);
	memset(f,0x1f,sizeof f);
	pos=f[0][0][0][0][0][0];
	VI vec;
	for(auto c:u)
	{
		vec.emplace_back(c-'0');
	}
	p.push({vec,0});
	f[vec[0]][vec[1]][vec[2]][vec[3]][vec[4]][vec[5]]=0;
	while(!p.empty())
	{
		auto [vec,cnt]=p.top();
		p.pop();
		if(vis[vec[0]][vec[1]][vec[2]][vec[3]][vec[4]][vec[5]]) continue;
		vis[vec[0]][vec[1]][vec[2]][vec[3]][vec[4]][vec[5]]=1;
		f[vec[0]][vec[1]][vec[2]][vec[3]][vec[4]][vec[5]]=cnt;
		for(int i=1;i<=6;i++)
		{
			VI v=vec;
			if(i==1)
			{
				v[0]=1-v[0];
				v[1]=1-v[1];
				v[4]=1-v[4];
				v[5]=1-v[5];
			}
			else if(i==2)
			{
				v[0]=1-v[0];
				v[1]=1-v[1];
				v[2]=1-v[2];
			}
			else if(i==3)
			{
				v[1]=1-v[1];
				v[2]=1-v[2];
				v[3]=1-v[3];
				v[5]=1-v[5];
			}
			else if(i==4)
			{
				v[2]=1-v[2];
				v[3]=1-v[3];
				v[4]=1-v[4];
				v[5]=1-v[5];
			}
			else if(i==5)
			{
				v[0]=1-v[0];
				v[3]=1-v[3];
				v[4]=1-v[4];
			}
			else if(i==6)
			{
				v[0]=1-v[0];
				v[2]=1-v[2];
				v[3]=1-v[3];
				v[5]=1-v[5];
			}
			p.push({v,cnt+1});
		}
	}
	vec.cl();
	for(auto c:v)
	{
		vec.emplace_back(c-'0');
	}
	if(f[vec[0]][vec[1]][vec[2]][vec[3]][vec[4]][vec[5]]==pos) pr(-1);
	else pr(f[vec[0]][vec[1]][vec[2]][vec[3]][vec[4]][vec[5]]);
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