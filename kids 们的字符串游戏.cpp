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

int n,m,op,p,num,len1,len2;
char s[200010],c1[200010],c2[200010];
char c;
void solve()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	while(m--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			num++;
		}
		else
		{
			scanf("%d %c",&p,&c);
			if(p==1)
			{
				if(num&1)
				{
					c2[++len2]=c;
				}
				else
				{
					c1[++len1]=c;
				}
			}
			else
			{
				if(num&1)
				{
					c1[++len1]=c;
				}
				else
				{
					c2[++len2]=c;
				}
			}
		}
	}
	if(num&1)
	{
		for(int i=len2;i>=1;i--)
		{
			printf("%c",c2[i]);
		}
		for(int i=n-1;i>=0;i--)
		{
			printf("%c",s[i]);
		}
		for(int i=1;i<=len1;i++)
		{
			printf("%c",c1[i]);
		}
	}
	else
	{
		for(int i=len1;i>=1;i--)
		{
			printf("%c",c1[i]);
		}
		for(int i=0;i<n;i++)
		{
			printf("%c",s[i]);
		}
		for(int i=1;i<=len2;i++)
		{
			printf("%c",c2[i]);
		}
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