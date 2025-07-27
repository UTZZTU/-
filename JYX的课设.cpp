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

bool Cmp(node x,node y)
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

int n,flag;
string s;
string op,a="Enter",b="Back",c="Forward",curr="-1",last="-1";
stack<string> st1,st2;
void solve()
{
	cin>>n;
	while(n--)
	{
		flag=1;
		cin>>op;
		if(op==a)
		{
			if(curr!="-1")
			{
				st1.push(curr);
			}
			cin>>curr;
		}
		else if(op==b)
		{
			if(st1.empty())
			{
				pr("Error");
				flag=0;
			}
			else
			{
				if(curr!="-1")
				st2.push(curr);
				curr=st1.top();
				st1.pop();
			}
		}
		else
		{
			if(last=="-1")
			{
				pr("Error");
				flag=0;
			}
			else if(last==b)
			{
				if(st2.empty())
				{
					pr("Error");
					flag=0;
				}
				else
				{
					if(curr!="-1")
					st1.push(curr);
					curr=st2.top();
					st2.pop();
				}
			}
			else if(last==a)
			{
				pr("Error");
				flag=0;
			}
		}
		if(flag)
		pr(curr);
		if(op!=c)
		last=op;
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