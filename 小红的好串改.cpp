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
int n,q,l,r;
string s;
int f[3][100010];
void solve()
{
	cin>>n>>q;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='r') f[0][i+1]=1;
		else if(s[i]=='e') f[1][i+1]=1;
		else f[2][i+1]=1;
		f[0][i+1]+=f[0][i];
		f[1][i+1]+=f[1][i];
		f[2][i+1]+=f[2][i];
	}
	while(q--)
	{
		cin>>l>>r;
        if(r-l+1<3)
        {
            pr(0);
            continue;
        }
		int minn=0x3f3f3f3f;
		int cnt=(r-l+1)/3;
		if((r-l+1)%3==1)
		{
			int len;
			int pp;
			{
				len=r-l+1;
				pp=f[0][l+cnt]-f[0][l-1];
				len-=pp;
				pp=f[1][l+2*cnt]-f[1][l+cnt];
				len-=pp;
				pp=f[2][l+3*cnt]-f[2][l+2*cnt];
				len-=pp;
				minn=min(minn,len);
			}
			
			{
				len=r-l+1;
				pp=f[0][l+cnt-1]-f[0][l-1];
				len-=pp;
				pp=f[1][l+2*cnt]-f[1][l+cnt-1];
				len-=pp;
				pp=f[2][l+3*cnt]-f[2][l+2*cnt];
				len-=pp;
				minn=min(minn,len);
			}
			
			{
				len=r-l+1;
				pp=f[0][l+cnt-1]-f[0][l-1];
				len-=pp;
				pp=f[1][l+2*cnt-1]-f[1][l+cnt-1];
				len-=pp;
				pp=f[2][l+3*cnt]-f[2][l+2*cnt-1];
				len-=pp;
				minn=min(minn,len);
			}
		}
		else if((r-l+1)%3==2)
		{
			int len;
			int pp;
			{
				len=r-l+1;
				pp=f[0][l+cnt]-f[0][l-1];
				len-=pp;
				pp=f[1][l+2*cnt+1]-f[1][l+cnt];
				len-=pp;
				pp=f[2][l+3*cnt+1]-f[2][l+2*cnt+1];
				len-=pp;
				minn=min(minn,len);
			}
			
			{
				len=r-l+1;
				pp=f[0][l+cnt]-f[0][l-1];
				len-=pp;
				pp=f[1][l+2*cnt]-f[1][l+cnt];
				len-=pp;
				pp=f[2][l+3*cnt+1]-f[2][l+2*cnt];
				len-=pp;
				minn=min(minn,len);
			}
			
			{
				len=r-l+1;
				pp=f[0][l+cnt-1]-f[0][l-1];
				len-=pp;
				pp=f[1][l+2*cnt]-f[1][l+cnt-1];
				len-=pp;
				pp=f[2][l+3*cnt+1]-f[2][l+2*cnt];
				len-=pp;
				minn=min(minn,len);
			}
		}
		else
		{
			int len;
			int pp;
			len=r-l+1;
			pp=f[0][l+cnt-1]-f[0][l-1];
			len-=pp;
			pp=f[1][l+2*cnt-1]-f[1][l+cnt-1];
			len-=pp;
			pp=f[2][l+3*cnt-1]-f[2][l+2*cnt-1];
			len-=pp;
			minn=min(minn,len);
		}
		cout<<minn<<endl;
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