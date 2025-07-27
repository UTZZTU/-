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
int n,x[110],y[110],flag;
double minn;
bool judge(int i,int j,int k)
{
	if(x[i]==x[j]&&x[i]==x[k]||y[i]==y[j]&&y[i]==y[k]) return false;
	if((y[i]-y[j])*(x[j]-x[k])==(y[j]-y[k])*(x[i]-x[j])) return false;
	if(x[i]==x[j]&&y[i]==y[j]||x[i]==x[k]&&y[i]==y[k]||x[j]==x[k]&&y[j]==y[k]) return false;
	return true;
}
//double get_len(int i,int j)
//{
//	double s=(double)sqrt((x[i]-x[j])*1.0*(x[i]-x[j])+(y[i]-y[j])*1.0*(y[i]-y[j]));
//	return s;
//}
void solve()
{
	flag=0;
	minn=1000000000.0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(n<3)
	{
		cout<<-1<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(!judge(i,j,k)) continue;
//				cout<<i<<" "<<j<<" "<<k<<endl;
				flag=1;
//				double l1=get_len(i,j);
//				double l2=get_len(i,k);
//				double l3=get_len(k,j);
//				double p=l1+l2+l3;
//				p/=2.0;
//				cout<<l1<<" "<<l2<<" "<<l3<<" "<<p<<endl;
//				double s=sqrt(p*1.0*(p-l1)*(p-l2)*(p-l3));
				double s=(x[j]-x[i])*(y[k]-y[i])-(y[j]-y[i])*(x[k]-x[i]);
				if(s<0) s=-s;
				s*=0.5;
//				cout<<s<<endl;
				minn=min(minn,s);
			}
		}
	}
	if(flag)
	{
		cout<<fixed<<setprecision(8)<<minn<<endl;
	}
	else
	{
		cout<<-1<<endl;
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