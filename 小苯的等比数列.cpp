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
int n,f[200010],sum[200010],maxx,vis[200010];
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		sum[f[i]]++;
		maxx=max(maxx,sum[f[i]]);
	}
	if(sum[1]>0)
	{
		for(int i=2;i<=200000;i++)
		{
			if(sum[i]) maxx=max(maxx,2);
		}
	}
	if(maxx>=19)
	{
		printf("%d\n",maxx);
		return;
	}
	sort(f+1,f+1+n);
	for(int i=n;i>=1;i--)
	{
		if(vis[f[i]]) continue;
		for(int j=2;j*j<=f[i];j++)
		{
			if(f[i]%j==0)
			{
				int x=f[i]/j;
				vector<int> vec;
				int tp=f[i];
				while(tp>0)
				{
					if(sum[tp]>0) vec.pb(tp);
					if(tp%j==0) tp/=j;
					else break;
				}
				int num=1;
				for(int k=1;k<vec.sz();k++)
				{
					if(vec[k]*j==vec[k-1]) num++;
					else
					{
						maxx=max(maxx,num);
						num=1;
					}
				}
				maxx=max(maxx,num);
				if(x!=j)
				{
					vec.cl();
					tp=f[i];
					while(tp>0)
					{
						if(sum[tp]>0) vec.pb(tp);
						if(tp%x==0) tp/=x;
						else break;
					}
					num=1;
					for(int k=1;k<vec.sz();k++)
					{
						if(vec[k]*x==vec[k-1]) num++;
						else
						{
							maxx=max(maxx,num);
							num=1;
						}
					}
					maxx=max(maxx,num);
				}
			}
		}
		vis[f[i]]=1;
	}
	printf("%d\n",maxx);
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