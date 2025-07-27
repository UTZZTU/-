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
//using u32 = unsigned int;
//using u64 = unsigned long long;
//using i128 = __int128;
//using u128 = unsigned __int128;
//using f128 = __float128;

struct Node
{
	int num,pos;
}S[N];

bool Cmp(Node x,Node y)
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

//cout<<fixed<<setprecision(x)
int n,q,f[100010],pp[100010][20],ks=0x3f3f3f3f;
int lg[100010]={-1};
map<int,vector<int>> mp;
int query(int l,int r){
	int len=lg[r-l+1];
//	int ans1=max(maxx[l][len],maxx[r-(1<<(len))+1][len]);
	int ans2=min(pp[l][len],pp[r-(1<<(len))+1][len]);
	return ans2;
}
void solve()
{
	for(int i=1;i<=100000;i++) pp[i][0]=ks;
//	memset(pp,0x3f,sizeof pp);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
//		int ssz=mp[f[i]].sz();
//		if(ssz>=2)
//		{
//			if(pp[mp[f[i]][ssz-1]][0]==ks&&i>mp[f[i]][ssz-1]+1)
//			{
//				pp[mp[f[i]][ssz-1]][0]=i;
//			}
//			if(pp[mp[f[i]][ssz-2]][0]==ks&&i>mp[f[i]][ssz-2]+1)
//			{
//				pp[mp[f[i]][ssz-2]][0]=i;
//			}
//		}
//		else if(ssz>=1)
//		{
//			if(pp[mp[f[i]][ssz-1]]==ks&&i>mp[f[i]][ssz-1]+1)
//			{
//				pp[mp[f[i]][ssz-1]][0]=i;
//			}
//		}
		mp[f[i]].pb(i);
		lg[i]=lg[i/2]+1;
	}
	for(auto it=mp.bg();it!=mp.end();it++)
	{
		if(it->second.sz()>=2)
		{
			vector<int> v=it->second;
			for(int i=0;i<v.sz();i++)
			{
				for(int j=i+1;j<=i+2;j++)
				{
					if(j>=v.sz()) break;
					if(v[j]>v[i]+1)
					{
						pp[v[i]][0]=v[j];
						break;
					}
				}
//cout<<v[i]<<" ";
			}
//			cout<<endl;
		}
	}
//	for(int i=1;i<=10;i++) printf("%d ",pp[i][0]);
//	printf("\n");
	for(int i=1;i<=lg[n];i++)
	{
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
//			maxx[j][i]=max(maxx[j][i-1],maxx[j+(1<<(i-1))][i-1]);
			pp[j][i]=min(pp[j][i-1],pp[j+(1<<(i-1))][i-1]);
		}
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int res=query(l,r);
		cout<<res<<endl;
		if(res==ks||res>r) printf("NO\n");
		else printf("YES\n");
	}
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	IOS;
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