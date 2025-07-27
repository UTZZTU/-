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

//using ll = long long;
//using u32 = unsigned int;
//using u64 = unsigned long long;
//using i128 = __int128;
//using u128 = unsigned __int128;
//using f128 = __float128;

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

//cout<<fixed<<setprecision(x)

int n,m,x,k,f[1010][1010];
char c;
void solve()
{
	cin>>n>>m>>x;
	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=0;
		}
	}
	f[0][x]=1;
	for(int i=1;i<=m;i++)
	{
		cin>>k>>c;
		if(c=='0')
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i-1][j]==1)
				{
					int pos=j+k;
					pos%=n;
					if(pos==0) pos=n;
					f[i][pos]=1;
				}
			}
		}
		else if(c=='1')
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i-1][j]==1)
				{
					int pos=j-k;
					pos=(pos+n)%n;
					if(pos==0) pos=n;
					f[i][pos]=1;
				}
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i-1][j]==1)
				{
					int pos1=j-k;
					pos1=(pos1+n)%n;
					if(pos1==0) pos1=n;
					f[i][pos1]=1;
					int pos2=j+k;
					pos2%=n;
					if(pos2==0) pos2=n;
					f[i][pos2]=1;
				}
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f[m][i]) sum++;
	}
	pr(sum);
	for(int i=1;i<=n;i++)
	{
		if(f[m][i]) cout<<i<<" ";
	}
	cout<<'\n';
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