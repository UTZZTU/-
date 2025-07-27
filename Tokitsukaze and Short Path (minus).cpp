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

ll n,a[200010],res,pre[200010];
void solve()
{
	res=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		pre[i]=a[i]+pre[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			res+=2ll*a[i]*(n-i);
		}
		else
		{
			int pos=upper_bound(a+1,a+i,2ll*a[1])-a;
//			pr("pos1:");
//			pr(pos);
			if(pos==i)
			{
				res+=2ll*(pre[i-1]);
			}
			else if(pos==1)
			{
				res+=4ll*a[1]*((ll)i-1);
			}
			else
			{
				res+=2ll*(pre[pos-1]);
				res+=4ll*a[1]*((ll)i-pos);
			}
//			if(i!=n)
//			{
//				pos=upper_bound(a+1+i,a+1+n,2ll*a[1])-a;
//				if(pos==n+1)
//				{
//					res+=2ll*(pre[n]-pre[i]);
//				}
//				else if(pos==i+1)
//				{
//					res+=4ll*(a[1])*((ll)n-i);
//				}
//				else
//				{
//					res+=2ll*(pre[pos-1]-pre[i]);
//					res+=4ll*a[1]*((ll)n-pos+1);
//				}
////				pr("pos2:");
////				pr(pos);
//			}
			if(2ll*a[1]<=a[i])
			{
				res+=4ll*a[1]*(n-i);
			}
			else
			{
				res+=2ll*a[i]*(n-i);
			}
		}
//		printf("%lld\n",res);
	}
	printf("%lld\n",res);
}
int main ()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	IOS;
	int _=1;
	scanf("%d",&_);
	while(_--)
	{
		solve();
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}