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

//cout<<fixed<<setprecision(x)

struct Node
{
	int pos,num;
}s[100010];

bool cmp(Node x,Node y)
{
	return x.num<y.num;
}
int f[100010],n,m,cnt;
PI p[100010];
VI vec[100010];
map<PI,bool> mp;
void solve()
{
	for(int i=1;i<=100000;i++)
	{
		f[i]=-1;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		s[i].pos=i;
		cin>>s[i].num;
		vec[s[i].num].pb(i);
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			f[0]=1;
		}
		else
		{
			if(f[s[i].num-1]==-1)
			{
				pr(-1);
				return;
			}
			else
			{
				mp[{f[s[i].num-1],s[i].pos}]=true;
				mp[{s[i].pos,f[s[i].num-1]}]=true;
				p[cnt++]={f[s[i].num-1],s[i].pos};
				f[s[i].num]=s[i].pos;
			}
		}
	}
	if(cnt>m)
	{
		pr(-1);
		return;
	}
	for(int i=1;i<=n-1;i++)
	{
		if(cnt==m) break;
		if(vec[i].sz()>=2)
		{
			int len=vec[i].sz();
			for(int j=0;j<len;j++)
			{
				for(int k=j+1;k<len;k++)
				{
					p[cnt++]={vec[i][j],vec[i][k]};
					if(cnt==m) break;
				}
				if(cnt==m) break;
			}
			if(cnt==m) break;
		}
	}
	for(int i=1;i<n-1;i++)
	{
		if(vec[i].sz()&&vec[i+1].sz())
		{
			int l1=vec[i].sz();
			int l2=vec[i+1].sz();
			for(int j=0;j<l1;j++)
			{
				for(int k=0;k<l2;k++)
				{
					if(mp[{vec[i][j],vec[i+1][k]}])
					{
						;
					}
					else
					{
						p[cnt++]={vec[i][j],vec[i+1][k]};
						mp[{vec[i][j],vec[i+1][k]}]=true;
						mp[{vec[i+1][k],vec[i][j]}]=true;
						if(cnt==m) break;
					}
				}
				if(cnt==m) break;
			}
			if(cnt==m) break;
		}
	}
	if(cnt<m)
	{
		pr(-1);
		return;
	}
	for(int i=0;i<cnt;i++)
	{
		cout<<p[i].fi<<" "<<p[i].se<<endl;
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